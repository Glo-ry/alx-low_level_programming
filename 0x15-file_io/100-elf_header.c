#include <stdio.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


void elf_file_checker(unsigned char *e_ident);
void _magic(unsigned char *e_ident);
void _class(unsigned char *e_ident);
void _data(unsigned char *e_ident);
void _version(unsigned char *e_ident);
void os_abi(unsigned char *e_ident);
void _abi(unsigned char *e_ident);
void _type(unsigned int e_type, unsigned char *e_ident);
void entry_point(unsigned long int e_entry, unsigned char *e_ident);
void elf_closure(int elf);

/**
 * elf_file_checker - function that checks for ELF file
 * @e_ident: pointer to elf numbers.
 * Return: elf
 */
void elf_file_checker(unsigned char *e_ident)
{
	if (e_ident[0] != 127 ||
			e_ident[1] != 'E' ||
			e_ident[2] != 'L' ||
			e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}


/**
 * _magic - function that checks and display magic numbers of elf header
 * @e_ident: pointer to elf numbers
 */
void _magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


/**
 * _class - function that checks and display class of elf heade.
 * @e_ident: pointer to elf class
 */
void _class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * _data - function that checks and display data of elf header
 * @e_ident: pointer to elf data
 */
void _data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * _version - function that checks and display version of elf header
 * @e_ident: pointer to elf numbers
 */
void _version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}


/**
 * os_abi - function that checks and display OS/ABI of ELF header
 * @e_ident: pointer to elf
 */
void os_abi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}


/**
 * _abi - function that checks and display ABI version of elf header
 * @e_ident: pointer to elf elf abi
 */
void _abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}


/**
 * _type - function that checks and display type of elf header
 * @e_type: the type
 * @e_ident: pointer to elf
 */
void _type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
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
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * entry_point - function that checks and display entry point of an elf header
 * @e_entry: entry point
 * @e_ident: pointer to elf
 */
void entry_point(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}


/**
 * elf_closure - function that checks and closes elf file
 * @elf: elf descriptor
 */
void elf_closure(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


/**
 * main - program that arrange and displays
 * the information contained in the elf file
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_closure(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		elf_closure(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_file_checker(header->e_ident);
	printf("ELF Header:\n");
	_magic(header->e_ident);
	_class(header->e_ident);
	_data(header->e_ident);
	_version(header->e_ident);
	os_abi(header->e_ident);
	_abi(header->e_ident);
	_type(header->e_type, header->e_ident);
	entry_point(header->e_entry, header->e_ident);

	free(header);
	elf_closure(o);
	return (0);
}

