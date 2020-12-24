//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void Substituir();
void Letras(char z, string chave);

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
            Substituir(argv[1]);
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
    return 0;    
}
void Substituir(string chave)
{
    string x = get_string("plaintext: ");
    printf("ciphertext: ");
    printf("\n");
        
    for (int i = 0; i < strlen(x); i++)
    {
        if (isalpha(x[i]))
        {
            char y = x[i];
            if (islower(x[i]))
            {
                Letras(tolower(y), chave);
            }
            else
            {
                Letras(toupper(y), chave);
            }
        }
        else
        {
            printf("%c", x[i]);
        }
    }
}
void Letras(char z, string chave)
{
    string Alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
    for (int i = 0; i < strlen(Alfabeto); i++)
    {
        if (islower(z))
        {
            if (z == tolower(Alfabeto[i]))
            {
                printf("%c", tolower(chave[i]));
            }
        }
        else
        {
            if (z == toupper(Alfabeto[i]))
            {
                printf("%c", toupper(chave[i]));
            }
        }
    }
}