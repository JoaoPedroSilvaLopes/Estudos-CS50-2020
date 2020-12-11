//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h>
#include <math.h>


int Resto;
int x = 10;
int y = 3;

int main(void)
{
    long NC = get_long("");
    
    if (NC >= 34*pow(10,13) && NC < 35*pow(10,13))
    {
        printf("AMERICANEXPRESS\n");
    }
    else if (NC >= 51*pow(10,14) && NC < 56*pow(10,14))
    {
        printf("MASTERCARD\n");
    }
    else if ((NC >= 4*pow(10,12) && NC < 5*pow(10,12)) || (NC >= 16*pow(10,15) && NC < 5*pow(10,15)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    
return 0;
}