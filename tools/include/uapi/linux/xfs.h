/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_LINUX_XFS_H
#define _UAPI_LINUX_XFS_H

#include <linux/types.h>

#define FMODE_RANDOM	(0x1000)
#define FMODE_WILLNEED	(0x40000000)

struct xfs_writable_file {
	const unsigned char *name;
	unsigned int f_mode; /* can be set into file->f_mode */
	long long i_size; /* file size */
	long long prev_pos; /* ra->prev_pos */
};

#endif /* _UAPI_LINUX_XFS_H */
