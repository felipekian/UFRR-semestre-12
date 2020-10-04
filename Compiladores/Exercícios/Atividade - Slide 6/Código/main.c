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


int main(int argc, char const *argv[])
{
    char file_name[1000];
    int tam_file_name;

    check_tot_arguments(argc);
    strcpy(file_name, argv[1]);
    check_file_name(file_name);

    

    return 0;
}
