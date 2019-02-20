// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _OE_UNISTD_H
#define _OE_UNISTD_H

#include <openenclave/bits/defs.h>
#include <openenclave/bits/types.h>

OE_EXTERNC_BEGIN

#define OE_STDIN_FILENO 0
#define OE_STDOUT_FILENO 1
#define OE_STDERR_FILENO 2

/* access() mode flags. */
#define OE_F_OK 0
#define OE_R_OK 4
#define OE_W_OK 2
#define OE_X_OK 1

/* lseek() whence parameters. */
#define OE_SEEK_SET 0
#define OE_SEEK_CUR 1
#define OE_SEEK_END 2

int oe_access(uint64_t devid, const char* pathname, int mode);

void* oe_sbrk(intptr_t increment);

ssize_t oe_read(int fd, void* buf, size_t count);

ssize_t oe_write(int fd, const void* buf, size_t count);

off_t oe_lseek(int fd, off_t offset, int whence);

int oe_link(uint64_t devid, const char* oldpath, const char* newpath);

int oe_unlink(uint64_t devid, const char* pathname);

int oe_rmdir(uint64_t devid, const char* pathname);

int oe_truncate(uint64_t devid, const char* path, off_t length);

#if defined(OE_NEED_STDC_NAMES)

#define STDIN_FILENO OE_STDIN_FILENO
#define STDOUT_FILENO OE_STDOUT_FILENO
#define STDERR_FILENO OE_STDERR_FILENO
#define F_OK OE_F_OK
#define R_OK OE_R_OK
#define W_OK OE_W_OK
#define X_OK OE_X_OK
#define SEEK_SET OE_SEEK_SET
#define SEEK_CUR OE_SEEK_CUR
#define SEEK_END OE_SEEK_END

OE_INLINE void* sbrk(intptr_t increment)
{
    return oe_sbrk(increment);
}

OE_INLINE ssize_t read(int fd, void* buf, size_t count)
{
    return oe_read(fd, buf, count);
}

OE_INLINE ssize_t write(int fd, const void* buf, size_t count)
{
    return oe_write(fd, buf, count);
}

OE_INLINE int access(const char* pathname, int mode)
{
    return oe_access(0, pathname, mode);
}

OE_INLINE off_t lseek(int fd, off_t offset, int whence)
{
    return oe_lseek(fd, offset, whence);
}

OE_INLINE int link(const char* oldpath, const char* newpath)
{
    return oe_link(0, oldpath, newpath);
}

OE_INLINE int unlink(const char* pathname)
{
    return oe_unlink(0, pathname);
}

OE_INLINE int rmdir(const char* pathname)
{
    return oe_rmdir(devid, pathname);
}

OE_INLINE int truncate(const char* path, off_t length)
{
    return oe_truncate(0, path, length);
}

#endif /* defined(OE_NEED_STDC_NAMES) */

OE_EXTERNC_END

#endif /* _OE_UNISTD_H */
