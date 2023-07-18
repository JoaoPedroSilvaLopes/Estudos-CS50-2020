//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

/* Olá professor, estou entregando a atividade um pouco atrasado 
por imprevístos nestes últimos dias que saíram do meu controle. 
Mas eu entendo se não aceitar. Na dúvida... ta feito.*/

#include <stdio.h> 
#include <cs50.h> //Get_string("");.
#include <string.h> //Usar strlen.
#include <ctype.h> //Usar isalpha, islower, isupper, tolower, toupper.

string Alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //String com todo o alfabeto.

int main(int argc, string argv[]) //Argumentos.
{
    if (argc == 2) //A quantidade de argumentos deve ser 2.
    {
        if (strlen(argv[1]) == 26) //Tamanho do argv[1] (chave) deve ser 26.
        {
            for (int i = 0; i < strlen(argv[1]); i++) //For para verificar todos os caracteres da chave são válidos.
            {
                if (!(isalpha(argv[1][i]))) //If caso o algum elemento do argv[1] seja diferente de uma letra do alfabeto.
                {
                    printf("Usage: %s\n", argv[0]); //Mensagem decorrente do erro.
                    return 1; //Return 1 para dar o erro.
                }
                for (int j = i + 1; j < strlen(argv[1]); j++) //j deve ser i + 1 para verificar o caractere posterior e ver se tem repetição.
                {
                    if ((toupper(argv[1][j])) == (toupper(argv[1][i]))) //If para verificar se não há nenhuma letra repetida.
                    {
                        printf("Usage: %s\n", argv[0]); //Mensagem decorrente do erro.
                        return 1; //Return 1 para dar o erro.
                    }
                }
            }
        }
        else //Else caso o tamanho não seja do argv[1] seja diferente de 26.
        {
            printf("Usage: %s\n", argv[0]); //Mensagem decorrente do erro.
            return 1; //Return 1 para dar o erro.
        }
    }
    else //Else caso a quantidade de argumentos seja diferente de 2.
    {
        printf("Usage: %s\n", argv[0]); //Mensagem decorrente do erro.
        return 1; //Return 1 para dar o erro.
    }
    string Frase = get_string("plaintext: "); //Get_string para receber a frase a ser substituída.
    printf("ciphertext: "); //Printf para imprimir ciphertext.
    
    for (int i = 0; i < strlen(Frase); i++) //For para que a quantidade de substituições não passará do tamanho da string "Frase".
    {
        if (isalpha(Frase[i])) //Caso a Frase seja letras do alfabeto.
        {
            char Letras = Frase[i]; //Letras é equivalente ao Frase[i], ambos são char.
            if (islower(Frase[i])) //Caso o caractere seja minúsculo.
            {
                for (int j = 0; j < strlen(Alfabeto); j++) //For para verificar "Letras" com as 26 letras do alfabeto da string "Alfabeto".
                {
                    if (Letras == tolower(Alfabeto[j])) //Caso Letras seja minúscula.
                    {
                        printf("%c", tolower(argv[1][j])); //Printf para imprimir o caractere equivalente no argv[1][i] e substituir Frase[i].
                    }
                }
            }
            else //Caso o caractere seja maiúsculo.
            {
                for (int j = 0; j < strlen(Alfabeto); j++) //For para verificar "Letras" com as 26 letras do alfabeto da string "Alfabeto".
                {
                    if (Letras == toupper(Alfabeto[j])) //Caso Letras seja maiúscula.
                    {
                        printf("%c", toupper(argv[1][j])); //Printf para imprimir o caractere equivalente no argv[1][i] e substituir Frase[i].
                    }
                }
            }
        }
        else //Caso o caractere da Frase não seja uma letra do alfabeto.
        {
            printf("%c", Frase[i]); //Printf para imprimir o caractere sem substituição, afinal só letras serão substituídas.
        }
    }
    printf("\n"); //Printf para pular a linha no final do texto substituído.
    return 0;
}