#
# Makefile.am
#
# Copyright (C) 2007 Alon Bar-Lev <alon.barlev@gmail.com>
#
# This file is released under the GPLv2.
#
AUTOMAKE_OPTIONS=foreign dist-bzip2

SUBDIRS=\
	doc \
	scripts
noinst_LIBRARIES=\
	libsuspend-common.a
sbin_PROGRAMS=\
	s2disk \
	swap-offset
dist_noinst_DATA= \
	conf/suspend.conf
sysconf_DATA=#required in order to create dir
if !ENABLE_MINIMAL
sbin_PROGRAMS+=\
	s2ram \
	s2both
if ENABLE_ENCRYPT
sbin_PROGRAMS+=\
	suspend-keygen
endif
initramfs_PROGRAMS=\
	resume
dist_doc_DATA=\
	TODO \
	README* \
	HOWTO \
	COPYING*
endif

if ENABLE_CREATE_DEVICE
dev_DATA=
install-data-hook:
	$(MKNOD) $(DESTDIR)$(devdir)/snapshot c 10 231
endif

install-data-local:
	if [ -f $(DESTDIR)$(sysconfdir)/suspend.conf ]; then \
		$(INSTALL_DATA) $(srcdir)/conf/suspend.conf $(DESTDIR)$(sysconfdir)/suspend.conf.new; \
	else \
		$(INSTALL_DATA) $(srcdir)/conf/suspend.conf $(DESTDIR)$(sysconfdir)/suspend.conf; \
	fi

AM_CFLAGS=\
	-D_LARGEFILE64_SOURCE \
	-DS2RAM \
	$(LZO_CFLAGS) \
	$(LIBGCRYPT_CFLAGS)

common_s2disk_libs=\
	$(LZO_LIBS) \
	$(LIBGCRYPT_LIBS)
common_s2ram_libs=

if ENABLE_SPLASHY
AM_CFLAGS+=\
	${SPLASHY_CFLAGS}
common_s2disk_libs+=\
	${SPLASHY_LIBS}
endif

libsuspend_common_a_SOURCES=\
	swsusp.h \
	vt.h vt.c \
	config_parser.h config_parser.c \
	md5.h md5.c \
	encrypt.h encrypt.c \
	loglevel.h loglevel.c \
	splash.h splash.c \
	splashy_funcs.h splashy_funcs.c \
	bootsplash.h bootsplash.c \
	whitelist.h whitelist.c \
	s2ram.h s2ram.c

if ARCH_X86
libsuspend_common_a_SOURCES+=\
	s2ram-x86.h s2ram-x86.c \
	dmidecode.c \
	radeontool.c \
	vbetool/vbetool.h vbetool/vbetool.c
AM_CFLAGS+=\
	$(LIBX86_CFLAGS) \
	$(LIBPCI_CFLAGS)
common_s2ram_libs+=\
	$(LIBX86_LIBS) \
	$(LIBPCI_LIBS)
endif
if ARCH_PPC
libsuspend_common_a_SOURCES+=\
	s2ram-ppc.h s2ram-ppc.c
endif

resume_CFLAGS=\
	$(AM_CFLAGS) \
	-D_GNU_SOURCE
resume_SOURCES=\
	resume.c
resume_LDADD=\
	libsuspend-common.a
if ENABLE_RESUME_STATIC
resume_LDADD+=\
	$(common_s2disk_libs)
resume_LDFLAGS=\
	$(AM_LDFLAGS) \
	-all-static
else
resume_LDADD+=\
	$(common_s2disk_libs)
endif

s2disk_SOURCES=\
	suspend.c
s2disk_LDADD=\
	libsuspend-common.a \
	$(common_s2disk_libs)

s2both_SOURCES=\
	suspend.c
s2both_CFLAGS=\
	$(AM_CFLAGS) \
	-DCONFIG_BOTH
s2both_LDADD=\
	libsuspend-common.a \
	$(common_s2ram_libs) \
	$(common_s2disk_libs)

s2ram_SOURCES=\
	s2ram-main.c
s2ram_LDADD=\
	libsuspend-common.a \
	$(common_s2ram_libs)

swap_offset_SOURCES=\
	swap-offset.c

suspend_keygen_SOURCES=\
	keygen.c
suspend_keygen_LDADD=\
	libsuspend-common.a \
	$(LIBGCRYPT_LIBS)

#
# Misc functions
#
install-resume-new-initrd:      resume
	@if test -z "$(RESUME_DEVICE)"; then \
		echo "Please specify --with-resume-device"; \
		false; \
	else \
		BOOT_DIR=$(DESTDIR)$(bootdir) ./scripts/create-resume-initrd.sh $(RESUME_DEVICE); \
	fi

install-resume-on-initrd:       resume
	BOOT_DIR=$(DESTDIR)$(bootdir) ./scripts/install-resume.sh