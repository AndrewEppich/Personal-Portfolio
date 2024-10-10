#include "fops.h"
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main (int argc, char *argv[]){

if (strcmp(argv[1], "write") == 0){
    int fd = create_file(argv[2], O_RDWR | O_APPEND, 0664);
    if (fd == -1){
        printf("Error creating file errno=%d %s\n", errno, strerror(errno));
    }
    write_to_file(fd, argv[3], 300);
}
else if (strcmp(argv[1], "create") == 0){
    create_file(argv[2], O_RDWR | O_CREAT, 0664);
}
else if (strcmp(argv[1], "read") == 0){
    int fd = create_file(argv[2], O_RDONLY, 0664);
    char buffer[500];
    int bytes_read = read_from_file(fd, buffer, 500);
    if (bytes_read == -1){
        printf("Error reading file, file does not exist=%d %s\n", errno, strerror(errno));
    }
    else{
    printf("Read %d bytes from file: %s\n", bytes_read, buffer);
    }
}
else if (strcmp(argv[1], "close") == 0){
    int fd = create_file(argv[2], O_RDWR, 0664);
    close_file(fd);
}
else if (strcmp(argv[1], "delete") == 0){
    create_file(argv[2], O_RDWR, 0664);
    delete_file(argv[2]);
}
else {
    printf("Please enter a valid option");
}

}