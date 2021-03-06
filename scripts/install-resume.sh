#!/bin/sh

if [ -z "$RESUME" ]; then
	RESUME="resume"
fi
if [ -z "$BOOT_DIR" ]; then
	BOOT_DIR="/boot"
fi
if [ -z "$INITRD_FILE" ]; then
	INITRD_FILE="$BOOT_DIR/resume-initrd"
fi
if [ -z "$MOUNT_POINT" ]; then
	MOUNT_POINT="/mnt"
fi

if [ -f "$RESUME" -a -f "$INITRD_FILE" -a -d "$MOUNT_POINT" ]; then
	cp "$INITRD_FILE" "$INITRD_FILE.orig"
	mount -t ext2 -o loop "$INITRD_FILE" "$MOUNT_POINT" && \
		install --mode=0755 "$RESUME" "$MOUNT_POINT"

	umount "$MOUNT_POINT"
else
	echo "Could not install the resume tool" >&2
	exit 1
fi

