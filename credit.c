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
            return 1;
        }
    }
    //------------------------------------------------------------------------
    if ((NC[0] == '3' && NC[1] == '7') || (NC[0] == '3' && NC[1] == '7'))
    {
        for (int j = 0; j < strlen(NC); j++)
        {
            S = j % 2;
            if (S != 0)
            {
                D[j] = (2 * NC[j]) / 10;
                printf("%i\n", NC[1]);
                if (D > 0)
                {
                    D[j] = D[j] + ((2 * NC[j]) % 10);
                }
            }
        }
        Soma = D[1] + D[3] + D[5] + D[7] + D[9] + D[11] + D[13];
        printf("%i\n", Soma);
        if (Soma % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    //-----------------------------------------------------------------------------------
    /*//Condição para verificar se o cartão é MASTERCARD.
    else if (NC[0] == 5 && (NC[1] == 1 || NC[1] == 2 || NC[1] == 3 || NC[1] == 4 || NC[1] == 5))
    {
        for (int z = 15; z >= 0; z--) //For para quebrar o número do cartão em algarismos únicos.
        {
            Algarismo[i] = NC / pow(10, z); //Algarismo[i] é o número do cartão dividido por 10^Z.
            Sobra = NC % (long) pow(10, z); //Sobra é o resto da divisão entre NúmeroCartão e 10^Z.
            NC = Sobra; //NúmeroCartão se torna a sobra, para garantir que as casas decimais irem diminuindo até 10^0.
            i++; //i deve ir aumentando para garantir que os algarismos sejam alocados em diferentes posições do vetor Algarismo[i].
        }
        i = 0; //i = 0, pois a quantidade de algarismos no número do cartão é par.
        //For para fazer a multiplicação dos algarismos alternados e somar os algarismos dos números multiplicados caso tenha 2 casa decimais.
        for (int w = 8; w >= 0; w--)
        {
            //Divisão é a divisão de Algarismo[i] por 10 para ter o número da 2 casa decimal caso for necessário.
            Divisão = (Algarismo[i] * 2) / 10;
            //RestoAlg é o resto da divisão de Algarismo[i] por 10 para ter o valor da primeira casa decimal caso for necessário.
            RestoAlg = (Algarismo[i] * 2) % 10;
            //SomaAlg[i] é a soma das variáveis anteriores que representa a soma da segunda e primeira casa decimal do Algarismo[i].
            SomaAlg[i] = Divisão + RestoAlg; 
            //i deve ser igual a i + 2 para garantir que os números utilizado será alternados.
            i = i + 2; 
        }
        //SomaTotal é a soma de todas as posições do vetor SomaAlg[i] e o que sobrou do vetor Algarimo[i].
        SomaTotal = (SomaAlg[0] + SomaAlg[2] + SomaAlg[4] + SomaAlg[6] + SomaAlg[8] + SomaAlg[10] + SomaAlg[12] + SomaAlg[14]) 
                    + Algarismo[1] + Algarismo[3] + Algarismo[5] + Algarismo[7] + Algarismo[9] +  Algarismo[11] + Algarismo[13] + Algarismo[15];
        //Validez é o resto da divisão entre SomaTotal e 10, serve para validar se o número do cartão é de fato valido ou não.
        Validez = SomaTotal % 10; 
        if (Validez == 0) //Caso o resto da divisão seja 0, o número do cartão é válido.
        {
            printf("MASTERCARD\n"); //Printf para mostrar o tipo do cartão.
        }
        else //Caso o resto da divisão não seja 0, o número do cartão é inválido.
        {
            printf("INVALID\n"); //Printf para mostrar que o cartão é inválido.
        }
    }*/
    /*else if (NC[0] == 4) //Condição para verificar se o cartão é VISA.
    {
        if (NúmeroCartão > 1 * pow(10, 15)) //If para caso o cartão VISA tenha 16 números.
        {
            for (int z = 15; z >= 0; z--) //For para quebrar o número do cartão em algarismos únicos.
            {
                Algarismo[i] = NúmeroCartão / pow(10, z); //Algarismo[i] é o número do cartão dividido por 10^Z.
                Sobra = NúmeroCartão % (long) pow(10, z); //Sobra é o resto da divisão entre NúmeroCartão e 10^Z.
                NúmeroCartão = Sobra; //NúmeroCartão se torna a sobra, para garantir que as casas decimais irem diminuindo até 10^0.
                i++; //i deve ir aumentando para garantir que os algarismos sejam alocados em diferentes posições do vetor Algarismo[i].
            }
            i = 0; //i = 0, pois a quantidade de algarismos no número do cartão é par.
            //For para fazer a multiplicação dos algarismos alternados e somar os algarismos dos números multiplicados caso tenha 2 casa decimais.
            for (int w = 8; w >= 0; w--) 
            {
                //Divisão é a divisão de Algarismo[i] por 10 para ter o número da 2 casa decimal caso for necessário.
                Divisão = (Algarismo[i] * 2) / 10;
                //RestoAlg é o resto da divisão de Algarismo[i] por 10 para ter o valor da primeira casa decimal caso for necessário.
                RestoAlg = (Algarismo[i] * 2) % 10;
                //SomaAlg[i] é a soma das variáveis anteriores que representa a soma da segunda e primeira casa decimal do Algarismo[i].
                SomaAlg[i] = Divisão + RestoAlg; 
                //i deve ser igual a i + 2 para garantir que os números utilizado será alternados.
                i = i + 2;; 
            }
            //SomaTotal é a soma de todas as posições do vetor SomaAlg[i] e o que sobrou do vetor Algarimo[i].
            SomaTotal = (SomaAlg[0] + SomaAlg[2] + SomaAlg[4] + SomaAlg[6] + SomaAlg[8] + SomaAlg[10] + SomaAlg[12] + SomaAlg[14]) 
                        + Algarismo[1] + Algarismo[3] + Algarismo[5] + Algarismo[7] + Algarismo[9] + Algarismo[11] + Algarismo[13] + Algarismo[15];
            //Validez é o resto da divisão entre SomaTotal e 10, serve para validar se o número do cartão é de fato valido ou não.
            Validez = SomaTotal % 10; 
            if (Validez == 0) //Caso o resto da divisão seja 0, o número do cartão é válido.
            {
                printf("VISA\n"); //Printf para mostrar o tipo do cartão.
            }
            else //Caso o resto da divisão não seja 0, o número do cartão é inválido.
            {
                printf("INVALID\n"); //Printf para mostrar que o cartão é inválido.
            }
        }
        else //Else para caso o cartão VISA tenha 13 número.
        {
            for (int z = 12; z >= 0; z--) //For para quebrar o número do cartão em algarismos únicos.
            {
                Algarismo[i] = NúmeroCartão / pow(10, z); //Algarismo[i] é o número do cartão dividido por 10^Z.
                Sobra = NúmeroCartão % (long) pow(10, z); //Sobra é o resto da divisão entre NúmeroCartão e 10^Z.
                NúmeroCartão = Sobra; //NúmeroCartão se torna a sobra, para garantir que as casas decimais irem diminuindo até 10^0.
                i++; //i deve ir aumentando para garantir que os algarismos sejam alocados em diferentes posições do vetor Algarismo[i].
            }
            i = 1; //i = 1, pois a quantidade de algarismos no número do cartão é ímpar.
            //For para fazer a multiplicação dos algarismos alternados e somar os algarismos dos números multiplicados caso tenha 2 casa decimais.
            for (int w = 6; w >= 0; w--) 
            {
                //Divisão é a divisão de Algarismo[i] por 10 para ter o número da 2 casa decimal caso for necessário.
                Divisão = (Algarismo[i] * 2) / 10;
                //RestoAlg é o resto da divisão de Algarismo[i] por 10 para ter o valor da primeira casa decimal caso for necessário.
                RestoAlg = (Algarismo[i] * 2) % 10; 
                //SomaAlg[i] é a soma das variáveis anteriores que representa a soma da segunda e primeira casa decimal do Algarismo[i].
                SomaAlg[i] = Divisão + RestoAlg; 
                //i deve ser igual a i + 2 para garantir que os números utilizado será alternados.
                i = i + 2; 
            }
            //SomaTotal é a soma de todas as posições do vetor SomaAlg[i] e o que sobrou do vetor Algarimo[i].
            SomaTotal = (SomaAlg[1] + SomaAlg[3] + SomaAlg[5] + SomaAlg[7] + SomaAlg[9] + SomaAlg[11]) 
                        + Algarismo[0] + Algarismo[2] + Algarismo[4] + Algarismo[6] + Algarismo[8] + Algarismo[10] + Algarismo[12];
            //Validez é o resto da divisão entre SomaTotal e 10, serve para validar se o número do cartão é de fato valido ou não.
            Validez = SomaTotal % 10; 
            if (Validez == 0) //Caso o resto da divisão seja 0, o número do cartão é válido.
            {
                printf("VISA\n"); //Printf para mostrar o tipo do cartão.
            }
            else //Caso o resto da divisão não seja 0, o número do cartão é inválido.
            {
                printf("INVALID\n");  //Printf para mostrar que o cartão é inválido.
            }
        }
    }*/   
    /*else //Else caso nenhum número inserido satisfaça as condições dos cartões AMEX, MASTERCARD e VISA.
    {
        printf("INVALID\n"); //Printf para mostrar que o cartão é inválido.
    }*/
    
    return 0;
}