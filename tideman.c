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
    int voter_count = get_int("Number of voters: ");

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
    int m;
    int n;
    for (int i = 0; i < candidate_count; i++) // linha da matriz candidatos
    {
        for (int j = 0; j < candidate_count; j++) // coluna da matriz candidatos
        {
            if (candidates[i] != candidates[j]) // se a comparação for de candidatos diferentes
            {
                //printf("%s , %s\n", candidates[i], candidates[j]);
                for (int x = 0; x < candidate_count; x++) // contagem do rank do primeiro candidato
                {
                    if (ranks[x] == i)
                    {
                        m = x;
                    }
                }
                for (int y = 0; y < candidate_count; y++) // contagem do rank do segundo candidato
                {
                    if (ranks[y] == j)
                    {
                        n = y;
                    }
                }
                if (m < n) // se m for menor que n, então quer dizer que m é mais preferível que n
                {
                    preferences[i][j]++; // Aumentar a quantidade de preferências
                }
                printf("%i\n", preferences[i][j]);
            }
        }
    }
    
    return;
}















// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] != preferences[j][i] && preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            /*else if (preferences[i][j] != preferences[j][i] && preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }*/
        }
    }

    printf("%i\n\n", pair_count);

    printf("%i - %i\n\n", pairs[0].winner, pairs[0].loser);
    printf("%i - %i\n\n", pairs[1].winner, pairs[1].loser);
    printf("%i - %i\n\n\n", pairs[2].winner, pairs[2].loser);
    
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    /*int diff[pair_count];
    int org[pair_count];
    int max = 0;
    int m = 0;
    for (int i = 0; i < pair_count; i++)
    {
        diff[i] = pairs[i].winner - pairs[i].loser;  
    }
    
    for (int i = 0; i < pair_count; i++)
    {
        if (diff[i] >= max)
        {
            m++;
            max = diff[i];
        }
    }
    
    if (m == pair_count)
    {
        printf("Empatou, a ordem não importa\n");
    }
    else
    {
        printf("A ordem importa\n");    
    }
    printf("%i\n", diff[0]);
    printf("%i\n", diff[1]);
    printf("%i\n", diff[2]);*/

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

