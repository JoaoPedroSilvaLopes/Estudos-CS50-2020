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

void record_preferences(int ranks[])
{
    int m = 0;
    int n = 0;

    for (int i = 0; i < candidate_count; i++) // linha da matriz candidatos
    {
        for (int j = 0; j < candidate_count; j++) // coluna da matriz candidatos
        {
            if (candidates[i] != candidates[j]) // se a comparação for de candidatos diferentes
            {
                for (int x = 0; x < candidate_count; x++) // contagem do rank do primeiro candidato
                {
                    if (ranks[x] == i)
                    {
                        m = x;
                    }
                    else if (ranks[x] == j)
                    {
                        n = x;
                    }
                }
                if (m < n) // se m for menor que n, então quer dizer que m é mais preferível que n
                {
                    preferences[i][j]++; // Aumentar a quantidade de preferências
                }
            }
        }
    }

    return;
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++) // Linha da matriz de candidatos
    {
        for (int j = 0; j < candidate_count; j++) // Coluna da matriz de candidatos
        {
            if (preferences[i][j] != preferences[j][i] && preferences[i][j] > preferences[j][i]) // Não pode ser empate e contar o vencedor
            {
                pairs[pair_count].winner = i; // Linkar o i no pairs.winner - mais preferido
                pairs[pair_count].loser = j; // Linkar o j no pairs.loser - menos preferido
                pair_count++; // Aumentar contagem de pares
            }
        }
    }

    return;
}

void sort_pairs(void)
{
    int m; // Variável auxiliar no pairs[].winner
    int n; // Variável auxiliar no pairs[].loser
    int diff[pair_count]; // Array para contar a força de vitória dos pares
    pair_count = 0; // Linkar pair_count a 0 de novo para contar preferences

    for (int i = 0; i < candidate_count; i++) // Linha da matriz de candidatos
    {
        for (int j = 0; j < candidate_count; j++) // Coluna da matriz de candidatos
        {
            if (preferences[i][j] != preferences[j][i] && preferences[i][j] > preferences[j][i])
            {
                diff[pair_count] = preferences[i][j] - preferences[j][i]; // Achar o valor da força de vitória do par
                pair_count++; // Aumentar contagem de pares novamente
            }
        }
    }

    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count - 1; j++)
        {
            if (diff[j] < diff[j + 1]) // Se a força de vitória for menor que a posterior do array
            {
                m = pairs[j].winner; //
                n = pairs[j].loser; //
                pairs[j].winner = pairs[j + 1].winner; //
                pairs[j].loser = pairs[j + 1].loser; //
                pairs[j + 1].winner = m; //
                pairs[j + 1].loser = n; //
            }
        }
    }

    return;
}












void lock_pairs(void)
{
    //int m = preferences[pairs[pair_count - 1].winner][pairs[pair_count - 1].loser] - preferences[pairs[pair_count - 1].loser][pairs[pair_count - 1].winner];

    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }







    for (int i = 0; i < pair_count; i++)
    {
        int n = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        int m = preferences[pairs[i + 1].winner][pairs[i + 1].loser] - preferences[pairs[i + 1].loser][pairs[i + 1].winner];
        int y = preferences[pairs[i - 1].winner][pairs[i - 1].loser] - preferences[pairs[i - 1].loser][pairs[i - 1].winner];
        
        if ((y > n) && (n < m))
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    
    
    
    
    
    
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[pairs[i].winner][pairs[i].loser] == true)
        {
            printf("TRUE: %i - %i\n", pairs[i].winner, pairs[i].loser);
        }
        else
        {
            printf("FALSE: %i - %i\n", pairs[i].winner, pairs[i].loser);
        }
    }
    
    return;
}
















void print_winner(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[pairs[i].winner][pairs[i].loser] == true)
        {
            for (int j = 0; j < pair_count; j++)
            {
                if (locked[pairs[j].winner][pairs[i].winner] == true)
                {
                    locked[pairs[i].winner][pairs[i].loser] = false;
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[pairs[i].winner][pairs[i].loser] == true)
        {
            printf("%s\n", candidates[pairs[i].winner]);
            break;
        }
    }
    
    return;
}