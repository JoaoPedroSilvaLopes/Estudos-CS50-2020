//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

int D[16];
int d[16];
int Soma;
int S;

int main(void)
{
    string NC = get_string("Insira o número do cartão: ");
    
    for (int i = 0; i < strlen(NC); i++)
    {
        if (!(isdigit(NC[i])) || i >= 16)
        {
            printf("INVALID\n");
        }
    }
    for (int j = 0; j < strlen(NC); j++)
    {
        S = strlen(NC) % 2;
        if ((j % 2) == S)
        {
            d[j] = atol(&NC[j]) / pow(10, strlen(&NC[j]) - 1);
            D[j] = (d[j] * 2) / 10;
            if (D[j] > 0)
            {
                D[j] = D[j] + ((2 * d[j]) % 10);
            }
            else
            {
                D[j] = d[j] * 2;
            }
        }
        else
        {
            D[j] = atol(&NC[j]) / pow(10, strlen(&NC[j]) - 1); 
        }
        Soma = Soma + D[j];
    }
    if ((Soma % 10) == 0 && ((NC[0] == '3' && NC[1] == '4') || (NC[0] == '3' && NC[1] == '7')))
    {
        printf("AMEX\n");
    }
    else if ((Soma % 10) == 0 && (NC[0] == '5' && (NC[1] == '1' || NC[1] == '2' || NC[1] == '3' || NC[1] == '4' || NC[1] == '5')))
    {
        printf("MASTERCARD\n");
    }
    else if ((Soma % 10) == 0 && (NC[0] == '4' && (strlen(NC) == 13 || strlen(NC) == 16)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}