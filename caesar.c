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
            if (isdigit(argv[1][i]))
            {
                string Frase = get_string("plaintext: ");
                for (int j = 0; j < strlen(Frase); j++)
                {
                    if (islower(Frase[j]))
                    {
                        Frase[j] = Frase[j];
                    }
                    else if (isupper(Frase[j]))
                    {
                        Frase[j] = Frase[j];
                    }
                    else
                    {
                        Frase[j] = Frase[j];
                    }
                }
                printf("%s\n", Frase);
            }
            else
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
    return 0;
}