/***************************
 * Author: Felipe Derkian
 * Data: 04/10/2020
 * Disciplina: Compiladores
 * Trabalho: Slide 6 - Reconhecer 4 tipos de linguagens regulares
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "validators.h"

void check_tot_arguments(int argc)
{
    if (argc != 2)
    {
        printf("Informe o nome do arquivo na chamada do programa\nEx.: filename.txt\n");
        exit(EXIT_FAILURE);
    }
}

void check_file_name(char *file_name)
{
    regex_t reg;

    if (regcomp(&reg, "^[a-zA-Z0-9][a-zA-Z0-9]*.txt$", REG_EXTENDED | REG_NOSUB) != 0)
    {
        fprintf(stderr, "erro regcomp\n");
        exit(EXIT_FAILURE);
    }

    if (!(regexec(&reg, file_name, 0, (regmatch_t *)NULL, 0)) == 0)
    {
        printf("Informe o nome de um arquivo com extensão .txt no argumento...\n");
        exit(EXIT_FAILURE);
    }
}