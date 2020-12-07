//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h>
#include <cs50.h> //Biblioteca para o get_int()

int main(void)
{
    int Altura;
    do
    {
        Altura = get_int("Digite a altura da piramide entre 1 e 8.\n");
    }
    while (Altura < 1 || Altura > 8);

    int Y = Altura - 1;
    int X1 = 1;
    int X2 = 1;
    for (int Coluna = 0; Coluna < Altura; Coluna++)
    {
      for (int Linha = 0; Linha < Y; Linha++)
      {
          printf(" ");
      }
      Y--;
      for (int Linha = 0; Linha < X1; Linha++)
      {
          printf("#");
      }
      X1++;
      printf("\n");
    }
    return 0;
}