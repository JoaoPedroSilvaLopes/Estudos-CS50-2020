//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int i;
int Divisão;
int Validez;
int SomaTotal;
int SomaAlg[17];
int Algarismo[17];
int RestoAlg;
long Resto;

int main(void)
{
    long NúmeroCartão = get_long("Insira o número do cartão: ");
    
    if ((NúmeroCartão >= 34 * pow(10, 13) && NúmeroCartão < 35 * pow(10, 13)) || (NúmeroCartão >= 37 * pow(10, 13) && NúmeroCartão < 38 * pow(10, 13)))
    {
        for (int z = 14; z >= 0; z--)
        {
            Algarismo[i] = NúmeroCartão / pow(10, z);
            Resto = NúmeroCartão % (long) pow(10, z);
            NúmeroCartão = Resto;
            i++;
        }
        i = 1;
        for (int w = 7; w >= 0; w--)
        {
            Divisão = (Algarismo[i] * 2) / 10;
            RestoAlg = (Algarismo[i] * 2) % 10;
            SomaAlg[i] = Divisão + RestoAlg;
            i = i + 2;
        }
        SomaTotal = (SomaAlg[1] + SomaAlg[3] + SomaAlg[5] + SomaAlg[7] + SomaAlg[9] + SomaAlg[11] + SomaAlg[13]) 
                + Algarismo[0] + Algarismo[2] + Algarismo[4] + Algarismo[6] + Algarismo[8] + Algarismo[10] + Algarismo[12] + Algarismo[14];
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
            Algarismo[i] = NúmeroCartão / pow(10, z);
            Resto = NúmeroCartão % (long) pow(10, z);
            NúmeroCartão = Resto;
            i++;
        }
        i = 0;
        for (int w = 8; w >= 0; w--)
        {
            Divisão = (Algarismo[i] * 2) / 10;
            RestoAlg = (Algarismo[i] * 2) % 10;
            SomaAlg[i] = Divisão + RestoAlg;
            i = i + 2;
        }
        SomaTotal = (SomaAlg[0] + SomaAlg[2] + SomaAlg[4] + SomaAlg[6] + SomaAlg[8] + SomaAlg[10] + SomaAlg[12] + SomaAlg[14]) 
                + Algarismo[1] + Algarismo[3] + Algarismo[5] + Algarismo[7] + Algarismo[9] +  Algarismo[11] + Algarismo[13] + Algarismo[15];
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
                Algarismo[i] = NúmeroCartão / pow(10, z);
                Resto = NúmeroCartão % (long) pow(10, z);
                NúmeroCartão = Resto;
                i++;
            }
            i = 0;
            for (int w = 8; w >= 0; w--)
            {
                Divisão = (Algarismo[i] * 2) / 10;
                RestoAlg = (Algarismo[i] * 2) % 10;
                SomaAlg[i] = Divisão + RestoAlg;
                i = i + 2;;
            }
            SomaTotal = (SomaAlg[0] + SomaAlg[2] + SomaAlg[4] + SomaAlg[6] + SomaAlg[8] + SomaAlg[10] + SomaAlg[12] + SomaAlg[14]) 
                    + Algarismo[1] + Algarismo[3] + Algarismo[5] + Algarismo[7] + Algarismo[9] + Algarismo[11] + Algarismo[13] + Algarismo[15];
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
                Algarismo[i] = NúmeroCartão / pow(10, z);
                Resto = NúmeroCartão % (long) pow(10, z);
                NúmeroCartão = Resto;
                i++;
            }
            i = 1;
            for (int w = 6; w >= 0; w--)
            {
                Divisão = (Algarismo[i] * 2) / 10;
                RestoAlg = (Algarismo[i] * 2) % 10;
                SomaAlg[i] = Divisão + RestoAlg;
                i = i + 2;
            }
            SomaTotal = (SomaAlg[1] + SomaAlg[3] + SomaAlg[5] + SomaAlg[7] + SomaAlg[9] + SomaAlg[11]) 
                    + Algarismo[0] + Algarismo[2] + Algarismo[4] + Algarismo[6] + Algarismo[8] + Algarismo[10] + Algarismo[12];
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