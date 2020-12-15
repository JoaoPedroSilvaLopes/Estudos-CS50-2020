//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>

int Tamanho, Palavras, Caractere;
char espaço[] = " ";
char Texto[2000];
int Espaços, Letras, Sentenças = 0;
int L, S, I;

int main(void)
{
    printf("Insira a frase: \n");
    scanf("%s\n", Texto);
    fgets(Texto,2000,stdin);
    Tamanho = strlen(Texto);
    printf("%i\n", Tamanho);

    for (int x = 0; x <= Tamanho; x++)
    {
        if (Texto[x] == ' ')
        {
            Espaços++;
        }
        else if (Texto[x] == '.' || Texto[x] == '!' || Texto[x] == '?')
        {
            Sentenças++;
        }
        else
        {

            Caractere++;
        }
    }
    printf("%i\n", Espaços);
    printf("%i\n", Sentenças);
    printf("%i\n\n", Caractere);
    
    Palavras = Espaços + 2;
    printf("%d\n", Palavras);
    Letras = Caractere + 1;
    printf("%d\n\n", Letras);
    
    L = round((Letras * 100) / Palavras);
    printf("%d\n", L);
    S = round((Sentenças * 100) / Palavras);
    printf("%d\n", S);
    
    I = round(round(0.0588 * L) - round(0.296 * S) - 15.8);
    printf("%d\n", I);
    if (I >= 16)
    {
        printf("Grade +16\n");
    }
    else if (I < 1)
    {
        printf("Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", I);
    }
    
    
    return 0;
}

/*
$$I = 0.0588 * L - 0.296 * S - 15.8$$
L = número médio de letras a cada 100 palavras no texto.
S = média do número de sentenças a cada 100 palavras no texto.
isspace (verifica um espaço em branco)
ispunct (verifica um ponto)
islower (verifica um caractere minúsculo)
isupper (verifica um caractere maiúculo)
isalpha (verifica se o caractere é uma letra do alfabeto)
strlen (verifica o tamanho de uma string)
*/