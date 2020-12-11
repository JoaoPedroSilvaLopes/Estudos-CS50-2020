//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int i = 0;
int NS[17];
int Soma[17];
long Resto;
int Resto1;
int Resto2;
int Soma1;
int D;

int main(void)
{
    long NC = get_long("Insira o número do cartão: ");
    
    if ((NC >= 34 * pow(10, 13) && NC < 35 * pow(10, 13)) || (NC >= 37 * pow(10, 13) && NC < 38 * pow(10, 13)))
    {
        for (int z = 14; z >= 0; z--)
        {
            NS[i] = NC / pow(10, z);
            Resto = NC % (long) pow(10, z);
            NC = Resto;
            i++;
        }
        i = 1;
        for(int w = 7; w >= 0; w--)
        {
            D = (NS[i]*2) / 10;
            Resto2 = (NS[i]*2) % 10;
            printf("%i\n", Resto2);
            Soma[i] = D + Resto2;
            printf("%i\n", Soma[i]);
            i = i + 2;
        }
        Soma1 = (Soma[1] + Soma[3] + Soma[5] + Soma[7] + Soma[9] + Soma[11] + Soma[13]) + NS[0] + NS[2] + NS[4] + NS[6] + NS[8] +  NS[10] + NS[12] +  NS[14];
        printf("%i\n", Soma1);
        Resto1 = Soma1 % 10;
        if (Resto1 == 0)
        {
            printf("AMEX\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
    }
    else if (NC >= 51 * pow(10, 14) && NC < 56 * pow(10, 14))
    {
        for (int z = 15; z >= 0; z--)
        {
            NS[i] = NC / pow(10, z);
            Resto = NC % (long) pow(10, z);
            NC = Resto;
            i++;
        }
        for(int w = 8; w >= 0; w--)
        {
            D = (NS[i]*2) / 10;
            Resto2 = (NS[i]*2) % 10;
            printf("%i\n", Resto2);
            Soma[i] = D + Resto2;
            printf("%i\n", Soma[i]);
            i = i + 2;
        }
        Soma1 = (Soma[0] + Soma[2] + Soma[4] + Soma[6] + Soma[8] + Soma[10] + Soma[12] + Soma[14]) + NS[1] + NS[3] + NS[5] + NS[7] + NS[9] +  NS[11] + NS[13] + NS[15];
        printf("%i\n", Soma1);
        Resto1 = Soma1 % 10;
        if (Resto1 == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    else if ((NC >= 4 * (long) pow(10, 12) && NC < 5 * (long) pow(10, 12)) || (NC >= 4 * (long) pow(10, 15) && NC < 5 * (long) pow(10, 15)))
    {
        if (NC < 1 * pow(10, 15))
        {
            for (int z = 15; z >= 0; z--)
            {
                NS[i] = NC / (long) pow(10, z);
                printf("%i\n", NS[i]);
                Resto = NC % (long) pow(10, z);
                printf("%li\n", Resto);
                NC = Resto;
                i++;
            }
            Soma1 = (NS[0]*2 + NS[2]*2 + NS[4]*2 + NS[6]*2 + NS[8]*2 + NS[10]*2 + NS[12]*2 + NS[14]*2) 
                   + NS[1] + NS[3] + NS[5] + NS[7] + NS[9] + NS[11] + NS[13] + NS[15];
            printf("%i\n", Soma1);
            Resto1 = Soma1 % 10;
            if (Resto1 == 0)
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
            for (int z = 12; z >= 0; z--)
            {
                NS[i] = NC / (long) pow(10, z);
                printf("%i\n", NS[i]);
                Resto = NC % (long) pow(10, z);
                printf("%li\n", Resto);
                NC = Resto;
                i++;
            }
            Soma1 = (NS[0]*2 + NS[2]*2 + NS[4]*2 + NS[6]*2 + NS[8]*2 + NS[10]*2 + NS[12]*2) 
                   + NS[1] + NS[3] + NS[5] + NS[7] + NS[9] + NS[11];
            printf("%i\n", Soma1);
            Resto1 = Soma1 % 10;
            if (Resto1 == 0)
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