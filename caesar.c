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
int Resto;
int Key;
int y;

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int x = get_int("");
        string Frase = get_string("plaintext: ");
        Tamanho = strlen(Frase);
        
        for (int Posição = 0; Posição < Tamanho; Posição++)
        {
            if (Frase[Posição] >= 'a' && Frase[Posição] <= 'z')
            {
                Key = x;
                Key = Key - (122 - Frase[Posição]);
                if (Key < 0)
                {
                    Frase[Posição] = Frase[Posição] + x;
                }
                else
                {
                    Resto = Key % 26;
                    Frase[Posição] = 96 + Resto;
                }
            }
            else if (Frase[Posição] >= 'A' && Frase[Posição] <= 'Z')
            {
                Key = x;
                Key = Key - (90 - Frase[Posição]);
                if (Key < 0)
                {
                    Frase[Posição] = Frase[Posição] + x;
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
        y = 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        y = 1;
    }
    return y;
}