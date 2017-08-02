#ifndef ELF_PARSER
#define ELF_PARSER

#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>

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

//Elf32 functions
void parse_elf32(Elf32_Ehdr hdr, FILE* elf);
void print_ehdr32(Elf32_Ehdr hdr);
void print_ephtbl32(Elf32_Ehdr hdr, FILE* elf);
void print_eshtbl32(Elf32_Ehdr hdr, FILE* elf);
void print_ephdr32(Elf32_Phdr phdr);
void print_eshdr32(Elf32_Shdr shdr);


//Elf64 functions
void parse_elf64(Elf64_Ehdr hdr, FILE* elf);
void print_ehdr64(Elf64_Ehdr hdr);
void print_ephtbl64(Elf64_Ehdr hdr, FILE* elf);
void print_eshtbl64(Elf64_Ehdr hdr, FILE* elf);
void print_ephdr64(Elf64_Phdr phdr);
void print_eshdr64(Elf64_Shdr shdr);



#endif
