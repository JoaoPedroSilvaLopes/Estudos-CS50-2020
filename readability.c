//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h> 
#include <cs50.h> //Utilizar Get_string("");
#include <math.h> //Utilizar Round
#include <string.h> //Utilizar strlen();
#include <ctype.h> //Utilizar islower(), isupper() e isspace().

int I, Letras, Sentenças; //Declaração de variáveis inteiras.
float  L, S, Espaços; //Declaração de variáveis decimais.

int main(void)
{
    string Texto = get_string("Insira o texto: \n"); //Get_string("") para inserir o texto a ser analisado.
    for (int i = 0; i < strlen(Texto); i++) //For para contar os caracteres, dividindo-os em letras, espaços e sentenças.
    {
        if (isspace(Texto[i])) //If caso o caractere seja um espaço.
        {
            Espaços++; //Soma +1 a quantidade de espaços.
        }
        else if ((islower(Texto[i])) || (isupper(Texto[i]))) //Else if caso o caractere uma letra maiúscula ou minúscula.
        {
            Letras++; //Soma +1 a quantidade de letras.
        }
        else if (Texto[i] == '.' || Texto[i] == '!' || Texto[i] == '?') //Else if caso o caractere seja uma das pontuações.
        {
            Sentenças++; //Soma +1 a quantidade de senteças.
        }
    }
    L = (Letras * 100) / (Espaços + 1); // L é (letras * 100) / (Espaços + 1), L deve ser float.
    S = (Sentenças * 100) / (Espaços + 1); // S é (Sentenças * 100) / (Espaços +1, S deve ser float.
    I = round((0.0588 * L) - (0.296 * S) - 15.8); // I é um número inteiro com o auxílio de round para dar o inteiro mais próximo.
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