#include "main.h"
#include <stdio.h>
#include <elf.h>

/**
 * print_class_field - prints the class from an elf header
 *
 * @magic: header information
 *
 * Return: void
 */
void print_class_field(unsigned char *magic)
{
	printf("  %-35s", "Data:");
	if (magic[5] == 1)
		printf("2's complement, little endian\n");
	else if (magic[5] == 2)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %02hx>", magic[5]);
}

/**
 * print_data_field - prints the information about data organization
 * from the elf header
 *
 * @magic: header information
 *
 * Return: void
 */
void print_data_field(unsigned char *magic)
{
	printf("  %-35s", "Data:");
	if (magic[5] == 1)
		printf("2's complement, little endian\n");
	else if (magic[5] == 2)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %02hx>", magic[5]);
}

/**
 * print_version_field - prints version info from elf header
 *
 * @magic: header information
 *
 * Return: void
 */
void print_version_field(unsigned char *magic)
{
	printf("  %-35s", "Version:");
	if (magic[6] <= EV_CURRENT)
	{
		printf("%d", magic[6]);
		if (magic[6] == EV_CURRENT)
			printf(" (current)\n");
		else
			printf("\n");
	}
	else
	{
		printf("49 <unknown %%lx>");
	}
}

/**
 * print_abi_version - prints abi version from header information
 *
 * @magic: header information
 *
 * Return: void
 */
void print_abi_version(unsigned char *magic)
{
	printf("  %-35s", "OS/ABI:");
	printf(magic[7] == 0 ? "UNIX - System V\n" :
			magic[7] == 1 ? "UNIX - HP-UX\n" :
			magic[7] == 2 ? "UNIX - NetBSD\n" :
			magic[7] == 3 ? "UNIX - Linux\n" :
			magic[7] == 4 ? "UNIX - GNU Hurd\n" :
			magic[7] == 6 ? "UNIX - Solaris\n" :
			magic[7] == 7 ? "UNIX - AIX\n" :
			magic[7] == 8 ? "UNIX - IRIX\n" :
			magic[7] == 9 ? "UNIX - FreeBSD\n" :
			magic[7] == 10 ? "UNIX - Tru64\n" :
			magic[7] == 11 ? "UNIX - Novell Modesto\n" :
			magic[7] == 12 ? "UNIX - OpenBSD\n" :
			magic[7] == 13 ? "UNIX - Open VMS\n" :
			magic[7] == 14 ? "UNIX - NonStop Kernel\n" :
			magic[7] == 15 ? "UNIX - AROS\n" :
			magic[7] == 16 ? "UNIX - Fenix OS\n" :
			magic[7] == 17 ? "UNIX - CloudABI\n" : "<unknown: %02x>\n", magic[7]);
	printf("  %-35s%d\n", "ABI Version:", magic[8]);
}

/**
 * print_type_field - prints elf filetype from header info
 *
 * @magic: header information
 *
 * Return: void
 */
void print_type_field(unsigned char *magic)
{
	int index;

	if (magic[5] == 1)
		index = 16;
	else
		index = 17;
	printf("  %-35s", "Type:");
	if (magic[index] == 1)
		printf("REL (Relocatable file)\n");
	else if (magic[index] == 2)
		printf("EXEC (Executable file)\n");
	else if (magic[index] == 3)
		printf("DYN (Shared object file)\n");
	else if (magic[index] == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown>: %02x%02x\n", magic[16], magic[17]);
}

/**
 * print_entry_point - prints entry address of executable from header
 *
 * @magic: header information
 *
 * Return: void
 */
void print_entry_point(unsigned char *magic)
{
	int i, last;
	int isLittleEndian = (magic[5] == 1);

	printf("  %-35s0x", "Entry point address:");
	if (magic[4] == 2)
		last = 0x1f;
	else
		last = 0x1b;
	if (isLittleEndian)
	{
		i = last;
		while (magic[i] == 0 && i > 0x18)
			i--;
		printf("%x", magic[i--]);
		while (i >= 0x18)
			printf("%02x", (unsigned char) magic[i--]);
		printf("\n");
	}
	else
	{
		i = 0x18;
		while (magic[i] == 0)
			i++;
		printf("%x", magic[i++]);
		while (i <= last)
			printf("%02x", (unsigned char) magic[i++]);
		printf("\n");
	}
}


/**
 * main - parses an elf header file
 *
 * @argc: number of args
 * @argv: arugment strings
 *
 * Return: 0 on success
 *
 * 98 if error
 */
int main(int argc, char *argv[])
{
	int fd, i;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		return (98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (98);
	}
	i = read(fd, &elf_header, sizeof(elf_header));
	if (i == -1 || i < (int)sizeof(elf_header))
	{
		dprintf(STDERR_FILENO, "Failed to read ELF file\n");
		return (98);
	}
	if (elf_header.e_ident[0] != 0x7f || elf_header.e_ident[1] != 'E'
			|| elf_header.e_ident[2] != 'L' || elf_header.e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Failed to read ELF file\n");
		return (98);
	}
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < 15; i++)
		printf("%02x ", elf_header.e_ident[i]);
	printf("%02x\n", elf_header.e_ident[15]);
	print_class_field(elf_header.e_ident);
	print_data_field(elf_header.e_ident);
	print_version_field(elf_header.e_ident);
	print_abi_version(elf_header.e_ident);
	print_type_field(elf_header.e_ident);
	print_entry_point(elf_header.e_ident);
	return (0);
}
