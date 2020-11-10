/**
 *  Autor: Felipe Derkian
 *  Disciplina: Compiladores
 *  Atividade: Slide 13
 */

#include <bits/stdc++.h>

using namespace std;

//declarações das funções
void stringUppercase();
int getColunaExpressaoCurrentTabelaDR(char current);
int getLinhaPilhaCorrentTabelaDR(char current);
int getMathExpressionGramatica(char *current);
bool analisadorSintatico();

//referencias as operações da tabelaDR
#define Q 0
#define D 1
#define R 2

//dimensão da matriz
#define M 9
#define N 6

//gramatica dimensões
#define LG 6
#define CG 10

//gramatica (- == ->)
char gramatica[LG][CG] = {
    "E->E+M",
    "E->M",
    "M->MxP",
    "M->P",
    "P->(E)",
    "P->V",
};

//tabelaDR
int tabela_DR[M][N] = {
    {D, Q, Q, D, Q, Q},
    {R, D, Q, R, Q, R},
    {R, R, Q, R, Q, R},
    {Q, Q, D, Q, D, Q},
    {Q, Q, D, Q, D, Q},
    {Q, Q, D, Q, D, Q},
    {R, R, Q, R, Q, R},
    {R, R, Q, R, Q, R},
    {Q, Q, D, Q, D, Q},
};

//pilha de analise sintantica
stack<char> pilha;

//expressao a ser analisada
char expression[] = "v+v*v\0";

//função principal
int main()
{
    stringUppercase();
    pilha.push('$');
    bool flag = analisadorSintatico();
    cout << (flag ? "Aceito" : "Nao aceito") << endl;
    return 0;
}


//parte do código que faz a analise se é redução, derivação ou falha
bool analisadorSintatico()
{
    bool flag = true;

    for (int i = 0; expression[i] != '\0' && flag; i++)
    {

        int linhaTabelaDR = getLinhaPilhaCorrentTabelaDR(pilha.top());
        int colunaTabelaDR = getColunaExpressaoCurrentTabelaDR(expression[i]);

        int operationCurrent = tabela_DR[linhaTabelaDR][colunaTabelaDR];

        if (operationCurrent == D)
        {
            cout << "TIPO D" << endl;
            pilha.push(expression[i]);
        }
        else if (operationCurrent == R)
        {
            /**
             *  ANALISAR ESSA PARTE COM O ALGORITMO DO SLIDE
             */
            cout << "TIPO R" << endl;
            char operacaoAnalise[100] = "";
            char validado[100] = "";

            char analisePilha = pilha.top();
            pilha.pop();

            while (true)
            {
                operacaoAnalise[strlen(operacaoAnalise)] = analisePilha;
                operacaoAnalise[strlen(operacaoAnalise)] = '\0';
                
                int posGramatica = getMathExpressionGramatica(operacaoAnalise);
                char gr_selec[100] = "";

                strcpy(gr_selec, gramatica[posGramatica]);

                if (posGramatica != -1)
                {
                    strcpy(validado, gr_selec);
                    pilha.push(validado[0]);
                    strcpy(validado, "");
                    break;
                }
            }
            i--;
        }
        else if (operationCurrent == Q)
        {
            cout << "TIPO Q" << endl;
            flag = !flag;
        }
    }

    return flag;
}

//verifica a expressão que combina com a que esta sendo analisada
int getMathExpressionGramatica(char *current)
{
    char *resposta;
    
    for (int i = 0; i < LG; i++)
    {
        for (int j = 0; j < gramatica[i][j] != '\0'; j++)
        {

            /**
             *  CASO ENCONTRE SIMILARIDADE
             *  ANALISAR a PARTIR DAQUI
             */
            if (current[0] == gramatica[i][j])
            {
                bool flag_math = true;
                int tam = strlen(gramatica[i]);
                int tam_current = strlen(current);

                for (int k = j, t = 0; gramatica[i][k] != '\0' && current[t] != '\0'; k++, t++)
                {
                    if (gramatica[i][k] != current[t])
                    {
                        flag_math = !flag_math;
                        break;
                    }
                }

                if (flag_math)
                {
                    cout << "gramatica selecionada: " << gramatica[i] << "  |  Current: " << current << endl;
                    //return a posição da lista
                    return i;
                }
            }
        }
    }

    return -1;
}

//converte a entrada para uppercase para padronizar a analise
void stringUppercase()
{
    int i = 0;
    while (expression[i])
    {
        expression[i] = toupper(expression[i]);
        i++;
    }

    cout << expression << endl;
}

//retorna a posição da coluna correspondente ao elemente corrente da entrada de analise
int getColunaExpressaoCurrentTabelaDR(char current)
{
    int atual = -1;

    switch (current)
    {
    case '+':
        atual = 0;
        break;
    case '*':
        atual = 1;
        break;
    case '(':
        atual = 2;
        break;
    case ')':
        atual = 3;
        break;
    case 'V':
        atual = 4;
        break;
    case '$':
        atual = 5;
        break;
    default:
        atual = -1;
    }
    return atual;
}

//retorna a posição da linha correspondente ao elemento corrente no topo da pilha de analise
int getLinhaPilhaCorrentTabelaDR(char current)
{
    int atual = -1;

    switch (current)
    {
    case 'E':
        atual = 0;
        break;

    case 'M':
        atual = 1;
        break;

    case 'P':
        atual = 2;
        break;

    case '+':
        atual = 3;
        break;

    case '*':
        atual = 4;
        break;

    case '(':
        atual = 5;
        break;

    case ')':
        atual = 6;
        break;

    case 'V':
        atual = 7;
        break;

    case '$':
        atual = 8;
        break;

    default:
        atual = -1;
    }

    return atual;
}