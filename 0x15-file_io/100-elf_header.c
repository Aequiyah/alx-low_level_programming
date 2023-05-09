#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <elf.h>

#define BUF_SIZE 1024

void print_error(char *error_msg) {
    fprintf(stderr, "Error: %s\n", error_msg);
    exit(98);
}

void print_elf_header(Elf64_Ehdr elf_header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header.e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("  Data:                              %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "2's complement, little endian");
    printf("  Version:                           %d\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "UNIX - Other");
    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (elf_header.e_type) {
        case ET_NONE:
            printf("NONE (None)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", elf_header.e_type);
            break;
    }
    printf("  Entry point address:               %lx\n", elf_header.e_entry);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_error("Invalid number of arguments");
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Unable to open file");
    }

    char buf[BUF_SIZE];
    ssize_t n_read = read(fd, buf, BUF_SIZE);
    if (n_read == -1) {
        print_error("Unable to read from file");
    }

    Elf64_Ehdr elf_header;
    memcpy(&elf_header, buf, sizeof(Elf64_Ehdr));

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header(elf_header);

    if (close(fd) == -1) {
        print_error("Unable to close file");
    }

    return 0;
}

