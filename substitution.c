//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string Alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                if (!(isalpha(argv[1][i])))
                {
                    printf("Usage: %s\n", argv[0]);
                    return 1;
                }
                for (int j = i + 1; j < strlen(argv[1]); j++)
                {
                    if ((toupper(argv[1][j])) == (toupper(argv[1][i])))
                    {
                        printf("Usage: %s\n", argv[0]);
                        return 1;
                    }
                }
            }
        }
        else
        {
            printf("Usage: %s\n", argv[0]);
            return 1;
        }
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    string Frase = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(Frase); i++)
    {
        if (isalpha(Frase[i]))
        {
            char Letras = Frase[i];
            if (islower(Frase[i]))
            {
                for (int j = 0; j < strlen(Alfabeto); j++)
                {
                    if (Letras == tolower(Alfabeto[j]))
                    {
                        printf("%c", tolower(argv[1][j]));
                    }
                }
            }
            else
            {
                for (int j = 0; j < strlen(Alfabeto); j++)
                {
                    if (Letras == toupper(Alfabeto[j]))
                    {
                        printf("%c", toupper(argv[1][j]));
                    }
                }
            }
        }
        else
        {
            printf("%c", Frase[i]);
        }
    }
    
    printf("OLA");
    return 0;    
}