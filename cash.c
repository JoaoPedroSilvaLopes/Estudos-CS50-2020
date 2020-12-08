//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
float Money;
float M;
float N;
float M1;
float N1;
float M2;
float N2;
float M3;
float N3;
float M4;
float N4;
float M5;
float N5;
float M6;
float N6;
float M7;
float N7;
float M8;
float N8;
int QuantMoedas;
int QuantMoedas1;
int QuantMoedas2;
int QuantMoedas3;
int MoedasTotal;
   
   do
   {
      Money = get_double("Digite o saldo: ");
      
      M = round(Money*100);
      N = M/100;
      // ------------------------------
      QuantMoedas = round((N/0.25)*100);
      M1 = (QuantMoedas/100);
      printf("%f\n\n", M1);
      // ------------------------------
      QuantMoedas1 = round(((N - (M1*0.25))/0.10)*100);
      M2 = (QuantMoedas1/100);
      printf("%f\n\n", M2);
      // ------------------------------
      QuantMoedas2 = round(((N - (M1*0.25) - (M2*0.10))/0.05)*100);
      M3 = (QuantMoedas2/100);
      printf("%f\n\n", M3);
      // ------------------------------
      QuantMoedas3 = round(((N - (M1*0.25) - (M2*0.10) - (M3*0.05))/0.01)*100);
      M4 = (QuantMoedas3/100);
      printf("%f\n\n", M4);
      // ------------------------------
      MoedasTotal = M1 + M2 + M3 + M4;
      printf("%d\n", MoedasTotal);
   }
   while(Money <= 0);
    
return 0;    
}