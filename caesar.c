//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> 
#include <string.h>

int Tamanho;
int main(void)
{
    int x = get_int("");
    string Frase = get_string("");
    Tamanho = strlen(Frase);
    
    for(int y = 0; y < Tamanho; y++)
    {
        Frase[y] = Frase[y] + x;
    }
    printf("%s\n", Frase);

    return 0;
}

