#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int Resposta = 1;
    
    while (Resposta == 1)
    {
        int Altura = get_int("Digite a altura da piramide entre 1 e 8.\n");

        if (Altura > 0 && Altura < 9) 
        {
            int Y = Altura - 1;
            int X = 1;
            printf("A altura escolhida para a piramide foi: %i ...estamos construindo...\n\n", Altura); 

            for (int Coluna = 0; Coluna < Altura; Coluna++) 
            {
                for (int Linha = 0; Linha < Y; Linha++)
                {
                    printf(" "); 
                }
                Y--;
                for (int Linha = 0; Linha < X; Linha++)
                {
                    printf("#");
                }
                X++;
                printf("\n"); 
                
            }
            printf("\nDeseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione 2.\n"); 
            scanf("%i", &Resposta); 
        }
        else
        {
            printf("Não foi inserido uma altura válida.\nDeseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione 2.\n");
            scanf("%i", &Resposta);
        }
    }
    return 0;
}
