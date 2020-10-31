/**
 *  Author: Felipe Derkian de Sousa Freitas
 *  
 *  Data: 31/10/2020
 * 
 *  Analisador preditivo para a gramática de balanço de parenteses na expressão
 * 
 *  ex: (4 + 3 * ( 4 - 2 ))
 * 
 */

#include <stack>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool validateExpression(char *expression)
{
    stack<char> pilha;
    bool flag = true;
    
    for (int i = 0; i < expression[i] != '\0' && flag; i++)
    {
        cout << "> " << expression[i] << endl;
        switch (expression[i])
        {
        case '(':
            pilha.push('(');
            break;
        case ')':
            if (pilha.empty() || pilha.top() == ')')
            {
                flag = false;
            }
            else if (pilha.top() == '(')
            {
                pilha.pop();
            }
        }
    }

    return (pilha.empty() && flag) ? true : false;
}

int main()
{
    char expression[1000];

    cout << "Informe a sequencia de parenteses:\n>>>  ";
    scanf("%[^\n]s", expression);

    cout << (validateExpression(expression) ? "Balanceado" : "Nao Balanceado") << endl;

    return EXIT_SUCCESS;
}
