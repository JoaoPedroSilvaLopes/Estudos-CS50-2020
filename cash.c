//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h>
#include <cs50.h>

int main(void)
{
   float Money;
   float Moedas;
   int Y;
   int Y1;
   int Y2;
   int Y3;
   float Money1;
   float Money2;
   float Money3;
   
   do
   {
       
       
      Money = get_float("Digite o saldo: ");
      
      Y = Money/0.25;
      
      Money1 = Money - (Y*0.25);
      
      Y1 = Money1/0.10;
      
      Money2 = Money1 - (Y1*0.10);
      
      Y2 = Money2/0.05;
      
      Money3 = Money2 - (Y2*0.05);
      
      Y3 = Money3/0.01;
      
      Moedas = Y + Y1 + Y2 + Y3;
      printf("%f\n", Moedas);
      
   }
   while(Money <= 0);
    
return 0;    
}