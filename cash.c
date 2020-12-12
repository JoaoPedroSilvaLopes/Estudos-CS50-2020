//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h> 
#include <cs50.h> //Utilizar o get_float("");.
#include <math.h> //Utilizar round.

int main(void)
{
    float Money; //Variável Money é float para ser trabalhada com números decimais.
    int QuantMoedas[5]; //Vetor QuantMoedas é inteiro para as quantidades de moedas que também são inteiras.
    do
    {
        Money = get_float("Digite o saldo: ");
        printf("\n"); //Printf para pular a linha.
        //QuantMoedas[0] está ligada ao valor da moeda de 25 centavos.
        QuantMoedas[0] = round((Money / 0.25) * 100) / 100; //Foi utilizado round para arredondar para o valor inteiro mais próximo.
        printf("Será preciso %d moeda(as) de 25 centavos.\n\n", QuantMoedas[0]); //Printf para mostrar a quantidade de moedas de 25 centavos necessárias.
        /*
        QuantMoedas[1] Está ligada ao valor da moeda de 10 centavos.
        Foi usado o QuantMoedas[0] para subtrair a variável Money e o resto seria a quantidade
        de moedas de 10 centavos arredondadas para o inteiro mais proximo com round.
        */
        QuantMoedas[1] = round(((Money - QuantMoedas[0] * 0.25) / 0.10) * 100) / 100;
        printf("Será preciso %d moeda(as) de 10 centavos.\n\n", QuantMoedas[1]); //Printf para mostrar a quantidade de moedas de 10 centavos necessárias.
        /*
        QuantMoedas[2] Está ligada ao valor da moeda de 5 centavos.
        Foi usado o QuantMoedas[0] e QuantMoedas[1] para subtrair a variável Money e o resto seria a quantidade
        de moedas de 5 centavos arredondadas para o inteiro mais proximo com round.
        */
        QuantMoedas[2] = round(((Money - QuantMoedas[0] * 0.25 - QuantMoedas[1] * 0.10) / 0.05) * 100) / 100;
        printf("Será preciso %d moeda(as) de 5 centavos.\n\n", QuantMoedas[2]); //Printf para mostrar a quantidade de moedas de 5 centavos necessárias.
        /*
        QuantMoedas[3] Está ligada ao valor da moeda de 1 centavo.
        Foi usado o QuantMoedas[0],QuantMoedas[1] e QuantMoedas[2] para subtrair a variável Money e o resto seria a quantidade
        de moedas de 1 centavo arredondadas para o inteiro mais proximo com round.
        */
        QuantMoedas[3] = round(((Money - QuantMoedas[0] * 0.25 - QuantMoedas[1] * 0.10 - QuantMoedas[2] * 0.05) / 0.01) * 100) / 100;
        printf("Será preciso %d moeda(as) de 1 centavo.\n\n", QuantMoedas[3]); //Printf para mostrar a quantidade de moedas de 1 centavo necessárias.
        //QuantMoedas[4] é a soma de todos os outros vetores para dar o total.
        QuantMoedas[4] = QuantMoedas[0] + QuantMoedas[1] + QuantMoedas[2] + QuantMoedas[3];
        printf("A quantidade total de moedas necessárias são: %d\n", QuantMoedas[4]); //Printf para mostrar a quantidade total de moedas necessárias.
    }
    while (Money <= 0);
    return 0;    
}