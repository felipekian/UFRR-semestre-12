/***************************
 * Author: Felipe Derkian
 * Data: 04/10/2020
 * Disciplina: Compiladores
 * Trabalho: Slide 6 - Reconhecer 4 tipos de linguagens regulares
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decimal.h"


#define ACEITO 1
#define NAO_ACEITO 0


int m_decimal[3][2] = {
    {0, -1},
    {1, -1},
    {-1, 1}
};



void initialize_decimal(){
    tam_str_decimal = 0;
    estado_decimal = 0;
    char_current_decimal;
}



int validateDecimalValue(char *str){
    initialize_decimal();
    tam_str_decimal = strlen(str);

    for (int i = 0; i < tam_str_decimal; i++)
    {
        char_current_decimal = str[i];        

        switch (char_current_decimal){
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
                if(estado_decimal == 0){
                    c_decimal = 0;
                } else {
                    c_decimal = 2;
                }
            break;            
            case '.':
                c_decimal = 1;
            break;
            default:
                return 0;
                break;
        }

        estado_decimal = m_decimal[c_decimal][estado_decimal];
    }

    return (estado_decimal == 1 ? ACEITO : NAO_ACEITO);    
    
}
