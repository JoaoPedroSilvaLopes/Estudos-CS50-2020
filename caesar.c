//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int Key;

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        Key = strlen(argv[1]);
        string Frase = get_string("plaintext: ");
        
        for (int i = 0; i < strlen(Frase); i++)
        {
            if (isalpha(Frase[i]))
            {
                /*Key = strlen(argv[1]);
                Key = Key - ('z' - Frase[i]);
                if (islower(Frase[i]))
                {
                    Frase[i] = Frase[i] + strlen(argv[1]);
                }
                else if
                {
                    Frase[i] = ('a' - 1) + (Key % 26);
                }
                else if (isupper(Frase[i]))
                {
                    Key = strlen(argv[1]);
                    Key = Key - ('Z' - Frase[i]);
                    if (Key < 0)
                    {
                        Frase[i] = Frase[i] + strlen(argv[1]);
                    }
                }
                else
                {
                    Frase[i] = ('A' - 1) + (Key % 26);
                }*/
            }
            else
            {
                printf("Usage: %s\n", argv[0]);
                return 1;
            }
        }
        printf("ciphertext: %s\n", Frase);
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    return 0;
}