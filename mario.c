//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h> //Biblioteca padrão
#include <cs50.h> //Biblioteca para o get_int()

int main(void)
{
    int Altura; //Variável Altura
    do //Do While para o usuário inserir a altura correta
    {
        Altura = get_int("Digite a altura da piramide entre 1 e 8.\n"); //Get_int() com a Altura
    }
    while (Altura < 1 || Altura > 8); //Condição de repetição para o Do While aconteceça caso não insira uma altura correta

    int Y = Altura - 1; //Variável que irá dar o tamanho da impressão dos espaços vazios
    int X = 1; //Varável que irá dar o tamanho da impressão das hashes
    for (int Coluna = 0; Coluna < Altura; Coluna++) //For que vai dar a Altura da piramide
    {
        for (int Linha = 0; Linha < Y; Linha++) //For que vai imprimir os espaços vazios
        {
            printf(" "); //Prinft para imprimir espaços vazios
        }
        Y--; //Y deve ir diminuindo para que os espaços vazios apareçam cada vez menos
        for (int Linha = 0; Linha < X; Linha++) //For que vai imprimir hashes
        {
            printf("#"); //Printf para imprimir hashes
        }
        X++; //X deve ir aumetando para que as hashes apareçam cada vez mais
        printf("\n"); //Printf para pular linha
    }
    return 0;
}