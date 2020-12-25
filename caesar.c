//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

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
            Frase[i] = Frase[i] + 1;
        }
        else if (isupper(Frase[i]))
        {
            Frase[i] = Frase[i] + 1;
        }
        else
        {
            Frase[i] = Frase[i];
        }
    }
    printf("ciphertext: %s\n", Frase);
    return 0;
}