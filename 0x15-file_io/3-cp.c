#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_error(int code, const char* error) {
    dprintf(STDERR_FILENO, "Error: %s\n", error);
    exit(code);
}

void copy_file(const char* file_from, const char* file_to) {
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[BUF_SIZE];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        print_error(98, "Can't read from file");

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1)
        print_error(99, "Can't write to file");

    while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1)
            print_error(99, "Can't write to file");
    }

    if (bytes_read == -1)
        print_error(98, "Can't read from file");

    if (close(fd_from) == -1 || close(fd_to) == -1)
        print_error(100, "Can't close file descriptor");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    copy_file(argv[1], argv[2]);

    return 0;
}

