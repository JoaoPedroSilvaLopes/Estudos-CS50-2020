//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <stdio.h>
#include <cs50.h>

char NúmeroCartão[0];
int z;
int Resto;
int x = 10;
int y = 3;

int main(void)
{
    for(z = 0; 0 < 15; z++)
    {
    NúmeroCartão[z] = get_int("Insira o número do cartão: ");
    printf("%s", NúmeroCartão);
    }

   if (NúmeroCartão[0] == 5 && NúmeroCartão[1] > 0 && NúmeroCartão[1] < 6)
   {
       x = NúmeroCartão[0]*2 + NúmeroCartão[2]*2 + NúmeroCartão[4]*2 + NúmeroCartão[6]*2 + NúmeroCartão[8]*2 + NúmeroCartão[10]*2 + NúmeroCartão[12]*2 + NúmeroCartão[14]*2 + NúmeroCartão[1] + NúmeroCartão[3] + NúmeroCartão[5] + NúmeroCartão[7] + NúmeroCartão[9] + NúmeroCartão[11] + NúmeroCartão[13] + NúmeroCartão[15];
       Resto = x % y;
       if(Resto == 0)
       {
          printf("AMERICANEXPRESS\n");
       }
       else
       {
           printf("INVALID\n");
       }
   }
/*
   }
   else if (x1 = 3 & x2 = 4 || x2 = 7)
   {
       if(x1.2 + x3.2 + x5.2 + x7.2 + x9.2 + x11.2 + x13.2 + x15.2 =
       {
          printf("MASTERCARD\n");
       }
       else
       {
           printf("INVALID\n");
   }
   else if (x1 = 4)
   {
       if(x1.2 + x3.2 + x5.2 + x7.2 + x9.2 + x11.2 + x13.2 + x15.2 =
       {
          printf("VISA\n");
       }
       else
       {
           printf("INVALID\n");
   }
   */
   
   //Resto = x % y;
   //printf("%i\n", Resto);

return 0;
}