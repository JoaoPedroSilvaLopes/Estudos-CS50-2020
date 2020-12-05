#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int SomadorHorizontal1, SomadorHorizontal2, SubtratorHorizontal;
    int Resposta = 1;
    
    while (Resposta == 1)
    {
        int AlturaPiramide = get_int("Digite a altura da piramide entre 1 e 8.\n");
        
        if (AlturaPiramide > 0 && AlturaPiramide < 9)
        {
            SubtratorHorizontal = AlturaPiramide - 1;
            SomadorHorizontal1 = 1;
            SomadorHorizontal2 = 1;
            printf("A altura escolhida para a piramide foi: %i ...estamos construindo...\n\n", AlturaPiramide);
            for (int Coluna = 0; Coluna < AlturaPiramide; Coluna++)
            {
                for (int Linha = 0; Linha < SubtratorHorizontal; Linha++)
                {
                    printf(" ");
                }
                SubtratorHorizontal--;
                for (int Linha = 0; Linha < SomadorHorizontal1; Linha++)
                {
                    printf("#");
                }
                SomadorHorizontal1++;
                printf("  ");
                for (int Linha = 0; Linha < SomadorHorizontal2; Linha++)
                {
                    printf("#");
                }
                SomadorHorizontal2++;
                printf("\n"); 
            }
            printf("\nDeseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione qualquer outra tecla.\n");
            scanf("%i", &Resposta); 
        }
        else
        {
            printf("Não foi inserido uma altura válida. Deseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione qualquer outra tecla.\n");
            scanf("%i", &Resposta);
        }
    }
    return 0;
}