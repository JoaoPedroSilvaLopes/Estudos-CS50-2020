//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> //Utilizar Get_string("");
#include <math.h> //Utilizar Round
#include <string.h> //Utilizar strlen();
#include <ctype.h>

int Tamanho, I, Espaços = 0, Letras = 0, Sentenças = 0; //Declaração de variáveis inteiras.
float  L, S, Palavras; //Declaração de variáveis decimais.

int main(void)
{
    string Texto = get_string("Insira o texto: \n"); //Get_string("") para inserir o texto a ser analisado.
    Tamanho = strlen(Texto); //Tamanho é a contagem de caracteres do texto, que foi contado com strlen();.
    for (int x = 0; x < Tamanho; x++) //For para contar os caracteres, dividindo-os em letras, espaços e sentenças.
    {
        //If caso o caractere seja um espaço.
        if (Texto[x] == ' ') 
        {
            Espaços++; //Soma +1 a quantidade de espaços.
        }
        //Else if caso o caractere seja uma das pontuações.
        else if (ispunct(Texto[x])) 
        {
            Sentenças++; //Soma +1 a quantidade de senteças.
        }
        //Else if caso o caractere uma letra maiúscula ou minúscula.
        else if ((islower(Texto[x])) || (isupper(Texto[x]))) 
        {
            Letras++; //Soma +1 a quantidade de letras.
        }
        //Else para caso o caractere não seja nenhum dos casos acima.
        else
        {
            //Não deve acontecer nada nesse caso.
        }
    }
    //Números de palavras é o números de espaços +1, depois do último espaço certamente terá uma palavra.
    Palavras = Espaços + 1; 
    // L é (letras * 100) / palavras, palavras é float para o resultado não ser arredondado para inteiro.
    L = (Letras * 100) / Palavras;
    // S é (Sentenças * 100) / palavras, palavras é float para o resultado não ser arredondado para inteiro.
    S = (Sentenças * 100) / Palavras;
    // I é um número inteiro com o auxílio de round para dar o inteiro mais próximo do o arrondamento ser mais preciso.
    I = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (I >= 16) //If caso I seja maior ou igual a 16 como foi pedido.
    {
        printf("Grade 16+\n"); //Caso dê maior ou igual a 16 imprimirá Grade 16+.
    }
    else if (I < 1) //Else if caso I seja menor que 1 como foi pedido.
    {
        printf("Before Grade 1\n"); //Caso dê menor que 1 imprimirá Before grade 1.
    }
    else //Else caso o I não seja nenhum outro caso.
    {
        printf("Grade %i\n", I); //Irá imprimir o próprio resultado da fórmula.
    }
    
    return 0;
}