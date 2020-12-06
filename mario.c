#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int Altura;
    do
    {
        Altura = get_int("Digite a altura da piramide entre 1 e 8.\n");
    }
    while(Altura < 1 || Altura > 8);

            for (int Coluna = 1; Coluna <= Altura; Coluna++)
            {
                for (int Linha = (Altura - Coluna); Linha > 0; Linha--)
                {
                    printf(" ");
                }
                for (int Linha = 0; Linha < Coluna; Linha++)
                {
                    printf("#");
                }
                printf("  ");
                for (int Linha = 0; Linha < Coluna; Linha++)
                {
                    printf("#");
                }
                printf("\n");
            }
return 0;
}