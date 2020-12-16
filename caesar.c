//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <ctype.h>
#include <cs50.h> 
#include <string.h>

int Tamanho;
char array[100];

int main(void)
{
    int Key = get_int("");
    printf("plaintext: ");
    string Frase = get_string("");
    Tamanho = strlen(Frase);
    
    for(int Posição = 0; Posição < Tamanho; Posição++)
    {
        if ((Frase[Posição] >= 'a' && Frase[Posição] <= 'z') || (Frase[Posição] >= 'A' && Frase[Posição] <= 'Z'))
        {
            //printf("%s\n\n", Frase);
            array[Posição] = (Frase[Posição] + Key);
            
            if ((array[Posição] >= 'a' && array[Posição] <= 'z') || (array[Posição] >= 'A' && array[Posição] <= 'Z'))
            {
                array[Posição] = array[Posição];
                //printf("%s\n\n", array);
            }
            else
            {
                array[Posição] = 'a' + Key - (123 - (Frase[Posição]));
                //printf("%s\n\n", array);
            }
        }
        else
        {
            array[Posição] = Frase[Posição];
        }
    }
    printf("ciphertext: ");
    printf("%s\n", array);

    return 0;
}
//isupper
//islower