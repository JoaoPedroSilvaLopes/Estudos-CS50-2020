//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int i;
int NS[17];
long Resto;
int Resto2;
int Divisão;
int Validez;
int SomaTotal;
int SomaAlg[17];

int main(void)
{
    long NúmeroCartão = get_long("Insira o número do cartão: ");
    
    if ((NúmeroCartão >= 34 * pow(10, 13) && NúmeroCartão < 35 * pow(10, 13)) || (NúmeroCartão >= 37 * pow(10, 13) && NúmeroCartão < 38 * pow(10, 13)))
    {
        for (int z = 14; z >= 0; z--)
        {
            NS[i] = NúmeroCartão / pow(10, z);
            Resto = NúmeroCartão % (long) pow(10, z);
            NúmeroCartão = Resto;
            i++;
        }
        i = 1;
        for (int w = 7; w >= 0; w--)
        {
            Divisão = (NS[i] * 2) / 10;
            Resto2 = (NS[i] * 2) % 10;
            SomaAlg[i] = Divisão + Resto2;
            i = i + 2;
        }
        SomaTotal = (SomaAlg[1] + SomaAlg[3] + SomaAlg[5] + SomaAlg[7] + SomaAlg[9] + SomaAlg[11] + SomaAlg[13]) 
                + NS[0] + NS[2] + NS[4] + NS[6] + NS[8] + NS[10] + NS[12] + NS[14];
        Validez = SomaTotal % 10;
        if (Validez == 0)
        {
            printf("AMEX\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
    }
    else if (NúmeroCartão >= 51 * pow(10, 14) && NúmeroCartão < 56 * pow(10, 14))
    {
        for (int z = 15; z >= 0; z--)
        {
            NS[i] = NúmeroCartão / pow(10, z);
            Resto = NúmeroCartão % (long) pow(10, z);
            NúmeroCartão = Resto;
            i++;
        }
        i = 0;
        for (int w = 8; w >= 0; w--)
        {
            Divisão = (NS[i] * 2) / 10;
            Resto2 = (NS[i] * 2) % 10;
            SomaAlg[i] = Divisão + Resto2;
            i = i + 2;
        }
        SomaTotal = (SomaAlg[0] + SomaAlg[2] + SomaAlg[4] + SomaAlg[6] + SomaAlg[8] + SomaAlg[10] + SomaAlg[12] + SomaAlg[14]) 
                + NS[1] + NS[3] + NS[5] + NS[7] + NS[9] +  NS[11] + NS[13] + NS[15];
        Validez = SomaTotal % 10;
        if (Validez == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((NúmeroCartão >= 4 * pow(10, 12) && NúmeroCartão < 5 * pow(10, 12)) || 
             (NúmeroCartão >= 4 * pow(10, 15) && NúmeroCartão < 5 * pow(10, 15)))
    {
        if (NúmeroCartão > 1 * pow(10, 15))
        {
            for (int z = 15; z >= 0; z--)
            {
                NS[i] = NúmeroCartão / pow(10, z);
                Resto = NúmeroCartão % (long) pow(10, z);
                NúmeroCartão = Resto;
                i++;
            }
            i = 0;
            for (int w = 8; w >= 0; w--)
            {
                Divisão = (NS[i] * 2) / 10;
                Resto2 = (NS[i] * 2) % 10;
                SomaAlg[i] = Divisão + Resto2;
                i = i + 2;;
            }
            SomaTotal = (SomaAlg[0] + SomaAlg[2] + SomaAlg[4] + SomaAlg[6] + SomaAlg[8] + SomaAlg[10] + SomaAlg[12] + SomaAlg[14]) 
                    + NS[1] + NS[3] + NS[5] + NS[7] + NS[9] + NS[11] + NS[13] + NS[15];
            Validez = SomaTotal % 10;
            if (Validez == 0)
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
                NS[i] = NúmeroCartão / pow(10, z);
                Resto = NúmeroCartão % (long) pow(10, z);
                NúmeroCartão = Resto;
                i++;
            }
            i = 1;
            for (int w = 6; w >= 0; w--)
            {
                Divisão = (NS[i] * 2) / 10;
                Resto2 = (NS[i] * 2) % 10;
                SomaAlg[i] = Divisão + Resto2;
                i = i + 2;
            }
            SomaTotal = (SomaAlg[1] + SomaAlg[3] + SomaAlg[5] + SomaAlg[7] + SomaAlg[9] + SomaAlg[11]) 
                    + NS[0] + NS[2] + NS[4] + NS[6] + NS[8] + NS[10] + NS[12];
            Validez = SomaTotal % 10;
            if (Validez == 0)
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