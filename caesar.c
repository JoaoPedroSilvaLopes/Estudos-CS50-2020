//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> //Usar get_string("");
#include <string.h> //Usar strlen();
#include <stdlib.h> //Usar atoi();

int Key; //Key de contagem
int Retorno; //Variável de retorno;

int main(int argc, string argv[]) //Declaração dos argumentos na função main
{
    if (argc == 2)
    {
        Key = atoi(argv[1]);
        string Frase = get_string("plaintext: ");
        
        for (int Posição = 0; Posição < strlen(Frase); Posição++)
        {
            if (Frase[Posição] >= 'a' && Frase[Posição] <= 'z')
            {
                Key = atoi(argv[1]);
                Key = Key - (122 - Frase[Posição]);
                if (Key < 0)
                {
                    Frase[Posição] = Frase[Posição] + atoi(argv[1]);
                }
                else
                {
                    Frase[Posição] = 96 + (Key % 26);
                }
            }
            else if (Frase[Posição] >= 'A' && Frase[Posição] <= 'Z')
            {
                Key = atoi(argv[1]);
                Key = Key - (90 - Frase[Posição]);
                if (Key < 0)
                {
                    Frase[Posição] = Frase[Posição] + atoi(argv[1]);
                }
                else
                {
                    Frase[Posição] = 64 + (Key % 26);
                }
            }
            else
            {
                Frase[Posição] = Frase[Posição];
            }
        }
        printf("ciphertext: %s\n", Frase);
        Retorno = 0;
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        Retorno = 1;
    }
    return Retorno;
}