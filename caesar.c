//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <ctype.h>
#include <cs50.h> 
#include <string.h>

int Tamanho;
int Resto;
int x = 0;
char c = 'a';
char C = 'A';

int main(void)
{

    int Key = get_int("");
    printf("plaintext: ");
    string Frase = get_string("");
    Tamanho = strlen(Frase);;
    
    for(int Posição = 0; Posição < Tamanho; Posição++)
    {
        if (Frase[Posição] != islower(Frase[Posição]) || Frase[Posição] != isupper(Frase[Posição]))
        {
            Frase[Posição] = Frase[Posição] + (Key % 26);
        }
        else
        {
            Frase[Posição] = Frase[Posição];
        }
    }
    printf("ciphertext: %s\n", Frase);
    return 0;
}