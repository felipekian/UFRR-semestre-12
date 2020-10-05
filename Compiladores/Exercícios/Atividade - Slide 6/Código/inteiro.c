/***************************
 * Author: Felipe Derkian
 * Data: 05/10/2020
 * Disciplina: Compiladores
 * Trabalho: Slide 6 - Reconhecer 4 tipos de linguagens regulares
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inteiro.h"


#define ACEITO 1
#define NAO_ACEITO 0


int m_inteiro[1][1] = {
    {0}
};


void initialize_inteiro(){
    tam_str_inteiro = 0;
    estado_inteiro = 0;
    char_current_inteiro;
}


int validateInteiroValue(char *str){
    initialize_inteiro();
    tam_str_inteiro = strlen(str);

    for (int i = 0; i < tam_str_inteiro; i++)
    {
        char_current_inteiro = str[i];        

        switch (char_current_inteiro){
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
                c_inteiro = 0;
            break;            
            default:
                return 0;
                break;
        }

        estado_inteiro = m_inteiro[c_inteiro][estado_inteiro];
    }

    return (estado_inteiro == 0 ? ACEITO : NAO_ACEITO);

}