//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int d;

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: %s\n", argv[0]);
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    string Frase = get_string("plaintext: ");
    for (int i = 0; i < strlen(Frase); i++)
    {
        if (islower(Frase[i]))
        {
            d = atoi(argv[1]) - (122 - Frase[i]);
            if (d < 0)
            {
                Frase[i] = Frase[i] + atoi(argv[1]);
            }
            else
            {
                Frase[i] = 96 + (d % 26);
            }
        }
        else if (isupper(Frase[i]))
        {
            d = atoi(argv[1]) - (95 - Frase[i]);
            if (d < 0)
            {
                Frase[i] = Frase[i] + atoi(argv[1]);
            }
            else
            {
                Frase[i] = 64 + (d % 26);
            }
        }
    }
    printf("ciphertext: %s\n", Frase);
    return 0;
}