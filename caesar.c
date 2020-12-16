//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> 
#include <string.h>
#include <math.h>

int z;
int Tamanho;
int main()
{
    int x = get_int("");
    if ( x >= 1)
    {
        z = 0;
        printf("OK");
    }
    else
    {
        z = 1;
        printf("Uga");
    }


    return z;
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
*/