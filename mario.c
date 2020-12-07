//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h> //Biblioteca padrã
#include <cs50.h> //Biblioteca para o get_int()

int main(void)
{
    int Altura; //Variável Altura
    do //Do While para o usuário inserir a altura correta
    {
        Altura = get_int("Digite a altura da piramide entre 1 e 8.\n"); //Get_int() com a Altura
    }
    while (Altura < 1 || Altura > 8); //Condição de repetição para o Do While aconteceça caso não insira uma altura correta

    int Y = Altura - 1; //Variável que irá dar o tamanho da impressão dos espaços vazios da primeira piramide
    int X1 = 1; //Variável que irá dar o tamanho da impressão das hashes da primeira piramide
    int X2 = 1; //Variável que irá dar o tamanho da impressão das hashes da segunda piramide
    for (int Coluna = 0; Coluna < Altura; Coluna++) //For que vai dar a Altura da piramide
    {
        for (int Linha = 0; Linha < Y; Linha++) //For que vai imprimir os espaços vazios da primeira piramide
        {
            printf(" "); //Prinft para imprimir espaços vazios da primeira piramide
        }
        Y--; //Y deve ir diminuindo para que os espaços vazios apareçam cada vez menos na primeira piramide
        for (int Linha = 0; Linha < X1; Linha++) //For que vai imprimir hashes da primeira piramide
        {
            printf("#"); //Printf para imprimir hashes da primeira piramide
        }
        X1++;  //X1 deve ir aumetando para que as hashes apareçam cada vez mais na primeira piramide
        printf("  "); //Printf de dois espaços para a construção da segunda piramide
        for (int Linha = 0; Linha < X2; Linha++) //For que vai imprimir hashes da segunda piramide
        {
            printf("#"); //Printf para imprimir hashes da segunda piramide
        }
        X2++; //X2 deve ir aumentando para que as hashes apareçam cada vez mais na segunda piramide, mas alinhados à esquerda
        printf("\n"); //Printf para pular linha
    }
    return 0;
}