#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_error_exit(int code, const char *format, const char *arg) {
    dprintf(STDERR_FILENO, format, arg);
    exit(code);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_error_exit(97, "Usage: cp file_from file_to\n");
    }

    int fd_from, fd_to;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUF_SIZE];

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        print_error_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1) {
        print_error_exit(99, "Error: Can't write to %s\n", argv[2]);
    }

    while ((bytesRead = read(fd_from, buffer, BUF_SIZE)) > 0) {
        bytesWritten = write(fd_to, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            print_error_exit(99, "Error: Can't write to %s\n", argv[2]);
        }
    }

    if (bytesRead == -1) {
        print_error_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    if (close(fd_from) == -1 || close(fd_to) == -1) {
        print_error_exit(100, "Error: Can't close fd %d\n", errno);
    }

    return 0;
}

