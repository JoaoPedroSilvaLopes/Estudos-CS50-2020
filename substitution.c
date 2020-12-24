//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const string Letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int Tamanho;
int Retorno;

int main(int argc, string argv[])
{
    //printf("%d\n", Tamanho);
    
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        Tamanho = strlen(argv[1]);
        if (Tamanho != 26)
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    
    
    
    
    /*int Caracteres [X];
    Número = strlen(argv[1]);

    for (int x = 0; x < Número; x++)
    if (!(isalpha(argv[1][x])))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (isalpha(argv[1][x]))
    {
        argv[1][x] = toupper(argv[1][x]);
    }
    string Texto = get_string("plaintext: ");
    int Y = strlen(Texto);
    char TextoC[Y + 1];
    
    for (int x = 0; x < Y; x++)
    if (isupper(Texto[x]) != 0)
    {
        for (int i = 0; i < X; i++)
        if (Texto[x] == Letras[i])
        {
            TextoC[x] = argv[1][i];
            break;
        }
    }
    else if (islower(Texto[x]) != 0)
    {
        for (int i = 0; i < Y; i++)
        if (Texto[x] == tolower(Letras[i]))
        {
            TextoC[x] = tolower(argv[1][i]);
            break;
        }
    }

    printf("ciphertext: %s\n", TextoC);*/
    
    return 0;
}