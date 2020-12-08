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
      M5 = round(0.25*100);
      N5 = M5/100;
      M6 = round(0.10*100);
      N6 = M6/100;
      M7 = round(0.05*100);
      N7 = M7/100;
      M8 = round(0.01*100);
      N8 = M8/100;
      // ------------------------------
      QuantMoedas = (N/N5);
      M1 = round(QuantMoedas*100);
      printf("%f\n", M1);
      N1 = M1/100;
      printf("%f\n\n", N1);
      // ------------------------------
      QuantMoedas1 = ((N - (N1*N5))/N6);
      M2 = round(QuantMoedas1*100);
      printf("%f\n", M2);
      N2 = M2/100;
      printf("%f\n\n", N2);
      // ------------------------------
      QuantMoedas2 = ((N - (N1*N5) - (N2*N6))/N7);
      M3 = round(QuantMoedas2*100);
      printf("%f\n", M3);
      N3 = M3/100;
      printf("%F\n\n", N3);
      // ------------------------------
      QuantMoedas3 = ((N - (N1*N5) - (N2*N6) - (N3*N7))/N8);
      M4 = round(QuantMoedas3*100);
      printf("%f\n", M4);
      N4 = M4/100;
      printf("%f\n\n", N4);
      // ------------------------------
      MoedasTotal = N1 + N2 + N3 + N4;
      printf("%d\n", MoedasTotal);
   }
   while(Money <= 0);
    
return 0;    
}