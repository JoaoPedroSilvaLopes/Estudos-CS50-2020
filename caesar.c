//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <ctype.h>
#include <math.h>
#include <cs50.h> 
#include <string.h>

int Tamanho;
int Divisão;
int x;

int main (int argc, string argv[])
{
    if (argc == 2)
    {
        printf("Success\n");
        x = 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        x = 1;
    }
    
return x;
}

    /*int Key = get_int("");
    printf("plaintext: ");
    string Frase = get_string("");
    Tamanho = strlen(Frase);;
    
    for(int Posição = 0; Posição < Tamanho; Posição++)
    {
        if (Frase[Posição] != islower(Frase[Posição]) || Frase[Posição] != isupper(Frase[Posição]))
        {
            Divisão = ceil(Key / 26);
                do
                {
                   Key = Key - (122 - Frase[Posição]);
                   printf("%i\n\n", Key);
                   Frase[Posição] = 96;
                   Divisão--;
                }
                while (Divisão + 1 > 0);
                Frase[Posição] = Frase[Posição] - Key + 4;
        }
        else
        {
            Frase[Posição] = Frase[Posição];
        }
    }
    printf("ciphertext: %s\n", Frase);*/