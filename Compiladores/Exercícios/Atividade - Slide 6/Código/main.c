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
#include "inteiro.h"
#include "decimal.h"
#include "cpf.h"
#include "dataBR.h"

int main(int argc, char const *argv[])
{
    char file_name[500] = "";
    char word[500] = "";
    int tam_file_name = 0;

    //"validators.h"
    check_tot_arguments(argc);
    //string.h
    strcpy(file_name, argv[1]);
    //"validators.h"
    check_file_name(file_name);
    //abre o arquivo caso exista
    FILE *file = fopen(file_name, "r");
    //"validators.h"
    check_file_exists(file, file_name);

    while (fscanf(file, "%s", word) != EOF)
    {
        if (validateDecimalValue(word))
        {
            printf("Reconheceu: %s :Como Decimal.\n", word);
        }
        else if (validateInteiroValue(word))
        {
            printf("Reconheceu: %s :Como Inteiro\n", word);
        }
        else if (validateCpfValue(word))
        {
            printf("Reconheceu: %s :Como CPF\n", word);
        }
        else if (validateDataBRValue(word))
        {
            printf("Reconheceu: %s :Como dataBR\n", word);
        }
        else
        {
            printf("%s --> NAO RECONHECIDO\n", word);
        }
    }

    fclose(file);
    return 0;
}
