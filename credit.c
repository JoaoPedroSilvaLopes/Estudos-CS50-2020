//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int i = 0;
int NS[16];
long Resto;
int Resto1;
int Soma;

int main(void)
{
    long NC = get_long("Insira o número do cartão: ");
    
    if ((NC >= 34*pow(10,13) && NC < 35*pow(10,13)) || (NC >= 37*pow(10,13) && NC < 38*pow(10,13)))
    {
        for(int z = 14; z >= 0; z--)
        {
            NS[0] = NC/pow(10,z);
            printf("%i\n\n", NS[0]);
            Resto = NC % (long) pow(10,z);
            NC = Resto;
            i++;
        }
        Soma = (NS[1]*2 + NS[3]*2 + NS[5]*2 + NS[7]*2 + NS[9]*2 + NS[11]*2 + NS[13]*2) + NS[0] + NS[2] +  NS[4] + NS[6] +  NS[8] + NS[10] +  NS[12] + NS[14];
        printf("%i\n", Soma);
        Resto1 = Soma % 10;
        if (Resto1 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
return 0;
}

