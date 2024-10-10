#include "fops.h"
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int create_file(const char *filename, int flags, mode_t mode)
{
    int fd = syscall(SYS_open, filename, flags, mode);
    if (fd == -1){
        printf("Error creating file errno=%d %s\n", errno, strerror(errno));
    }
    return fd;
}
ssize_t write_to_file(int fd, const void *buf, size_t count)
{
    int value = syscall(SYS_write, fd, buf, count);
    if (value == -1){
        printf("Error writing to file errno=%d %s\n", errno, strerror(errno));
    }
    return value;
}

ssize_t read_from_file(int fd, void *buf, size_t count)
{
    int value = syscall(SYS_read, fd, buf, count);
    if (value == -1){
        printf("Error reading from file errno=%d %s\n", errno, strerror(errno));
    }
    return value;
}
int close_file(int fd)
{
    int value = syscall(SYS_close, fd);
    if (value == -1){
        printf("Error closing file or file does not exist errno=%d %s\n", errno, strerror(errno));
    }
    return value;
}
int delete_file(const char *filename)
{
    int value = syscall(SYS_unlink, filename);
    if (value == -1){
        printf("Error deleting file errno=%d %s\n", errno, strerror(errno));
    }
    return value;
}