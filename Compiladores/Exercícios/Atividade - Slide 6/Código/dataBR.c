/***************************
 * Author: Felipe Derkian
 * Data: 05/10/2020
 * Disciplina: Compiladores
 * Trabalho: Slide 6 - Reconhecer 4 tipos de linguagens regulares
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataBR.h"


#define ACEITO 1
#define NAO_ACEITO 0


int m_dataBR[10][10] = {
    {1,0,0,0,0,0,0,0,0,0},
    {0,2,0,0,0,0,0,0,0,0},
    {0,0,3,0,0,0,0,0,0,0},
    {0,0,0,4,0,0,0,0,0,0},
    {0,0,0,0,5,0,0,0,0,0},
    {0,0,0,0,0,6,0,0,0,0},
    {0,0,0,0,0,0,7,0,0,0},
    {0,0,0,0,0,0,0,8,0,0},
    {0,0,0,0,0,0,0,0,9,0},
    {0,0,0,0,0,0,0,0,0,10}
};


void initialize_dataBR(){
    tam_str_dataBR = 0;
    estado_dataBR = 0;
    char_current_dataBR;
}


int validateDataBRValue(char *str){
    initialize_dataBR();
    tam_str_dataBR = strlen(str);
    
    for (int i = 0; i < tam_str_dataBR; i++)
    {
        char_current_dataBR = str[i];        

        switch (char_current_dataBR){
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
            case '/':
            case '-':
                c_dataBR = i;
            break;    
            default:
                return 0;
                break;
        }

        estado_dataBR = m_dataBR[c_dataBR][estado_dataBR];

    }

    return (estado_dataBR == 10 ? ACEITO : NAO_ACEITO);

}