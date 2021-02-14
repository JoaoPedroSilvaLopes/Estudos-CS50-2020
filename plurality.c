//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoaoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br
#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 //Número máximo de candidatos.

typedef struct //Nome e contagem de votos do candidato
{
    string name;
    string name2;
    int votes;
    int votes2;
}
candidate;

candidate candidates[MAX]; //Array dos candidatos
int candidate_count; //Número de candidatos
bool vote(string name); //Função vote
void print_winner(void); //Função print_winner

int main(int argc, string argv[]) //Função main
{
    if (argc < 2) //Checkar a iniciaização com a quantidade válida de argumentos.
    {
        printf("Usage: plurality [candidate ...]\n");
        return 0;
    }
    candidate_count = argc - 1; //Contagem de candidatos
    if (candidate_count > MAX) //Se a quantidade de candidatos for maior que 9
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 0; 
    }
    for (int i = 0; i < candidate_count; i++) 
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count = get_int("Number of voters: "); //Pedir a quantidade de votos

    for (int i = 0; i < voter_count; i++) //Loop de todos os votos
    {
        string name = get_string("Vote: "); //Indicar o nome do candidato para o voto

        if (!vote(name)) //Checkar um voto inválido
        {
            printf("Invalid vote.\n");
            i--; // Condição para manter a quantidade de votos caso dê inválido
        }
    }
    print_winner(); //Printar o vencedor
}
bool vote(string name) //Função de updates de votos
{
    for (int i = 0; i < candidate_count; i++)
    {
        string name2 = candidates[i].name;
        if (strcmp(name, name2) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}
void print_winner(void) //Função para printar o vencedor(a/es/as)
{
    int high = candidates[0].votes; // Variável do maior número de votos
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes > high)
        {
            high = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == high) // Condição para pegar qualquer nome de candidato com o maior número
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}