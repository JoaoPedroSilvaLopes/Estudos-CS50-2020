//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <stdlib.h>
#include <cs50.h> 
#include <string.h>
#include <math.h>

int z, x;
int Tamanho;
int main()
{
    scanf("%i\n", &x);
    if ( x >= 1)
    {
        z = 0;
        printf("OK\n");
    }
    else
    {
        z = 1;
        printf("Usage: ./caesar key");
    }


    return z;
    exit(1);
}


/*int x = get_int("");
    string Frase = get_string("");
    Tamanho = strlen(Frase);
    
    for(int y = 0; y < Tamanho; y++)
    {
        if((Frase[y] >= 'a' && Frase[y] <= 'z') || (Frase[y] >= 'A' && Frase[y] <= 'Z'))
        {
            Frase[y] = Frase[y] + x;
        }
        else
        {
            
        }
    }
    printf("%s\n", Frase);
    //plaintext:
    //ciphertext:
*/