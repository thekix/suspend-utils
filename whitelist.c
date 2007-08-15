/* whitelist.c
 * whitelist of machines that are known to work somehow
 * and all the workarounds
 */

#include <stdlib.h>
#include "whitelist.h"

struct machine_entry whitelist[] = {
	{ "IBM",			"",		"ThinkPad X32",	"", RADEON_OFF|S3_BIOS|S3_MODE },
	{ "Hewlett Packard",	"",	"HP OmniBook XE3 GF           ","", VBE_POST|VBE_SAVE },
	/* Michael Wagner <michael-wagner@gmx.de> */
	{ "4MBOL&S",			"7521 *"	"REV. A0",	"", 0 },
	/* Alexander Wirt */
	{ "Apple Computer, Inc.",	"MacBook1,1",		"",	"", VBE_SAVE },
	/* Marvin Stark <marv@der-marv.de> */
	{ "Apple Computer, Inc.",	"MacBook2,1",		"",	"", VBE_POST },
	/* Julien BLACHE jb@jblache.org */
	{ "Apple Computer, Inc.",	"MacBookPro2,2",	"",	"", VBE_POST|VBE_MODE },
	/* Felix Rommel, https://bugzilla.novell.com/show_bug.cgi?id=228572 */
	{ "Acer,Inc.",			"Aspire 1350",		"",	"", VBE_POST|VBE_MODE|NOFB },
	{ "Acer, inc.",			"Aspire 1690     ",	"",	"", VBE_POST|VBE_SAVE|NOFB },
	/* Ricardo Garcia <sarbalap+freshmeat@gmail.com> */
	{ "Acer, inc.",			"Aspire 3000 *",	"",	"", VBE_POST|VBE_MODE },
	/* From: Bontemps Camille <camille.bontemps@gmail.com> */
	{ "Acer",			"Aspire 3610",		"",	"", S3_BIOS|S3_MODE },
	/* From: Saul Mena Avila <saul_2110@yahoo.com.mx> */
	{ "Acer",			"Aspire 3620",		"",	"", S3_BIOS|S3_MODE },
	/* From: Witmaster <witmaster@op.pl> */
	{ "Acer            ",		"Aspire 3690 *",	"",	"", S3_BIOS|S3_MODE },
	/* Carlos Corbacho <cathectic@gmail.com> */
	{ "Acer",			"Aspire 5020",		"",	"", VBE_POST },
	/* Paul Kretek <pk@oz4.org> */
	{ "Acer            ",		"Aspire 5500Z *",	"",	"", 0 },
	/* From: "cj.yap" <chuanren.ye@gmail.com> */
	{ "Acer, inc.",			"Aspire 5570 *",	"",	"", VBE_POST|VBE_MODE },
	{ "Acer            ",		"Extensa 4150 *",	"",	"", S3_BIOS|S3_MODE },
	{ "Acer           ",		"TravelMate 240 ",	"",	"", VBE_POST|VBE_SAVE },
	{ "Acer           ",		"TravelMate C300",	"",	"", VBE_SAVE },
	/* TravelMate 630Lci	Tim Dijkstra <tim@famdijkstra.org> */
	{ "Acer           ",		"TravelMate 630 ",	"",	"", S3_BIOS|S3_MODE },
	/* Norbert Preining */
	{ "Acer",			"TravelMate 650",	"",	"", VBE_POST|VBE_SAVE },
	/* Martin Sack, this one may be NOFB, to be verified */
	{ "Acer",			"TravelMate 800",	"",	"", VBE_POST },
	/* Arkadiusz Miskiewicz <arekm@maven.pl> */
	{ "Acer",			"TravelMate 2300",	"",	"", VBE_POST|VBE_MODE },
	/* jan sekal <jsekal@seznam.cz> */
	{ "Acer",			"TravelMate 2410",	"",	"", S3_BIOS|S3_MODE },
	/* Peter Stolz <p.stolz@web.de> */
	{ "Acer",			"TravelMate 2420",	"",	"", S3_BIOS|S3_MODE },
	/* Erki Ferenc <ferki@3rdparty.hu> */
	{ "Acer            ",		"TravelMate 2450 ",	"",	"", 0 },
	{ "Acer, inc.",			"TravelMate 3000 ",	"",	"", VBE_POST|VBE_SAVE },
	{ "Acer            ",		"TravelMate 3220 *",	"",	"", S3_BIOS|S3_MODE },
	/* Rohan Dhruva <rohandhruva@gmail.com> */
	{ "Acer, inc.",			"TravelMate 3260 ",	"",	"", VBE_POST|VBE_MODE },
	/* From: LucaB <lbonco@tin.it> */
	{ "Acer, inc.",			"TravelMate 4100 ",	"",	"", VBE_POST|VBE_SAVE },
	{ "Acer            ",		"TravelMate 4650 *",	"",	"", S3_BIOS|S3_MODE },
	{ "Acer, inc.",			"Ferrari 4000    ",	"",	"", VBE_POST|VBE_SAVE|NOFB },
	/* From: Julien Puydt <jpuydt@free.fr> */
	{ "ASUSTeK Computer Inc.",	"A2D       ",		"",	"", S3_BIOS|S3_MODE },
	/* Cristian Rigamonti */
	{ "ASUSTEK ",			"A2H/L ",		"",	"", 0 },
	/* Patryk Zawadzki <patrys@icenter.pl> */
	{ "ASUSTeK Computer Inc. ",	"A6Km      ",		"",	"", 0 },
	/* Szalai Akos <szalakos@gmail.com> */
	{ "ASUSTeK Computer Inc. ",	"A6M",			"",	"", VBE_POST },
	/* tias@ulyssis.org */
	{ "ASUSTeK Computer Inc. ",	"A6U       ",		"",	"", VBE_POST|VBE_MODE },
	{ "ASUSTEK ",			"L2000D",		"",	"", S3_MODE },
	{ "ASUSTEK ",			"L3000D",		"",	"", VBE_POST|VBE_SAVE },
	/* Guenther Schwarz <guenther.schwarz@gmx.de> */
	{ "ASUSTeK Computer Inc.        ",	"M2N       ",	"",	"", S3_BIOS|S3_MODE },
	/* Peter Suetterlin <P.Suetterlin@astro.uu.nl>, VBE_MODE does not work */
	{ "ASUSTeK Computer Inc.        ",	"M3N       ",	"",	"", VBE_POST|VBE_SAVE },
	/* Manfred Tremmel, https://bugzilla.novell.com/show_bug.cgi?id=171107 */
	{ "ASUSTeK Computer Inc.        ",	"M6N       ",	"",	"", S3_BIOS|S3_MODE },
	{ "ASUSTeK Computer Inc.        ",	"M6Ne      ",	"",	"", S3_MODE },
	/* Charles de Miramon */
	{ "ASUSTeK Computer Inc.        ",	"M5N       ",	"",	"", S3_BIOS|S3_MODE },
	/* M6VA, seraphim@glockenbach.net */
	{ "ASUSTeK Computer Inc.        ",	"M6VA      ",	"",	"", S3_BIOS|S3_MODE },
	/* M7N, Xavier Douville <s2ram-sourceforge@douville.org> */
	{ "ASUSTeK Computer Inc.        ",	"M7A       ",	"",	"", S3_BIOS|S3_MODE },
	/* ASUS S5200N Philip Frei <pjf@gmx.de> */
	{ "ASUSTeK Computer Inc.        ",	"S5N       ",	"",	"", S3_BIOS|S3_MODE },
	/* ASUS V6V, Johannes Engel <j-engel@gmx.de> */
	{ "ASUSTeK Computer INC.",	"V6V",			"",	"", S3_MODE },
	/* Kanru Chen <kanru@csie.us> */
	{ "ASUSTeK Computer INC.",		"W3A",		"",	"", S3_BIOS|S3_MODE },
	/* ASUS W5A, Riccardo Sama' <riccardo.sama@yetopen.it> */
	{ "ASUSTeK Computer Inc.        ",	"W5A       ",	"",	"", S3_BIOS|S3_MODE },
	/* ASUS M2400N, Daniel Gollub */
	{ "ERGOUK                       ",	"M2N       ",	"",	"", S3_BIOS|S3_MODE },
	/* ASUS Mainboard, Christoph Jaeschke <chrjae@arcor.de> */
	{ "ASUSTek Computer Inc.",	"K8N-E-Deluxe",		"",	"", S3_BIOS },
	/* ASUS a7v600 motherboard, has no usable sys_* entries besides bios_version :-(
	   reported by James Spencer */
	{ "",		"",	"",	"ASUS A7V600 ACPI BIOS Revision *", S3_BIOS|S3_MODE },
	/* ASUS M2N-E motherboars, not much usable in DMI :-(
	   reported by Ingo <ingo.steiner@gmx.net> */
	{ "",		"",	"",	"ASUS M2N-E ACPI BIOS Revision *",  0 },
	/* another ASUS Mainboard, reported by mailinglist@prodigy7.de */
	{ "",	"",	"",	"ASUS M2N32-SLI DELUXE ACPI BIOS Revision 1201", VBE_POST|VBE_MODE },
	{ "",	"",	"",	"ASUS M2N32-SLI DELUXE ACPI BIOS Revision 1101", VBE_POST|VBE_MODE },
	/* Mark Stillwell */
	{ "AVERATEC",			"3700 Series",		"",	"", S3_BIOS|S3_MODE },
	/* Ross Patterson <me@rpatterson.net> */
	{ "AVERATEC",			"1000 Series",		"",	"", S3_BIOS|S3_MODE },
	/* Sebastian Maus <sebastian.maus@bluemars.net> */
	{ "BENQ",			"JoyBook 7000",	"GRASSHOPPER2",	"", S3_BIOS|S3_MODE },
	/* Andreas Schmitz */
	{ "BenQ           ",		"Joybook R22",		"",	"", S3_BIOS|S3_MODE },
	/* Gilles Grandou <gilles@grandou.net> */
	{ "CLEVO",			"D500P",		"",	"", VBE_POST|NOFB },
	/* Leszek Kubik <leszek.kubik@googlemail.com> */
	{ "COMPAL          ",		"HEL80I          ",	"",	"", 0 },

	/* This Armada m300, reported by benoit.monin@laposte.net seems not to have a useful
	   model description, so to make sure i also added the bios_version */
	{ "Compaq",			"Armada                                     ",	"",	"1.35", 0 },
	{ "Compaq",			"Armada    E500  *",	"",	"", 0 },
	/* Martin Heimes <martin.heimes@gmx.de> */
	{ "Compaq",			"Evo  D510 USDT",	"",	"", 0 },
	/* Chris AtLee <chris@atlee.ca>, VBE_MODE does not work, text size changes. */
	{ "Compaq ",			"Evo N800w *",		"",	"", VBE_POST|VBE_SAVE },
	{ "Compaq*",			"N620c *",		"",	"", S3_BIOS|S3_MODE },
	/* Struan Bartlett <struan.bartlett@NewsNow.co.uk> */
	{ "Dell Inc.                ",	"Dell DXP051 *",	"",	"", 0 },
	/* From bug 1544913@sf.net, Andrei - amaces */
	{ "Dell Computer Corporation",  "Inspiron 1150*",       "",     "", 0 },
	/* Dell Inspiron 500m, Per Øyvind Karlsen <pkarlsen@mandriva.com> */
	{ "Dell Computer Corporation",	"Inspiron 500m*",	"",	"", S3_BIOS },
	/* Dell Inspiron 510m, Jose Carlos Garcia Sogo <jsogo@debian.org> */
	{ "Dell Inc.",			"Inspiron 510m *",	"",	"", VBE_POST },
	/* Dell Inspiron 600m, Gavrie Philipson <gavrie@gmail.com> */
	{ "Dell Computer Corporation",  "Inspiron 600m *",      "",     "", VBE_POST|VBE_MODE },
	/* Eric Sandall <eric@sandall.us> */
	{ "Dell Computer Corporation",  "Inspiron 5100 *",	"",	"", NOFB },
	/* VBE_POST|VBE_SAVE works on text console, but not under X. Tested by Chirag Rajyaguru */
	{ "Dell Computer Corporation",  "Inspiron 5150*",	"",	"", VBE_SAVE },
	{ "Dell Computer Corporation",  "Inspiron 8000 *",	"",	"", VBE_POST|VBE_SAVE },
	/* by Henare Degan <henare.degan@gmail.com> 8500 w. NVidia card. There are also 8500s w. ATI cards */
	{ "Dell Computer Corporation",  "Inspiron 8500 *",	"",	"", VBE_POST|VBE_SAVE },
	{ "Dell Computer Corporation",  "Latitude C600 *",	"",	"", RADEON_OFF },
	{ "Dell Computer Corporation",  "Latitude C610 *",	"",	"", VBE_POST|VBE_MODE },
	/* Manuel Jander */
	{ "Dell Computer Corporation",	"Latitude CPx J650GT*",	"",	"", 0 },
	/* Luke Myers */
	{ "Dell Computer Corporation",	"Latitude CPx J800GT*",	"",	"", VBE_POST|VBE_MODE },
	/* https://bugzilla.novell.com/show_bug.cgi?id=220865 */
	{ "Dell Inc.",			"Latitude D410 *",	"",	"", VBE_POST|VBE_MODE },
	/* tested by seife */
	{ "Dell Inc.",			"Latitude D420 *",	"",	"", VBE_POST|VBE_MODE },
	/* Roland Hagemann <mail@rolandhagemann.de> */
	{ "Dell Computer Corporation",  "Latitude D500 *",	"",	"", VBE_POST|VBE_SAVE },
	/* Ian Samule, https://bugzilla.novell.com/show_bug.cgi?id=175568 */
	{ "Dell Inc.",			"Latitude D505 *",	"",	"", VBE_POST|VBE_SAVE },
	/* tested by seife */
	{ "Dell Inc.",			"Latitude D520 *",	"",	"", VBE_POST|VBE_MODE },
	{ "Dell Computer Corporation",  "Latitude D600 *",	"",	"", VBE_POST|VBE_SAVE|NOFB },
	{ "Dell Inc.",			"Latitude D610 *",	"",	"", VBE_POST|VBE_SAVE|NOFB },
	/* D620 reported by Miroslav Ruda <ruda@ics.muni.cz>, <nicolae.mihalache@spaceapplications.com> */
	{ "Dell Inc.",			"Latitude D620 *",	"",	"", VBE_POST|VBE_MODE },
	{ "Dell Computer Corporation",	"Latitude D800 *",	"",	"", VBE_POST|VBE_SAVE },
	/* Johannes Engel <j-engel@gmx.de> */
	{ "Dell Inc.",			"Latitude D820 *",	"",	"", VBE_POST|VBE_MODE },
	/* Dell e1505, Alexander Antoniades */
	{ "Dell Inc.",			"MM061 *",		"",	"", 0 },
	/* Dell inspiron 1300, Tim Dijkstra <tim@famdijkstra.org> */
	{ "Dell Inc.",			"ME051 *",		"",	"", 0 },
	/* Dell Inspiron E1702, Julian Krause <suspend@thecrypto.org> */
	{ "Dell Inc.",			"MP061 *",		"",	"", 0 },
	/* Dell Inspiron E1705, Paul Hummel <paulhummel@gmail.com> */
	{ "Dell Inc.",			"MP061",		"",	"", 0 },
	/* Dell Inspiron 630m, Fredrik Edemar */
	{ "Dell Inc.",			"MXC051 *",		"",	"", 0 },
	/* Dell Inspiron 640m, Daniel Drake <dsd@gentoo.org> */
	{ "Dell Inc.",			"MXC061 *",		"",	"", VBE_POST },
	/* Dell XPS M1710 Harry Kuiper <hkuiper@xs4all.nl>, console only resumes with vesafb! */
	{ "Dell Inc.",			"MXG061 *",		"",	"", 0 },
	/* Desktop with Intel graphics, Sitsofe Wheeler <sitsofe@yahoo.com> */
	{ "Dell Inc.                ",	"OptiPlex GX520 *",	"",	"", VBE_POST|VBE_MODE },
	/* Per Øyvind Karlsen <pkarlsen@mandriva.com> VBE_POST will get console working, but break X */
	{ "Dell Computer Corporation",	"Precision M60*",	"",	"", VBE_SAVE },
	/* Michael Witten mfwitten@MIT.EDU */
	{ "Dell Computer Corporation",	"Dimension 2400 *",	"",	"", VBE_POST|VBE_MODE },
	/* Allen <ducalen@sympatico.ca>, Desktop with onboard grephics */
	{ "Dell Computer Corporation",	"Dimension 3000 *",	"",	"", VBE_POST|VBE_MODE },

	/* Michael Dickson <mike@communicatezing.com> */
	{ "ECS",			"536",			"",	"", VBE_POST|NOFB },
	/* Michael Bunk <michael.bunk@gmail.com> */
	{ "Elitegroup Co.",		"ECS G320",		"",	"", VBE_POST|VBE_MODE },

	/* Andi Kleen, reported to work in 64bit mode */
	{ "FUJITSU",			"LifeBook S2110",	"",	"", S3_BIOS },
	/* stan ioan-eugen <stan.ieugen@gmail.com> */
	{ "FUJITSU SIEMENS",		"Amilo A1667G Serie",	"",	"", S3_BIOS },
	/* Those two x86_64 amilos are a bit strange. I seldom see s3_bios + vbe_* ... */
	{ "FUJITSU SIEMENS",		"Amilo A7640 ",		"",	"", VBE_POST|VBE_SAVE|S3_BIOS },
	/* reported by Thomas Halva Labella <hlabella@ulb.ac.be> */
	{ "FUJITSU SIEMENS",		"Amilo A7645 ",		"",	"", VBE_SAVE|S3_BIOS|S3_MODE },
	/* Chris Hammond <christopher.hammond@gmail.com> Amilo A 1630 */
	{ "FUJITSU SIEMENS",		"Amilo A Series",	"0.01",	"", VBE_POST|VBE_SAVE },
	/* Reiner Herrmann <reiner@reiner-h.de>, this one realls needs VBE_SAVE
	   since there are many different models of the "AMILO M" series, i do a very exact match */
	{ "FUJITSU SIEMENS",		"AMILO M        ",	"-1 *",	"R01-S0Z *", VBE_POST|VBE_SAVE },
	/* Markus Meyer <markus.meyer@koeln.de>, Christian Illy <christian.illy@gmx.de> */
	{ "FUJITSU SIEMENS",		"Amilo Si 1520",	"",	"", S3_BIOS|S3_MODE },
	/* Aleksandar Markovic <acojlo@gmail.com> */
	{ "FUJITSU SIEMENS",		"AMILO PRO V2030",	"",	"", VBE_POST|VBE_MODE },
	/* Florian Herrmann <florian-herrmann@gmx.de> */
	{ "FUJITSU SIEMENS",		"AMILO Pro V2040",	"",	"", 0 },
	/* <arild.haugstad@gmx.net> / https://bugzilla.novell.com/show_bug.cgi?id=279944 */
	{ "FUJITSU SIEMENS",		"AMILO Pro V3205",	"",	"", S3_BIOS|S3_MODE },
	/* Alexandr Kara <Alexandr.Kara@seznam.cz> */
	{ "FUJITSU SIEMENS",		"AMILO Pro Edition V3405", "",	"", S3_BIOS|S3_MODE },
	/* Steffen <mlsone@forevers.de> */
	{ "FUJITSU SIEMENS",		"AMILO PRO V8010 *",	"",	"", VBE_POST|VBE_MODE },
	/* <noname1@onlinehome.de> */
	{ "FUJITSU SIEMENS",		"AMILO Xi 1546",	"",	"", S3_BIOS|S3_MODE },
	/* wolfgang.aigner@gmx.de */
	{ "FUJITSU SIEMENS",		"LIFEBOOK E4010",	"",	"", VBE_SAVE },
	/* <jan.lockenvitz.ext@siemens.com>, tested with X only */
	{ "FUJITSU SIEMENS",		"LIFEBOOK S7010",	"",	"", 0 },
	/* Eckhart Woerner <ew@ewsoftware.de> */
	{ "FUJITSU SIEMENS",		"LIFEBOOK T4010",	"",	"", S3_BIOS|S3_MODE },
	/* Jay <jay@jay.cz> */
	{ "FUJITSU SIEMENS",		"LIFEBOOK T4210",	"",	"", S3_BIOS|S3_MODE|PCI_SAVE },
	/* Tomas Pospisek <tpo@sourcepole.ch> */
	{ "Fujitsu Siemens",		"P6VAP-AP",		"",	"", 0 },
	{ "FUJITSU SIEMENS",		"Stylistic ST5000",	"",	"", S3_BIOS|S3_MODE },
	/* Ulf Lange <mopp@gmx.net> */
	{ "FUJITSU SIEMENS",		"SCENIC N300/N600",	"",	"", VBE_POST|VBE_MODE },
	/* This is a desktop with onboard i810 video <seife@suse.de> */
	{ "FUJITSU SIEMENS",		"SCENIC W300/W600",	"",	"", VBE_POST|VBE_MODE },
	/* Peer Heinlein <p.heinlein@jpberlin.de> */
	{ "FUJITSU SIEMENS",		"SCENIC W",		"",	"", VBE_POST|VBE_MODE },

	/* Christoph Wiesmeyr <christoph.wiesmeyr@liwest.at> */
	{ "GERICOM",			"259IA1",		"",	"", 0 },
	/* booiiing@gmail.com */
	{ "Gericom",			"HUMMER",	"",	"1.03   ",  VBE_POST|VBE_MODE },
	/* From: Einon <einon@animehq.hu>, seems to work only from X :-( */
	{ "Gericom",			"Montara-GML ",	"FAB-2",	"", 0 },
	/* S.Çağlar Onur <caglar@pardus.org.tr>, only works from X */
	{ "MTC",			"Montara-GML ",	"FAB-2",	"", 0 },
	/* Josef Zenisek <jzenisek@gmx.de> */
	{ "Gigabyte Technology Co., Ltd.",	"945GZM-S2",	"",	"", 0 },

	/* Robert Hart <Robert.Hart@BuroHappold.com> */
	{ "Hewlett-Packard",	"HP Pavilion dv2500 Notebook PC", "",	"", 0 },
	/* Marcos Pinto <markybob@gmail.com>, HP dv6000 */
	{ "Hewlett-Packard",		"EW434AVABA *",		"",	"", S3_BIOS|S3_MODE },
	/* hp compaq nc2400, tested by seife. sometimes has keyboard problems after resume */
	{ "Hewlett-Packard",		"HP Compaq nc2400*",	"",	"68YOP*", VBE_POST|VBE_MODE },
	/* Rene Seindal <rene@seindal.dk> */
	{ "Hewlett-Packard",		"HP Compaq nc4400*",	"F.08",	"68YHV*", VBE_POST|VBE_SAVE },
	/* Antti Laine <antti.a.laine@tut.fi>, "did not work with older BIOS", now has F.09 */
	{ "Hewlett-Packard",		"HP Compaq nc4400*",	"",	"68YHV*", VBE_POST|VBE_MODE },
	{ "Hewlett-Packard*",		"Compaq nx5000 *",	"",	"68BCU*", VBE_POST|VBE_MODE },
	{ "Hewlett-Packard*",		"hp compaq nx5000 *",	"",	"68BCU*", VBE_POST|VBE_MODE },
	/* Ed Hoo <whoishoo@gmail.com> */
	{ "Hewlett-Packard*",		"hp Compaq nx5000 *",	"",	"68BCU*", VBE_POST|VBE_MODE },
	/* there seem to be versions with a " " after Hewlett-Packard and without. */
	{ "Hewlett-Packard*",		"HP Compaq nc6000 *",	"",	"68BDD*", S3_BIOS|S3_MODE },
	/* Jan Adlen <janne@rosehip.mine.nu> */
	{ "Hewlett-Packard",		"Compaq nc6000 *",	"",	"68BDD*", S3_BIOS|S3_MODE },
	/* Winfried Dobbe, https://bugzilla.novell.com/show_bug.cgi?id=159688 */
	{ "Hewlett-Packard",		"HP Compaq nc6120 *",	"",	"", VBE_POST|VBE_MODE },
	/* Niv aharonovich <niv.kaha@gmail.com> */
	{ "Hewlett-Packard",		"HP Compaq nx6120 *",	"",	"68DTD*", VBE_POST|VBE_MODE },
	{ "Hewlett-Packard",		"HP Compaq nx6125 *",	"",	"", VBE_SAVE|NOFB },
	{ "Hewlett-Packard",		"HP Compaq nc6230 *",	"",	"", VBE_SAVE|NOFB },
	/* Michal Vyskocil <michal.vyskocil@gmail.com> */
	{ "Hewlett-Packard",		"HP Compaq nx6310 *",	"",	"68YDU*", VBE_POST },
	/* Benedikt Nimmervoll <nimmervoll.benedikt@googlemail.com> */
	{ "Hewlett-Packard",		"HP Compaq nx6325 *",	"",	"68TT2*", VBE_POST|VBE_SAVE },
	/* Michael Biebl <biebl@teco.edu> */
	{ "Hewlett-Packard ",		"HP compaq nx7000 *",	"",	"", VBE_POST|VBE_SAVE },
	/* François Münch <francois.munch@free.fr> */
	{ "Hewlett-Packard ",		"Compaq nx 7010 (PG588EA#*","",	"", S3_BIOS },
	/* Valent Turkovic <valent.turkovic@gmail.com> */
	{ "Hewlett-Packard",		"HP Compaq nx7300 (RU374ES#*",	"",	"", VBE_POST|VBE_MODE },
	/* Slawomir Skrzyniarz <diodak@gmail.com> */
	{ "Hewlett-Packard",		"HP Compaq nx7400 (RH412EA#)",	"",	"", VBE_POST|VBE_MODE },
	/* Michael Meskes <meskes@debian.org>, this is a NX 7400 */
	{ "Hewlett-Packard",		"",			"",	"68YGU*", VBE_POST },
	{ "Hewlett-Packard",		"HP Compaq nx8220 *",	"",	"", VBE_SAVE|NOFB },
	/* Stefan Seyfried <seife@suse.de> novell bug 259831 */
	{ "Hewlett-Packard",	"HP Compaq nw8440 (EY696AA*",	"",	"68YVD*", VBE_POST|VBE_MODE },
	/* Matto Marjanovic <maddog@mir.com> */
	{ "Hewlett-Packard",		"Presario C500 (RZ341UA#*",	"",	"", 0 },
	/* Fatih Alabas https://bugzilla.novell.com/show_bug.cgi?id=230528 */
	{ "Hewlett-Packard",		"Presario M2000 (EQ547PA#*",	"",	"", S3_BIOS|VBE_MODE },
	/* Sitsofe Wheeler <sitsofe@yahoo.com> */
	{ "Hewlett-Packard ",		"Presario R3000 *",	"",	"", S3_BIOS|S3_MODE },
	/* Arthur Peters <amp@singingwizard.org> */
	{ "Hewlett-Packard",		"Presario R3200 *",	"",	"", VBE_POST|VBE_SAVE },
	{ "Hewlett-Packard",		"Presario R4100 *",	"",	"", S3_BIOS|S3_MODE },
	/* iamnoah@gmail.com */
	{ "Hewlett-Packard",		"Presario V2000 (EP381UA#*","",	"", S3_BIOS },
	/* From: "Lim Chuen Ee, Mike" <chuenee@starhub.net.sg> */
	{ "Hewlett-Packard",		"Presario V3000 (RL377PA#*","",	"", S3_BIOS|S3_MODE },
	/* "Zirkel, Timothy K" <zirkelt@lafayette.edu> */
	{ "Hewlett-Packard ",		"Compaq Presario X1000 (DK454AV)*",	"",	"", S3_BIOS },
	/* S.Çağlar Onur <caglar@pardus.org.tr>, works only from X! */
	{ "Hewlett-Packard",	"HP Pavilion dv2000 (GF759EA#*", "",	"", 0 },
	/* Fabio Comolli <fabio.comolli@gmail.com>, dv4378ea, ATI X700 */
	{ "Hewlett-Packard",	"Pavilion dv4000 (ES973EA#*",	"",	"", VBE_POST|VBE_SAVE|NOFB },
	/* Damien Raude-Morvan <drazzib@drazzib.com>, This is a dv4052ea, i915GM */
	{ "Hewlett-Packard",	"Pavilion dv4000 (EB911EA#*",	"",	"", S3_BIOS },
	/* Arun Gupta <axgupta1@gmail.com> */
	{ "Hewlett-Packard",	"Pavilion dv6000 (EY798AV#*",	"",	"", 0 },
	/* Antony Dovgal <tony2001@phpclub.net> */
	{ "Hewlett-Packard",	"HP Pavilion dv6000 (RM469EA#*","",	"", 0 },
	/* John Soros <sorosj@gmail.com> "HP dv6120ea" */
	{ "Hewlett-Packard",	"HP Pavilion dv6000 (RP980EA#*","",	"", 0 },
	/* Chris Polderman <chris.polderman@gmail.com> */
	{ "Hewlett-Packard",	"HP Pavilion ze2000 (EK791EA#*","",	"", 0 },
	/* Frank Schröder <frank.schroeder@gmail.com>, zt3380us */
	{ "Hewlett-Packard ",	"Pavilion zt3300 (PF083UA#*",	"",	"", 0 },
	/* Karthik <molecularbiophysics@gmail.com> */
	{ "Hewlett-Packard ",		"Pavilion zt3300 *",	"",	"68BAL*", S3_BIOS },
	/* A desktop with integrated graphics, Bo Thysell <thysell@fusemail.com> */
	{ "HP Pavilion 061",		"EJ192AA-ABS t3250.se",	"",	"", 0 },

	/* R51 confirmed by Christian Zoz and Sitsofe Wheeler <sitsofe@yahoo.com> */
	{ "IBM",			"",		"ThinkPad R51",	"", 0 },
	/* R52, reported by Joscha Arenz */
	{ "IBM",			"1860*",		"",	"", S3_BIOS|S3_MODE },
	/* R51e, reported by nemec.jiri@gmail.com */
	{ "IBM",			"",	"ThinkPad R51e",	"", S3_BIOS|S3_MODE },
	/* T30 */
	{ "IBM",			"2366*",		"",	"", RADEON_OFF },
	/* Thinkpad 600e, George Tellalov <gtellalov@emporikilife.gr>, needs X running */
	{ "IBM",			"2645*",		"",	"", VBE_POST|VBE_MODE },
	/* X22, confirmed by Richard Neill */
	{ "IBM",			"2662*",		"",	"", S3_BIOS|S3_MODE|RADEON_OFF },
	/* X31, confirmed by Bjoern Jacke */
	{ "IBM",			"2672*",		"",	"", S3_BIOS|S3_MODE|RADEON_OFF },
	/* X40 confirmed by Christian Deckelmann */
	{ "IBM",			"2371*",	"ThinkPad X40",	"", S3_BIOS|S3_MODE },
	/* X40, Andrew Pimlott <andrew@pimlott.net> */
	{ "IBM",			"2386*",		"",	"", S3_BIOS|S3_MODE },
	/* X41 Tablet, tested by Danny Kukawka */
	{ "IBM",			"",	"ThinkPad X41 Tablet",	"", S3_BIOS|S3_MODE },
	/* T42p confirmed by Joe Shaw, T41p by Christoph Thiel (both 2373) */
	{ "IBM",			"2373*",		"",	"", S3_BIOS|S3_MODE },
	/* T41p, Stefan Gerber */
	{ "IBM",			"2374*",		"",	"", S3_BIOS|S3_MODE },
	/* Some T43's reported by Sebastian Nagel */
	{ "IBM",			"",		"ThinkPad T43",	"", S3_BIOS|S3_MODE },
	/* T43p reported by Magnus Boman */
	{ "IBM",			"",	"ThinkPad T43p",	"", S3_BIOS|S3_MODE },
	/* G40 confirmed by David Härdeman */
	{ "IBM",			"2388*",		"",	"", 0 },
	/* R32 */
	{ "IBM",			"2658*",		"",	"", 0 },
	/* R40 */
	{ "IBM",			"2681*",		"",	"", 0 },
	{ "IBM",			"2722*",		"",	"", 0 },
	/* Z60m, reported by Arkadiusz Miskiewicz */
	{ "IBM",			"2529*",		"",	"", S3_BIOS|S3_MODE },
	/* A21m, Raymund Will */
	{ "IBM",			"2628*",		"",	"", 0 },
	/* A21p, Holger Sickenberg */
	{ "IBM",			"2629*",		"",	"", 0 },
	/* A31p, Till D"orges <td@pre-secure.de> */
	{ "IBM",			"2653*",		"",	"", RADEON_OFF },
	/* X41, Florian Ragwitz <rafl@debian.org>, */
	{ "IBM",			"2525*",		"",	"", S3_BIOS|S3_MODE },
	/* X60 / X60s */
	{ "LENOVO",			"1702*",		"",	"", S3_BIOS|S3_MODE },
	{ "LENOVO",			"1704*",		"",	"", S3_BIOS|S3_MODE },
	{ "LENOVO",			"1706*",		"",	"", S3_BIOS|S3_MODE },
	/* https://bugzilla.novell.com/show_bug.cgi?id=210928, Thinkpad R60, 32bit? */
	{ "LENOVO",			"9456*",		"",	"", S3_BIOS|S3_MODE },
	/* Marcus Better <marcus@better.se>, this time with a capital "P" */
	{ "LENOVO",			"",		"ThinkPad R60",	"", S3_BIOS|S3_MODE },
	/* From: gregor herrmann <gregor.herrmann@comodo.priv.at> */
	{ "LENOVO",			"",		"Thinkpad R60e", "", S3_BIOS|S3_MODE },
	/* Dave Royal <dave@daveroyal.com>, R60e 32bit works with S3_MODE, 64bit needs VBE_MODE */
	{ "LENOVO",			"0657*",		"",	"", S3_BIOS|VBE_MODE },
	/* At least 1709 series thinkpads can be whitelisted by name,
	   and we can probably delete entries above, too.... */
	{ "LENOVO",			"",		"ThinkPad X60",	"", S3_BIOS|S3_MODE },
	/* T60p, had a report from a 2007* and a 2008* model */
	{ "LENOVO",			"",	"ThinkPad T60p",	"", S3_BIOS|S3_MODE },
	/* T60 From: Jeff Nichols <jnichols@renkoo.net> and Kristofer Hallgren <kristofer.hallgren@gmail.com> */
	{ "LENOVO",			"",	"ThinkPad T60",		"", S3_BIOS|S3_MODE },
	/* T61, Joe Nahmias <jello@debian.org>, debian bug #432018 */
	{ "LENOVO",			"7658*",	"",		"", S3_BIOS|S3_MODE },
	/* T61 with NVidia card, https://bugzilla.novell.com/show_bug.cgi?id=290618 */
	{ "LENOVO",			"7663*",	"",		"", S3_MODE },
	/* X61s, Hendrik-Jan Heins <hjh@passys.nl>. Probably does not restore the
	   framebuffer mode correctly, but S3_MODE as well as VBE_MODE seem to fail
	   sometimes on x86_64 on this machine :-( */
	{ "LENOVO",			"7669*",	"",		"", S3_BIOS },
	/* T61, intel card <seife@suse.de> 32bit works with S3_MODE, but 64bit needs VBE_MODE */
	{ "LENOVO",			"8895*",	"",		"", S3_BIOS|VBE_MODE },
	/* Paul Wilkinson <pwilko@gmail.com> */
	{ "LENOVO",			"",	"ThinkPad Z61p",	"", S3_BIOS|S3_MODE },
	/* Z61m From: Roderick Schertler <roderick@argon.org> */
	{ "LENOVO",			"",	"ThinkPad Z61m",	"", S3_BIOS|S3_MODE },
	
	/* LENOVO non-Thinkpads go here... */
	/* these Lenovo 3000 N100 model 768 are available with different graphics chips, so
	   i do not dare to wildcard anything here :-( */
	/* Aviv Ben-Yosef <aviv.by@gmail.com> */
	{ "LENOVO",			"07686VG",	"3000 N100 *",	"", 0 },
	/* Bogdan <boogi77@o2.pl> */
	{ "LENOVO",			"076831G",	"3000 N100 *",	"", 0 },
	/* Tim Creech <dezgotspam@gmail.com> */
	{ "LENOVO",			"076835U",	"3000 N100 *",	"", 0 },
	/* Ted Percival <ted@midg3t.net> */
	{ "LENOVO",			"07687MM",	"3000 N100 *",	"", S3_MODE },

	{ "LG Electronics",		"M1-3DGBG",		"",	"", S3_BIOS|S3_MODE },
	{ "Matsushita Electric Industrial Co.,Ltd.", "CF-51E*",	"",	"", VBE_POST|VBE_MODE },
	/* Hanspeter Kunz <buzz.rexx@gmail.com> */
	{ "Matsushita Electric Industrial Co.,Ltd.", "CF-R3E*",	"002",	"", VBE_POST|VBE_MODE },
	/* https://sourceforge.net/tracker/index.php?func=detail&aid=1601715&group_id=45483&atid=443088 */
	{ "Matsushita Electric Industrial Co.,Ltd.", "CF-R2C*",	"0032",	"", VBE_POST|VBE_MODE },
	/* Joost Witteveen <joost@iliana.nl> */
	{ "MAXDATA",			"IMPERIO4045A *",	"",	"", 0 },
	/* Jan Gerrit <JanGerrit@Burg-Borgholz.de> */
	{ "MAXDATA",			"PRO600IW",		"",	"", S3_BIOS|S3_MODE },
	/* Gergely Csepany <cheoppy@gmail.com> */
	{ "MICRO-STAR INT'L CO.,LTD.",	"MS-1057",		"",	"", S3_BIOS|S3_MODE },
	/* Baruch Even <baruch@ev-en.org> */
	{ "Micro-Star International",	"MS-1412",		"",	"", VBE_POST|VBE_SAVE|NOFB },
	/* uswsusp@faxm0dem.org */
	{ "MSI.",			"MS-7207PV",		"",	"", 0 },
	/* "Alex V. Myltsev" <avm@altlinux.ru */
	{ "NCA_GROUP_LTD",		"iRU_Notebook",		"0106",	"", VBE_POST|VBE_MODE },
	/* Hugo Costelha */
	{ "NEC *",			"B7 *",			"",	"", VBE_SAVE }, 
	/* Benoit Thiell <badzil@gmail.com> */
	{ "NEC COMPUTERS INTERNATIONAL","NEC Versa Premium",	"FAB-2","", 0 },
	/* Per Waago <waago@stud.ntnu.no> */
	{ "Packard Bell NEC",	"00000000000000000000000", "P820008416","", 0 },
	/* Pavol Otcenas <Pavol.Otcenas@2c.cz>, "Prestigio Nobile 159W" */
	{ "To Be Filled By O.E.M.", "259IA1", "To Be Filled By O.E.M.", "080010 ", S3_MODE },
	/* Jeremie Delaitre <jeremie.delaitre@gmail.com> */
	{ "SAMSUNG ELECTRONICS CO., LTD.",	"Q35/Q36",	"",	"", S3_BIOS|S3_MODE },
	/* Eduardo Robles Elvira <edulix@gmail.com> */
	{ "SAMSUNG ELECTRONICS CO., LTD.",	"R40/R41",	"",	"", VBE_SAVE },
	/* Daniel Koester <koester@math.uni-augsburg.de> does not yet work from text mode */
	{ "SAMSUNG ELECTRONICS CO., LTD.",	"R55S *",	"",	"", 0 },
	/* Stephen Denham <stephen.denham@gmail.com> */
	{ "SAMSUNG Electronics",	"SENS V25",		"",	"", VBE_POST|VBE_MODE },

	{ "TOSHIBA",			"Libretto L5/TNK",	"",	"", 0 },
	{ "TOSHIBA",			"Libretto L5/TNKW",	"",	"", 0 },
	/* this is a Toshiba Satellite 4080XCDT, believe it or not :-( */
	{ "TOSHIBA",		"Portable PC",	"Version 1.0",	"Version 7.80", S3_MODE },
	/* Alan Mycroft <Alan.Mycroft@cl.cam.ac.uk> */
	{ "TOSHIBA",			"PORTEGE M300",		"",	"", S3_MODE },
	/* Mathieu Lacage <mathieu.lacage@sophia.inria.fr> */
	{ "TOSHIBA",			"PORTEGE R100",		"",	"", 0 },
	{ "TOSHIBA",			"Satellite A30",	"",	"", VBE_SAVE },
	/* Diego Ocampo <diegoocampo8@gmail.com> */
	{ "TOSHIBA",			"Satellite A80",	"",	"", 0 },
	/* From: a.maurizi@isac.cnr.it */
	{ "TOSHIBA",			"Satellite A100",	"",	"", S3_BIOS|S3_MODE },
	/* Christian Schneeman <cschneemann@suse.de> */
	{ "TOSHIBA",			"Satellite L10",	"",	"", VBE_POST|VBE_MODE },
	/* tnt.rocket@freenet.de, need to verify if S3_MODE is needed too */
	{ "TOSHIBA",			"Satellite M30X",	"",	"", S3_BIOS },
	/* Michaell Gurski */
	{ "TOSHIBA",			"Satellite M35X",	"",	"", S3_BIOS|S3_MODE },
	/* Antonis Tsolomitis <atsol@aegean.gr> */
	{ "TOSHIBA",			"Satellite P10",	"",	"", S3_BIOS|NOFB },
	/* From: mire <mire@osadmin.com> */
	{ "TOSHIBA",			"Satellite P200",	"",	"", S3_BIOS|S3_MODE },
	/* From: Jim <jim.t@vertigo.net.au> */
	{ "TOSHIBA",			"SatellitePro4600",	"",	"", 0 },
	/* Bram Senders <bram@luon.net> */
	{ "TOSHIBA",			"SP4600",	"Version 1.0",	"", 0 },
	{ "TOSHIBA",			"TECRA S3",		"",	"", 0 },
	/* From: a v <adam_6515@hotmail.com> */
	{ "TOSHIBA",			"TECRA8100",		"",	"", S3_MODE },
	/* Stefan Seyfried has one of those :-) S3_BIOS leads to "melting screen" */
	{ "TOSHIBA",			"TECRA 8200",		"",	"", S3_MODE },
	{ "Samsung",			"SQ10",			"",	"", VBE_POST|VBE_SAVE },
	/* https://bugzilla.novell.com/show_bug.cgi?id=290734 */
	{ "Samsung Electronics",	"SX20S",		"",	"", VBE_POST|VBE_MODE },
	{ "SHARP                           ",	"PC-AR10 *",	"",	"", 0 },
	/* Dhananjaya Rao <phaze87@gmail.com> */
	{ "Sony Corporation",		"VGN-B55G(I)"		"",	"", 0 },
	/* Jorge Visca <xxopxe@gmail.com> */
	{ "Sony Corporation",		"VGN-C140G",		"",	"", S3_BIOS|S3_MODE },
	{ "Sony Corporation",		"VGN-FS115B",		"",	"", S3_BIOS|S3_MODE },
	/* Olivier Saier <osaier@gmail.com>, apparently S3_BIOS locks the machine hard */
	{ "Sony Corporation",		"VGN-FS115Z",		"",	"", S3_MODE },
	/* S.Çağlar Onur <caglar@pardus.org.tr> */
	{ "Sony Corporation",		"VGN-FS215B",	"",	"", 0 },
	/* Joseph Smith <joe@uwcreations.com> */
	{ "Sony Corporation",		"VGN-FS660_W",		"",	"", 0 },
	/* Stephan Martin <stephan.martin@open-xchange.com> */
	{ "Sony Corporation",		"VGN-TX3XP_L",		"",	"", S3_BIOS|S3_MODE },
	/* Mattia Dongili <malattia@linux.it> */
	{ "Sony Corporation",		"VGN-UX50",		"",	"", VBE_MODE },
	/* Sitsofe Wheeler <sitsofe@yahoo.com> */
	{ "Sony Corporation",		"PCG-FX405*",		"",	"", S3_BIOS },
	/* Stefan Nobis <stefan@snobis.de> */
	{ "Sony Corporation",		"PCG-FX601*",		"",	"", S3_BIOS|S3_MODE },
	/* Marco Nenciarini <mnencia@prato.linux.it> */
	{ "Sony Corporation",		"PCG-GRT916Z*",		"",	"", 0 },
	{ "Sony Corporation",		"PCG-GRT995MP*",	"",	"", 0 },
	/* Mattia Dongili <malattia@linux.it> */
	{ "Sony Corporation    ",	"PCG-GR7_K(J)        ",	"",	"", 0 },
	/* Bruce Perens <bruce@perens.com> */
	{ "Sony Corporation",		"PCG-TR2A(UC)",		"",	"", VBE_MODE },

	/* Gregory Colpart <reg@evolix.fr> 'Transtec Levio 210' */
	{ "transtec AG",		"MS-1057",		"",	"", S3_BIOS|S3_MODE },
	/* Joachim Gleissner */
	{ "transtec AG",		"MS-1034",		"",	"", S3_BIOS|S3_MODE },

	/* Clevo D470K, Jasper Mackenzie <scarletpimpernal@hotmail.com> */
	{ "VIA",			"K8T400",	"VT8204B ",	"", S3_BIOS|S3_MODE },
	/* VIA EPIA M Mini-ITX Motherboard with onboard gfx, reported by Monica Schilling */
	{ "VIA Technologies, Inc.",	"VT8623-8235",		"",	"", S3_MODE },

	// entries below are imported from acpi-support 0.59 and though "half known".
	{ "ASUSTeK Computer Inc.",	"L7000G series Notebook PC*", "","", VBE_POST|VBE_SAVE|UNSURE },
	{ "ASUSTeK Computer Inc.",	"W5A*",			"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Acer",			"TravelMate 290*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Acer",			"TravelMate 660*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Acer",			"Aspire 2000*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Acer, inc.",			"TravelMate 8100*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 700m*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 1200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 6000*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 8100*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 8200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 8600*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 9300*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude 110L*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D510*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D810*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude X1*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude X300*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Precision M20*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 700m*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 1200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 6000*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 8100*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 8200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 8600*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 9300*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude 110L*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D410*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D510*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D810*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude X1*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude X300*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Precision M20*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "ECS",			"G556 Centrino*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU",			"Amilo M*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU",			"LifeBook S Series*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU",			"LIFEBOOK S6120*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU",			"LIFEBOOK P7010*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"Amilo M*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"LifeBook S Series*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"LIFEBOOK S6120*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"LIFEBOOK P7010*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc4200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nx6110*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc6220*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc8230*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Pavilion dv1000*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Pavilion zt3000*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Tablet PC Tx1100*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Tablet PC TR1105*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"Pavilion zd7000*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// R40
	{ "IBM",			"2682*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2683*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2692*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2693*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2696*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2698*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2699*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2723*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2724*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2897*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// R50/p
	{ "IBM",			"1830*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1831*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1832*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1833*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1836*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1840*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1841*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	/* R50e needs not yet implemented save_video_pci_state :-(
	{ "IBM",			"1834*",		"",	"", UNSURE },
	{ "IBM",			"1842*",		"",	"", UNSURE },
	{ "IBM",			"2670*",		"",	"", UNSURE },
	*/
	// R52
	{ "IBM",			"1846*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1847*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1848*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1849*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1850*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1870*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// T21
	{ "IBM",			"2647*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2648*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// T23
	{ "IBM",			"475S*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// T40/T41/T42/p
	{ "IBM",			"2375*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2376*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2378*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2379*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// T43
	{ "IBM",			"1871*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1872*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1873*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1874*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1875*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1876*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// X30
	{ "IBM",			"2673*",		"",	"", VBE_POST|VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2884*",		"",	"", VBE_POST|VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2885*",		"",	"", VBE_POST|VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2890*",		"",	"", VBE_POST|VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2891*",		"",	"", VBE_POST|VBE_SAVE|UNSURE|RADEON_OFF },
	// X40
	{ "IBM",			"2369*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2370*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2372*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2382*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	// X41
	{ "IBM",			"1864*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"1865*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2526*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2527*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "IBM",			"2528*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },

	{ "Samsung Electronics",	"NX05S*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "SHARP Corporation",		"PC-MM20 Series*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "Sony Corporation",		"PCG-U101*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },

	{ "TOSHIBA",			"libretto U100*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"P4000*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE A100*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE A200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE M200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE R200*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"Satellite 1900*",	"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"TECRA A2*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"TECRA A5*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"TECRA M2*",		"",	"", VBE_POST|VBE_SAVE|UNSURE },
	{ NULL, NULL, NULL, NULL, 0 }
};
