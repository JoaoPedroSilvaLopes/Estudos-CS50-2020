//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void) //Usei o mesmo código do Mario Less, mas com algumas alterações.
{
    int SomadorHorizontal1, SomadorHorizontal2, SubtratorHorizontal, Resposta; //Declaração de variáveis.

    do //Do while foi utilizado para repetir para o usuário o procedimento de construção da piramide caso o mesmo queira ou caso tenha errado e queria fazer certo.
    {
        int AlturaPiramide = get_int("Digite a altura da piramide entre 1 e 8.\n"); //Pergunta para o usuário a altura da piramide.
        printf("%i", AlturaPiramide);
        system("clear || cls"); //Comando de limpar a tela.
        SubtratorHorizontal = AlturaPiramide - 1;
        SomadorHorizontal1 = 1;
        SomadorHorizontal2 = 1;
        
        if (AlturaPiramide >= 1 && AlturaPiramide <= 8) //If que varia de acordo com a escolha do usuário.
        {
            printf("A altura escolhida para a piramide foi: %i ...estamos construindo...\n\n", AlturaPiramide); //Prinft para mostrar a altura escolhida.

            for (int Coluna = 0; Coluna < AlturaPiramide; Coluna++) //Laço For utilizado para determinar a altura da piramide.
            {
                for (int Linha = 0; Linha < SubtratorHorizontal; Linha++)
                {
                    printf(" "); //Printf para imprimir os espaços vazios da piramide.
                }
                for (int Linha = 0; Linha < SomadorHorizontal1; Linha++)
                {
                    printf("#"); //Printf para imprimir as hashes da primeira piramide.
                }
                SomadorHorizontal1 = SomadorHorizontal1 + 1; //SomadorHorizontal deve aumentar, imprimir hashes e ficar alinhado à direita.
                SubtratorHorizontal = SubtratorHorizontal - 1; //SubtratorHorizontal deve diminuir e imprimir espaços vazios.
                printf(" "); //Printf para fazer o espaçamento entre as duas piramides.
                for (int Linha = 0; Linha < SomadorHorizontal2; Linha++)
                {
                    printf("#"); //Printf para imprimir as hashes da segunda piramide.
                }
                printf("\n"); //Printf para quebrar a linha.
                system("sleep 0.5"); //delay na construção da piramide pra ficar legal KAKAKA.
                SomadorHorizontal2 = SomadorHorizontal2 + 1; //SomadorHorizontal2 deve aumentar, imprimir hashes e ficar alinhado à esquerda.
            }
            printf("\nDeseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione qualquer outra tecla.\n"); //Pergunta para o usuário se o mesmo quer repetir o processo.
            scanf("%i", &Resposta); //Resposta do usuário.
            system("clear || cls");
        }
        else //Else para as alturas inválidas.
        {
            printf("Não foi inserido uma altura válida.\nDeseja escolher a altura novamente? Se sim pressione 1, se deseja sair pressione qualquer outra tecla.\n");
            scanf("%i", &Resposta);
            system("clear || cls");
        }
    }
    while (Resposta == 1); //Condição para que a repetição continue.
    return 0;
}