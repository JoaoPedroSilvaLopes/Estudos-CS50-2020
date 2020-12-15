//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> //Utilizar Get_string("");
#include <math.h> //Utilizar Round
#include <string.h>

int Tamanho, I; 
float  L, S, Palavras, Espaços = 0, Letras = 0, Sentenças = 0;

int main(void)
{
    string Texto = get_string("Insira o texto: \n");
    Tamanho = strlen(Texto);
    for (int x = 0; x < Tamanho; x++)
    {
        if (Texto[x] == ' ')
        {
            Espaços++;
        }
        else if (Texto[x] == '.' || Texto[x] == '!' || Texto[x] == '?')
        {
            Sentenças++;
        }
        else if ((Texto[x] >= 'a' && Texto[x] <= 'z') || (Texto[x] >= 'A' && Texto[x] <= 'Z'))
        {
            Letras++;
        }
        else
        {

        }
    }
    Palavras = Espaços + 1;
    L = (Letras * 100) / Palavras;
    S = (Sentenças * 100) / Palavras;
    I = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (I >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (I < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", I);
    }
    
    return 0;
}
