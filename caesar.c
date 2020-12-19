//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int Tamanho;
int Resto;
int Key;
int Retorno;
string teste;

int main(int argc, string argv[])
{
    /*for (int x = 0; argv[x] != (void *)0; x++)
    {
        if (argv[x] < '0' || argv[x] > '9')
        {
            break;
        }
    }*/
    if (argc == 2 && argv[1] == (void *)0)
    {
        Key = atoi(argv[1]);
        string Frase = get_string("plaintext: ");
        Tamanho = strlen(Frase);
        
        for (int Posição = 0; Posição < Tamanho; Posição++)
        {
            if (Frase[Posição] >= 'a' && Frase[Posição] <= 'z')
            {
                Key = atoi(argv[1]);
                Key = Key - (122 - Frase[Posição]);
                if (Key < 0)
                {
                    Frase[Posição] = Frase[Posição] + atoi(argv[1]);
                }
                else
                {
                    Resto = Key % 26;
                    Frase[Posição] = 96 + Resto;
                }
            }
            else if (Frase[Posição] >= 'A' && Frase[Posição] <= 'Z')
            {
                Key = atoi(argv[1]);
                Key = Key - (90 - Frase[Posição]);
                if (Key < 0)
                {
                    Frase[Posição] = Frase[Posição] + atoi(argv[1]);
                }
                else
                {
                    Resto = Key % 26;
                    Frase[Posição] = 64 + Resto;
                }
            }
            else
            {
                Frase[Posição] = Frase[Posição];
            }
        }
        printf("ciphertext: %s\n", Frase);
        Retorno = 0;
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        Retorno = 1;
    }
    return Retorno;
}