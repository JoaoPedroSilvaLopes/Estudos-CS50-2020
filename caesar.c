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
int Resto; //Resto da divisão entre a Key de contagem dividido por 26.

int main(int argc, string argv[]) //Declaração dos argumentos na função main
{
    if (argc == 2) //If caso a quantidade de argumentos seja igual a 2.
    {
        Key = atoi(argv[1]); //Key é a conversão do argv[1] para inteiro.
        string Frase = get_string("plaintext: "); //Get_string("") para introduzir a frase a ser criptografada.
        Resto = Key % 26;
        
        for (int Posição = 0; Posição < strlen(Frase); Posição++) //For para verificar cada um dos caracteres da string.
        {
            if (Frase[Posição] >= 'a' && Frase[Posição] <= 'z') //If para caso o caractere seja uma letra minúscula.
            {
                Key = atoi(argv[1]);
                Key = Key - ('z' - Frase[Posição]); //Key é a subtração de 'z' - o caractere de Frase[Posição].
                if (Key < 0) //If para caso Key dê menor do que 0.
                {
                    Frase[Posição] = Frase[Posição] + atoi(argv[1]); //O caractere será a soma do próprio caractere + Atoi(argv[1]).
                }
                else //Else para caso Key seja igual ou maior que 0.
                {
                    Frase[Posição] = ('a' - 1) + (Resto); //O caractere será a soma de ('a' - 1) e o Resto.
                }
            }
            else if (Frase[Posição] >= 'A' && Frase[Posição] <= 'Z') //Else if para caso o caractere seja uma letra maiúscula.
            {
                Key = atoi(argv[1]);
                Key = Key - ('Z' - Frase[Posição]); //Key é a subtração de 'Z' - o caractere de Frase[Posição].
                if (Key < 0) //If para caso Key dê menor do que 0.
                {
                    Frase[Posição] = Frase[Posição] + atoi(argv[1]); //O caractere será a soma do próprio caractere + Atoi(argv[1]).
                }
                else //Else para caso Key seja igual ou maior que 0.
                {
                    Frase[Posição] = ('A' - 1) + (Resto); //O caractere será a soma de ('A' - 1) e o Resto.
                }
            }
            else //Else para caso o caractere não seja uma letra.
            {
                Frase[Posição] = Frase[Posição]; //Caso não seja uma letra, o caractere deverá permanecer o mesmo.
            }
        }
        printf("ciphertext: %s\n", Frase); //Printf para imprimir ciphertext: Frase, sendo Frase ja esta criptografada.
        Retorno = 0; //Retorno = 0, indicando que o programa funcionou normalmente.
    }
    else //Else para caso tenha argumentos diferentes de 2.
    {
        printf("Usage: %s\n", argv[0]); //Printf para imprimir Usage: ./caesar, sendo caesar = argv[0];.
        Retorno = 1; //Retorno = 1, diz indicando o erro
    }
    return Retorno; //Retorno.
}