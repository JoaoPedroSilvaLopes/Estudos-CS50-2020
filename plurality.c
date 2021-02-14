#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 //Número máximo de candidatos.

typedef struct //Nome e contagem de votos do candidato
{
    string name;
    int votes;
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
            i--;
        }
        else
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (strcmp(name, candidates[j].name) == 0)
                {
                    candidates[j].votes++;
                    break;
                }
            }
        }
    }

    print_winner(); //Printar o vencedor
}

// Update vote totals given a new vote
bool vote(string name)
{  
    string name2 = "Alice";
    if (strcmp(name, name2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_winner(candidate candidates[i].votes) //Função para printar o vencedor(a/es/as)
{
    int voter_count = get_int("Number of voters: "); //Pedir a quantidade de votos
    for (int i = 0; i < voter_count; i++)
    {
        printf("%i\n", candidates[i].votes);
    }
    return;
}