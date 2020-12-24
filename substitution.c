//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int const X = 26;
const string Letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int Número;
int x;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    
    int Caracteres [X];
    Número = strlen(argv[1]);
    
    for (int v = 0; v < Número; v++)
    if (!(isalpha(argv[1][x])))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (isalpha(argv[1][v]))
    {
        argv[1][v] = toupper(argv[1][v]);
    }
    
    
    for (int y = 0; y < X; y++)
    if (argv[1][x] == Caracteres[y])
    {
        printf("Usage: %s key\n", argv[0]);
    }
    Caracteres[x] = argv[1][x];
    
    string Texto = get_string("plaintext: ");
    int Y = strlen(Texto);
    char TextoC[Y + 1];
    
    for (int w = 0; w < Y; w++)
    if (isupper(Texto[w]) != 0)
    {
        for (int i = 0; i < X; i++)
        if (Texto[w] == Letras[i])
        {
            TextoC[w] = argv[1][i];
            break;
        }
    }
    else if (islower(Texto[w]) != 0)
    {
        for (int i = 0; i < Y; i++)
        if (Texto[w] == tolower(Letras[i]))
        {
            TextoC[w] = tolower(argv[1][i]);
            break;
        }
    }

    printf("ciphertext: %s\n", TextoC);
    
    return 0;
}