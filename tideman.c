//MATRÍCULA: 20201045050643
//NOME: João Pedro Silva Lopes
//USUÁRIO: JoãoPedroSilvaLopes
//EMAIL INSTITUCIONAL: joao.pedro.silva06@aluno.ifce.edu.br

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 // Max candidatos

int preferences[MAX][MAX]; // É o numero de votos que preferem o i ao invés de j

bool locked[MAX][MAX]; // Mostra se existe uma seta apontando do i para o j

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array dos candidatos
string candidates[MAX]; 
pair pairs[MAX * (MAX - 1) / 2];

int pair_count; // Número de pares
int candidate_count; // Número de candidatos
int voter_count;

// Funções
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2) // Checka o uso inválido
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1; // Quantidade dos candidatos
    
    if (candidate_count > MAX) // Checka para não exceder a quantidade máxima de candidatos
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++) //Disposição dos candidatos no array candidates[i]
    {
        candidates[i] = argv[i + 1];
    }
    
    for (int i = 0; i < candidate_count; i++) // Limpar o grafico dos pares
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    /*int*/ voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++) // Continuar perguntando os votos
    {
        int ranks[candidate_count]; // ranks[j] é o voto de jth preferencia
        
        for (int j = 0; j < candidate_count; j++) // Consultar cada rank
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}










// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = ranks[j];
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

