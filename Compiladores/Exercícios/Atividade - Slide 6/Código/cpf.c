/***************************
 * Author: Felipe Derkian
 * Data: 05/10/2020
 * Disciplina: Compiladores
 * Trabalho: Slide 6 - Reconhecer 4 tipos de linguagens regulares
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpf.h"


#define ACEITO 1
#define NAO_ACEITO 0


int m_cpf[14][14] = {
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,3,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,4,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,5,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,6,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,7,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,8,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,9,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,10,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,11,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,12,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,13,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,14}
};


void initialize_cpf(){
    tam_str_cpf = 0;
    estado_cpf = 0;
    char_current_cpf;
}


int validateCpfValue(char *str){
    initialize_cpf();
    tam_str_cpf = strlen(str);
    
    for (int i = 0; i < tam_str_cpf; i++)
    {
        char_current_cpf = str[i];        

        switch (char_current_cpf){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
            case '-':
                c_cpf = i;
            break;    
            default:
                return 0;
                break;
        }

        estado_cpf = m_cpf[c_cpf][estado_cpf];

    }

    return (estado_cpf == 14 ? ACEITO : NAO_ACEITO);

}