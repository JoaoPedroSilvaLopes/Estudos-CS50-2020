//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h> //Utilizar get_long("");
#include <math.h> //Utilizar pow;

int i;
int Divisão;
int Validez;
int SomaTotal;
int SomaAlg[17];
int Algarismo[17];
int RestoAlg;
long Sobra;

int main(void)
{
    //Get_long para garantir qua não será digitado letras ou caracteres especiais.
    long NúmeroCartão = get_long("Insira o número do cartão: ");
    
    //Condição para verificar se o cartão é AMEX.
    if ((NúmeroCartão >= 34 * pow(10, 13) && NúmeroCartão < 35 * pow(10, 13)) || 
        (NúmeroCartão >= 37 * pow(10, 13) && NúmeroCartão < 38 * pow(10, 13)))
    {
        for (int z = 14; z >= 0; z--) //For para quebrar o número do cartão em algarismos únicos.
        {
            Algarismo[i] = NúmeroCartão / pow(10, z); //Algarismo[i] é o número do cartão dividido por 10^Z.
            Sobra = NúmeroCartão % (long) pow(10, z); //Sobra é o resto da divisão entre NúmeroCartão e 10^Z.
            NúmeroCartão = Sobra; //NúmeroCartão se torna a sobra, para garantir que as casas decimais irem diminuindo até 10^0.
            i++; //i deve ir aumentando para garantir que os algarismos sejam alocados em diferentes posições do vetor Algarismo[i].
        }
        i = 1; //i = 1, pois a quantidade de algarismos no número do cartão é ímpar.
        //For para fazer a multiplicação dos algarismos alternados e somar os algarismos dos números multiplicados caso tenha 2 casa decimais.
        for (int w = 7; w >= 0; w--) 
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
        SomaTotal = (SomaAlg[1] + SomaAlg[3] + SomaAlg[5] + SomaAlg[7] + SomaAlg[9] + SomaAlg[11] + SomaAlg[13]) 
                    + Algarismo[0] + Algarismo[2] + Algarismo[4] + Algarismo[6] + Algarismo[8] + Algarismo[10] + Algarismo[12] + Algarismo[14]; 
        //Validez é o resto da divisão entre SomaTotal e 10, serve para validar se o número do cartão é de fato valido ou não.
        Validez = SomaTotal % 10; 
        if (Validez == 0) //Caso o resto da divisão seja 0, o número do cartão é válido.
        {
            printf("AMEX\n"); //Printf para mostrar o tipo do cartão.
        }
        
        else //Caso o resto da divisão não seja 0, o número do cartão é inválido.
        {
            printf("INVALID\n"); //Printf para mostrar que o cartão é inválido.
        }
    }
    //Condição para verificar se o cartão é MASTERCARD.
    else if (NúmeroCartão >= 51 * pow(10, 14) && NúmeroCartão < 56 * pow(10, 14))
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
    }
    else if ((NúmeroCartão >= 4 * pow(10, 12) && NúmeroCartão < 5 * pow(10, 12)) || 
             (NúmeroCartão >= 4 * pow(10, 15) && NúmeroCartão < 5 * pow(10, 15))) //Condição para verificar se o cartão é VISA.
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
    }   
    else //Else caso nenhum número inserido satisfaça as condições dos cartões AMEX, MASTERCARD e VISA.
    {
        printf("INVALID\n"); //Printf para mostrar que o cartão é inválido.
    }
    
    return 0;
}