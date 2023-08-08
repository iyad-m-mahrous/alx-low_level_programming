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
void print_class_field(char *magic)
{
	printf("  %-35s", "Class:");
	if (magic[4] == 2)
		printf("ELF64\n");
	else if (magic[4] == 1)
		printf("ELF32\n");
	else
		printf("<unknown: %02hx>", magic[4]);
}

/**
 * print_data_field - prints the information about data organization
 * from the elf header
 *
 * @magic: header information
 *
 * Return: void
 */
void print_data_field(char *magic)
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
void print_version_field(char *magic)
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
void print_abi_version(char *magic)
{
	printf("  %-35s", "OS/ABI:");
	if (magic[7] == 0)
		printf("UNIX - System V\n");
	else if (magic[7] == 1)
		printf("UNIX - HP-UX\n");
	else if (magic[7] == 2)
		printf("UNIX - NetBSD\n");
	else if (magic[7] == 3)
		printf("UNIX - Linux\n");
	else if (magic[7] == 4)
		printf("UNIX - GNU Hurd\n");
	else if (magic[7] == 6)
		printf("UNIX - Solaris\n");
	else if (magic[7] == 7)
		printf("UNIX - AIX\n");
	else if (magic[7] == 8)
		printf("UNIX - IRIX\n");
	else if (magic[7] == 9)
		printf("UNIX - FreeBSD\n");
	else if (magic[7] == 10)
		printf("UNIX - Tru64\n");
	else if (magic[7] == 11)
		printf("UNIX - Novell Modesto\n");
	else if (magic[7] == 12)
		printf("UNIX - OpenBSD\n");
	else if (magic[7] == 13)
		printf("UNIX - Open VMS\n");
	else if (magic[7] == 14)
		printf("UNIX - NonStop Kernel\n");
	else if (magic[7] == 15)
		printf("UNIX - AROS\n");
	else if (magic[7] == 16)
		printf("UNIX - Fenix OS\n");
	else if (magic[7] == 17)
		printf("UNIX - CloudABI\n");
	else
		printf("<unknown: %02x>\n", magic[7]);
	printf("  %-35s%d\n", "ABI Version:", magic[8]);
}

/**
 * print_type_field - prints elf filetype from header info
 *
 * @magic: header information
 *
 * Return: void
 */
void print_type_field(char *magic)
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
void print_entry_point(char *magic)
{
	int i, end;

	printf("  %-35s0x", "Entry point address:");
	if (magic[4] == 2)
		end = 0x1f;
	else
		end = 0x1b;
	if (magic[5] == 1)
	{
		i = end;
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
		while (i <= end)
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
	char magic[17];

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
	i = read(fd, magic, 17);
	if (i == -1 || i < 17)
	{
		dprintf(STDERR_FILENO, "Failed to read ELF file\n");
		return (98);
	}
	if (magic[0] != 0x7f || magic[1] != 'E' || magic[2] != 'L' || magic[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Failed to read ELF file\n");
		return (98);
	}
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < 15; i++)
		printf("%02x ", (unsigned int) magic[i]);
	printf("%02x\n", (unsigned int) magic[15]);
	print_class_field(magic);
	print_data_field(magic);
	print_version_field(magic);
	print_abi_version(magic);
	print_type_field(magic);
	print_entry_point(magic);
	return (0);
}
