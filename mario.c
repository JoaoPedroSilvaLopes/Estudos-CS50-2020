//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void) // Usei o mesmo código do Mario Less, mas com algumas alterações, desta forma na haveria necessidade de mudar os comentários, somente adicionar alguns novos.
{
    int SomadorHorizontal1, SomadorHorizontal2, SubtratorHorizontal, AlturaPiramide, Resposta; // Declaração de variáveis.

    do // Do while foi utilizado para repetir para o usuário o procedimento de construção da piramide caso o mesmo queira ou caso tenha errado e queria fazer certo.
    {
        printf("Digite a altura da piramide\n"); // Pergunta para o usuário a altura da piramide.
        scanf("%i", &AlturaPiramide); // Resposta do usuário.
        system("clear || cls"); // Comando de limpar a tela, tanto para o windows quanto para o linux.
        SubtratorHorizontal = AlturaPiramide - 1;
        SomadorHorizontal1 = 1;
        SomadorHorizontal2 = 1;

        if (AlturaPiramide >= 1 && AlturaPiramide <= 8) // If que varia de acordo com a escolha do usuário.
        {
            /*
            Foi utilizado um laço for para a formação das duas piramides,a primeira piramide foi feita com o auxilio das variáveis
            SomadorHorizontal1 e SubtratorHorizontal, já segunda piramide foi feita com o SomadorHorizontal2,
            tambem vale-se salientar que a forma que o laço For foi utilizado é extremamente similar ao método de 
            alimentação de matrizes, pois no final de contas essa piramide nada mais é que uma matriz quadrada 
            de tamanho X, mas com alguns locais dela sendo imprimidos um espaço em vazio dando o formato de piramide.
            */
            printf("A altura escolhida para a piramide foi: %i", AlturaPiramide); // Prinft para mostrar a altura escolhida.
            printf("... estamos construindo ...\n"); // Prinft para mostrar uma mensagem com FRU FRU.

            for (int Coluna = 0; Coluna < AlturaPiramide; Coluna++) // Laço For utilizado para determinar a altura da piramide.
            {
                for (int Linha = 0; Linha < SubtratorHorizontal; Linha++)
                {
                    printf(" "); // Printf para imprimir os espaços vazios da piramide.
                }
                for (int Linha = 0; Linha < SomadorHorizontal1; Linha++)
                {
                    printf("#"); // Printf para imprimir as hashes da primeira piramide.
                }
                SomadorHorizontal1 = SomadorHorizontal1 + 1; // SomadorHorizontal deve aumentar, imprimir hashes e ficar alinhado à direita.
                SubtratorHorizontal = SubtratorHorizontal - 1; // SubtratorHorizontal deve diminuir e imprimir espaços vazios.
                printf(" "); // Printf para fazer o espaçamento entre as duas piramides.
                for (int Linha = 0; Linha < SomadorHorizontal2; Linha++)
                {
                    printf("#"); // Printf para imprimir as hashes da segunda piramide.
                }
                printf("\n"); // printf para quebrar a linha quando um ciclo se encerrar.
                SomadorHorizontal2 = SomadorHorizontal2 + 1; // SomadorHorizontal2 deve aumentar, imprimir hashes e ficar alinhado à esquerda.
                system("sleep 0.5"); // delay na construção da piramide pra ficar legal KAKAKA.
            }
            printf("Deseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione 2.\n"); // Pergunta para o usuário se o mesmo quer repetir o processo. Está em todos os ifs, else ifs e elses.
            scanf("%i", &Resposta); // Resposta do usuário. Está em todos os ifs, else ifs e elses.
            system("clear || cls"); // Comando de limpar a tela. Está em todos os ifs, else ifs e elses.
        }
        else if (AlturaPiramide == 0) // Esse else if é para caso a variável AlturaPiramide for igual a 0.
        {
            printf("Não foi construido nada, afinal, a altura que foi colocada foi 0. tenta de novo.\n");
            printf("Deseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione 2.\n");
            scanf("%i", &Resposta);
            system("clear || cls");
        }
        else if (AlturaPiramide < 0) // Esse else if é para caso a variável AlturaPiramide for menor que 0.
        { 
            printf("Hey, isso não faz sentido. Faz de novo e dessa vez com números positivos.\n");
            printf("Deseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione 2.\n");
            scanf("%i", &Resposta);
            system("clear || cls");
        }
        else if (AlturaPiramide > 8) // Esse else if é para caso a variável AlturaPiramide for maior que 8.
        {
            printf("Acho que você exagerou demais... vamos tentar de novo.\n");
            printf("Deseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione 2.\n");
            scanf("%i", &Resposta);
            system("clear || cls");
        }
        else // Esse else é para caso a variável AlturaPiramide não seja um número inteiro.
        {
            printf("Você nao digitou um número inteiro...");
            printf("Deseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione 2.\n");
            scanf("%i", &Resposta);
            system("clear || cls");
        } 
      
    }
    while (Resposta == 1); // Condição para que a repetição continue, caso o contrário o programa finaliza.
    system("pause");
    return 0;
}

