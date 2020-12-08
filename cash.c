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
    int QuantMoedas;
    int QuantMoedas1;
    int QuantMoedas2;
    int QuantMoedas3;
    int MoedasTotal;
    do
    {
        Money = get_float("Digite o saldo: ");
        // ------------------------------
        QuantMoedas = round((Money / 0.25) * 100) / 100;
        printf("Será preciso %d moeda(as) de 25 centavos.\n\n", QuantMoedas);
        // ------------------------------
        QuantMoedas1 = round(((Money - QuantMoedas * 0.25) / 0.10) * 100) / 100;
        printf("Será preciso %d moeda(as) de 10 centavos.\n\n", QuantMoedas1);
        // ------------------------------
        QuantMoedas2 = round(((Money - QuantMoedas * 0.25 - QuantMoedas1 * 0.10) / 0.05) * 100) / 100;
        printf("Será preciso %d moeda(as) de 5 centavos.\n\n", QuantMoedas2);
        // ------------------------------
        QuantMoedas3 = round(((Money - QuantMoedas * 0.25 - QuantMoedas1 * 0.10 - QuantMoedas2 * 0.05) / 0.01) * 100) / 100;
        printf("Será preciso %d moeda(as) de 1 centavo.\n\n", QuantMoedas3);
        // ------------------------------
        MoedasTotal = QuantMoedas + QuantMoedas1 + QuantMoedas2 + QuantMoedas3;
        printf("%d\n", MoedasTotal);
    }
    while (Money <= 0);
    return 0;    
}