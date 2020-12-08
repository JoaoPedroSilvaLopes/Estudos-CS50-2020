#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int Money;
   do
   {
      Money = get_float("Digite o saldo:"); 
   }
   while(Money <= 0);
    
return 0;    
}