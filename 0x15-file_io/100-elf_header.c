#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - print error message to stderr and exit with status code 98
 * @msg: error message to print
 */
void print_error(char *msg)
{
        fprintf(stderr, "%s\n", msg);
        exit(98);
}

/**
 * print_elf_header - print ELF header information
 * @header: pointer to ELF header
 */
void print_elf_header(Elf64_Ehdr *header)
{
        int i;

        printf("  Magic:   ");
        for (i = 0; i < EI_NIDENT; i++)
                printf("%02x ", header->e_ident[i]);
        printf("\n");

        printf("  Class:                             ");
        switch (header->e_ident[EI_CLASS])
        {
                case ELFCLASSNONE: printf("none\n"); break;
                case ELFCLASS32:   printf("ELF32\n"); break;
                case ELFCLASS64:   printf("ELF64\n"); break;
                default:           printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
        }

        printf("  Data:                              ");
        switch (header->e_ident[EI_DATA])
        {
                case ELFDATANONE: printf("none\n"); break;
                case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
                case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
                default:          printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
        }

        printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);

        printf("  OS/ABI:                            ");
        switch (header->e_ident[EI_OSABI])
        {
                case ELFOSABI_NONE:     printf("UNIX System V ABI\n"); break;
                case ELFOSABI_HPUX:     printf("HP-UX ABI\n"); break;
                case ELFOSABI_NETBSD:   printf("NetBSD ABI\n"); break;
                case ELFOSABI_LINUX:    printf("Linux ABI\n"); break;
                case ELFOSABI_SOLARIS:  printf("Solaris ABI\n"); break;
                case ELFOSABI_AIX:      printf("AIX ABI\n"); break;
                case ELFOSABI_IRIX:     printf("IRIX ABI\n"); break;
                case ELFOSABI_FREEBSD:  printf("FreeBSD ABI\n"); break;
                case ELFOSABI_TRU64:    printf("TRU64 UNIX ABI\n"); break;
                case ELFOSABI_MODESTO:  printf("Novell Modesto ABI\n"); break;
                case ELFOSABI_OPENBSD:  printf("OpenBSD ABI\n"); break;
                case ELFOSABI_ARM_AEABI:printf("ARM EABI\n"); break;
                case ELFOSABI_ARM:      printf("ARM\n"); break;
                case ELFOSABI_STANDALONE: printf("Standalone (embedded) application\n"); break;
                default:                printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
        }

        printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

        printf("  Type:                              ");
        switch (header->e_type)
        {
                case ET_NONE:     printf("none\n"); break;
                case ET_REL:      printf("relocatable\n"); break;

