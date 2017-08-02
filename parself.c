#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>
#include "elf_parser.h"


int main(int argc, char** argv){

    if(argc != 2)
        usage(argv[0]);
    
    //Try to open the ELF
    FILE* elf = fopen(argv[1], "rb");
    if(!elf){
        printf("[-] \"%s\" doesn't exist !\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    unsigned char ident[EI_NIDENT];
    fread(&ident, EI_NIDENT, 1, elf);
    if(feof(elf))
        fatal("[-] Unexpected EOF while parsing e_ident");
    
    if(!check_magic(ident))
        fatal("[-] Check the magic number");
   
    //Get the appropriate Elf header
    Elf32_Ehdr ehdr32;
    Elf64_Ehdr ehdr64;
    char eclass;

    if(ident[4] == ELFCLASS32){
        eclass = ELFCLASS32;
        memcpy(&ehdr32.e_ident, &ident, EI_NIDENT);
        fread((char*)&ehdr32 + EI_NIDENT, sizeof(Elf32_Ehdr) - EI_NIDENT, 1,elf);
        if(feof(elf)) 
            fatal("[-] Unexpected EOF while parsing Elf32_header");
    }
    else if(ident[4] == ELFCLASS64){
        eclass = ELFCLASS64;
        memcpy(&ehdr64.e_ident, &ident, EI_NIDENT);
        fread((char*)&ehdr64 + EI_NIDENT, sizeof(Elf64_Ehdr) - EI_NIDENT, 1,elf);
        if(feof(elf))
            fatal("[-] Unexpected EOF while parsing Elf64_header");
    }else
        fatal("[-] ELFCLASS not recognized");
    
    //parse the elf
    if(eclass == ELFCLASS32)
        parse_elf32(ehdr32, elf);
    else
        parse_elf64(ehdr64, elf);

    fclose(elf);

    return 0;
}
