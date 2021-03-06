/*
 * config_parser.c
 *
 * Configuration file parser for userland suspend tools
 *
 * Copyright (C) 2006 Rafael J. Wysocki <rjw@sisk.pl>
 *
 * This file is released under the GPLv2.
 *
 */

#include "config.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

#include "config_parser.h"
#include "encrypt.h"

int parse_line(char *str, struct config_par *parv)
{
	char *fmt, *end;
	int error = 0;
	int i, k;

	/* Skip white space */
	while (isspace(*str))
		str++;
	/* Skip the lines containing white space only */
	if (!*str)
		goto cleanup;
	/* Ignore comments */
	if (*str == '#')
		goto cleanup;

	/* Compare with parameter names */
	for (i=0; parv[i].name; i++) {
		k = strlen(parv[i].name);
		if (!strncmp(parv[i].name, str, k)) {
			if (!parv[i].ptr)
				break;
			str += k;
			while (isblank(*str))
				str++;
			if (*str != ':' && *str != '=') {
				error = -EINVAL;
				break;
			}
			str++;
			while (isblank(*str))
				str++;
			end = str + strlen(str);
			while (end > str && isspace(*--end))
				*end = '\0';
			if (*str) {
				fmt = parv[i].fmt;
				if (!strncmp(fmt, "%s", 2))
					strncpy(parv[i].ptr, str,
						parv[i].len - 1);
				else {
					if (sscanf(str, fmt, parv[i].ptr) <= 0)
						error = -EINVAL;
				}
				break;
			}
		}
	}

cleanup:
	return error;
}

/**
 *	parse - read and parse the configuration file
 */

int parse(char *my_name, char *file_name, struct config_par *parv)
{
	char buf[MAX_STR_LEN];
	char *str;
	FILE *file;
	int error, i;

	file = fopen(file_name, "r");
	if (!file) {
		fprintf(stderr, "%s: Could not open configuration file\n",
			my_name);
		return -errno;
	}
	error = 0;
	i = 0;
	do {
		str = fgets(buf, MAX_STR_LEN, file);
		if (!str)
			break;
		i++;
		error = parse_line(str, parv);
	} while (!error);
	fclose(file);
	if (error)
		fprintf(stderr, "%s: Error in configuration file, line %d\n",
			my_name, i);
	return error;
}

/* We're abusing struct option a bit. usage() expects an \0 in the
 * name string, and after that a comment.
 */
void usage(char *my_name, struct option *options, const char *short_options)
{
	struct option *opt;

	printf("Usage: %s [options]", my_name);
	for (opt = options; opt->name; opt++)
	{
		const char *descr = opt->name + strlen(opt->name) + 1;
		if (strchr(short_options,opt->val))
			printf("\n  -%c, --%s", opt->val, opt->name);
		else
			printf("\n  --%s", opt->name);

		if (opt->has_arg)
			printf(" <%s>", opt->name);

		if (strlen(descr))
			printf("\t%s",descr);
	}

	printf("\n");
}

void version(char *my_name, char *extra_version)
{
	printf(
		(
			"%s (%s) %s %s\n"
			"\n"
			"FEATURES: %s\n"
			"\n"
			"This is free software.  You may redistribute copies of it under the terms of\n"
			"the GNU General Public License <http://www.gnu.org/licenses/gpl.html>.\n"
			"There is NO WARRANTY, to the extent permitted by law.\n"
		),
		my_name,
		PACKAGE_NAME,
		PACKAGE_VERSION,
		extra_version ? extra_version : "",
		CONFIG_FEATURES
	);
}

