//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h> //Utilizar get_long("");
#include <math.h> //Utilizar pow;
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

//int i;
int Divisão;
int Validez;
int SomaTotal;
int SomaAlg[17];
int Algarismo[17];
int RestoAlg;
long Sobra;

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
    if ((NC[0] == '3' && NC[1] == '7') || (NC[0] == '3' && NC[1] == '7'))
    {
        for (int j = 0; j < strlen(NC); j++)
        {
            S = j % 2;
            if (S != 0)
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
        }
        Soma = D[0] + D[1] + D[2] + D[3] + D[4] + D[5] + D[6] + D[7] + D[8] + D[9] + D[10] + D[11] + D[12] + D[13] + D[14];
        if (Soma % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (NC[0] == '5' && (NC[1] == '1' || NC[1] == '2' || NC[1] == '3' || NC[1] =='4' || NC[1] == '5'))
    {
        for (int j = 0; j < strlen(NC); j++)
        {
            S = j % 2;
            if (S == 0)
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
        }
        Soma = D[0] + D[1] + D[2] + D[3] + D[4] + D[5] + D[6] + D[7] + D[8] + D[9] + D[10] + D[11] + D[12] + D[13] + D[14] + D[15];
        if (Soma % 10 == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (NC[0] == '4')
    {
        if (strlen(NC) == 16)
        {
            for (int j = 0; j < strlen(NC); j++)
            {
                S = j % 2;
                if (S == 0)
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
            }
            Soma = D[0] + D[1] + D[2] + D[3] + D[4] + D[5] + D[6] + D[7] + D[8] + D[9] + D[10] + D[11] + D[12] + D[13] + D[14] + D[15];
            if (Soma % 10 == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            for (int j = 0; j < strlen(NC); j++)
            {
                S = j % 2;
                if (S != 0)
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
            }
            Soma = D[0] + D[1] + D[2] + D[3] + D[4] + D[5] + D[6] + D[7] + D[8] + D[9] + D[10] + D[11] + D[12];
            if (Soma % 10 == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }  
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}