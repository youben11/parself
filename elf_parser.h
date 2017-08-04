#ifndef ELF_PARSER
#define ELF_PARSER

#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>

char* ELF; // addr of the content of the ELF
char* STRTAB; // addr of the string table

Elf32_Shdr* SYMTAB32;
Elf32_Shdr* DYNSYM32;

Elf64_Shdr* SYMTAB64;
Elf64_Shdr* DYNSYM64;


void usage(char* prog);
void fatal(char* msg);
int check_magic(char* ident);
void space(int count);

//Getters
char* get_hdata(unsigned char data);
char* get_hversion(unsigned char version);
char* get_hosabi(unsigned char osabi);
char* get_htype(unsigned short type);
char* get_hmachine(unsigned short machine);

char* get_phtype(unsigned int type);
char* get_phflags(unsigned int flags);

char* get_shtype(unsigned int type);
char* get_shflags(unsigned int flags);

char* get_symtype32(unsigned char info);
char* get_symtype64(unsigned char info);
char* get_symbind32(unsigned char info);
char* get_symbind64(unsigned char info);
char* get_symvis32(unsigned char other);
char* get_symvis64(unsigned char other);

//Elf32 functions
void parse_elf32(Elf32_Ehdr hdr, FILE* elf);
void print_ehdr32(Elf32_Ehdr hdr);
void print_ephtbl32(Elf32_Ehdr hdr);
void print_eshtbl32(Elf32_Ehdr hdr);
void print_esymtbl32(Elf32_Shdr* shdr, char* name);
void print_ephdr32(Elf32_Phdr* phdr);
void print_eshdr32(Elf32_Shdr* shdr, int index);
void print_esym32(Elf32_Sym* sym, int index);


//Elf64 functions
void parse_elf64(Elf64_Ehdr hdr, FILE* elf);
void print_ehdr64(Elf64_Ehdr hdr);
void print_ephtbl64(Elf64_Ehdr hdr);
void print_eshtbl64(Elf64_Ehdr hdr);
void print_esymtbl64(Elf64_Shdr* shdr, char* name);
void print_ephdr64(Elf64_Phdr* phdr);
void print_eshdr64(Elf64_Shdr* shdr, int index);
void print_esym64(Elf64_Sym* sym, int index);



#endif
