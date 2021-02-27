#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100 // Max votos
#define MAX_CANDIDATES 9 // Max candidatos

int preferences[MAX_VOTERS][MAX_CANDIDATES]; // preferences[i][j] is j preference for voter i

typedef struct // Candidatos posuem nome, contagem de votos e status de eliminado
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES]; // Array dos candidatos

int voter_count; // Número de votos
int candidate_count; // Número de candidatos

// Funções
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2) // Checka o uso inválido
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    
    candidate_count = argc - 1; // Quantidade dos array dos candidatos
    
    if (candidate_count > MAX_CANDIDATES) // Checka para não exceder a quantidade máxima de candidatos
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++) // Dados do candidato
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    
    voter_count = get_int("Number of voters: "); // Número de eleitores
    
    
    if (voter_count > MAX_VOTERS) // Checka para não exceder a quantidade máxima de eleitores
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++) // Continuar perguntando os votos
    {
        
        for (int j = 0; j < candidate_count; j++) // consulta a classificação dos candidatos
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name)) // receber o votos, ao menos que seja inválido
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }
/*
    while (true) // Continuar usando runoffs até existir um vencedor
    {
        tabulate(); // Calcular os votos dos candidatos restantes
        
        bool won = print_winner(); // Check se a eleição teve um vencedor
        if (won)
        {
            break;
        }

        // Eliminar o(s) último(s) candidato(s)
        int min = find_min();
        bool tie = is_tie(min);

        if (tie) // Se der empate em todos os candidatos
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min); // Eliminar alguém com o número mínimo de votos

        for (int i = 0; i < candidate_count; i++) // Resetar a contagem de votos de volta para zero
        {
            candidates[i].votes = 0;
        }
    }
    return 0*/
}














bool vote(int voter, int rank, string name) // Registro de votos para os candidatos não eliminados
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {  
            if (strcmp(name, candidates[i].name) == 0 && candidates[i].eliminated == false)
            {  
                //preferences[i][j] = *candidates[i].name;
                //printf("%i\n", preferences[0][j]);
                //if (preferences[0][j] == preferences[i][j])
                //{
                    //candidates[i].votes++;
                    //preferences[i][0] = *candidates[i].name;
                    //printf("%i\n", candidates[i].votes);
                    //printf("%s\n", "repetido");
                    //return true;
                //}
                //else
                //{
                    candidates[i].votes++;
                    //preferences[i][0] = *candidates[i].name;
                    printf("%i\n", candidates[i].votes);
                    //printf("%s\n", "repetido");
                    return true;
                //}
            }
            else
            {
                break;
            }
        }
    }
return false;
}










/*
void tabulate(void) // Catalogar os votos dos candidatos não eliminados
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            printf("%s\n", candidates[i].name);
            printf("%i\n", candidates[i].votes);
        }
    }
    return;
}

bool print_winner(void) // Printar o vencedor da eleição, caso seja apenas um
{
    int sum = 0;
    int high;
    for (int i = 0; i < candidate_count; i++)
    {
        int nv[i];
        if (candidates[i].votes > high && candidates[i].eliminated == false)
        {
            high = candidates[i].votes;
            nv[i] = candidates[i].votes;
            sum = sum + nv[i];
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == high && (high > (sum / 2)))
        {
            printf("%s\n", candidates[i].name);
        }
        return true;
    }
    return false;
}

int find_min(void) // Retornar o número minimo de votos e os candidatos restantes
{
    int loss;
    for (int i = 0; i < candidate_count; i++)
    {
        int nv[i];
        if (candidates[i].votes < loss  && candidates[i].eliminated == false)
        {
            loss = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == loss && candidates[i].eliminated == false)
        {
            printf("%d\n", candidates[i].votes);
        }
    }
    return 0;
}

bool is_tie(int min) // Retornar TRUE se a eleição teve empate com todos os candidatos, retornar FALSO caso o contrário
{ 
    int n = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (min == candidates[i].votes)
        {
            n++;        
        }
    }
    if (n == min)
    {
        return true;
    }
    return false;
}

void eliminate(int min) // Eliminar o candidato (ou candidatos) em último lugar
{
    int loss;
    for (int i = 0; i < candidate_count; i++)
    {
        int nv[i];
        if (candidates[i].votes < loss  && candidates[i].eliminated == false)
        {
            loss = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == loss && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}*/