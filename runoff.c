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

int voter_count; // Número de eleitores
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
    return 0;
}

bool vote(int voter, int rank, string name) // Registro de votos para os candidatos não eliminados
{
    // verificação da validez da palavra
    int x = 0; // indice do candidatos digitado
    int z; // indice do total de candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[x].name) == 0)
        {

        }
        else if (i == candidate_count - 1 && !(strcmp(name, candidates[x].name) == 0 ))
        {
            return false;
        }
        else
        {
            x++;
        }
    }
    z = x + 1;
    //printf("%i\n", z);
    //printf("%i\n", x);

    // Descobrir a posição da matriz
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] == 0) // se uma preferencia estive vaga
            {
                for (int y = j; y > 0; y--) // condição;
                {
                    if (preferences[i][y - 1] == z) // se uma preferencia anterior estiver com o mesmo voto
                    {
                        return false; // retornar falso
                    }
                }
                preferences[i][j] = z;
                return true;
            }
        }
    }
return false;
}












void tabulate(void) // Catalogar os votos dos candidatos não eliminados
{
    /*for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i\n", preferences[i][j]);   
        }
    }
    printf("\n\n\n");*/
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            for (int x = 0; x < candidate_count; x++)
            {
                if (j == 0 && preferences[i][j] == (x + 1))
                {
                    if (candidates[x].eliminated == false)
                    {
                        //preferences[i][j] = (x + 1);
                        candidates[x].votes++;
                        //printf("%i\n", candidates[x].votes);
                    }
                    else
                    {
                        for (int y = 0; y < candidate_count; y++)
                        {
                            if (preferences[i][j + 1] == (y + 1) && candidates[y].eliminated == false)
                            {
                                //preferences[i][j] = preferences[i][j + 1];
                                //preferences[i][j + 1] = 0;
                                candidates[y].votes++;
                                //printf("%i\n", candidates[x].votes);
                                break;
                            }
                            /*else if (preferences[i][j + 1] == (y + 1) && candidates[y].eliminated == true)
                            {
                                   
                            }*/
                        }   
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < candidate_count; i++)
    {
        //for (int j = 0; j < candidate_count; j++)
        //{
            printf("%i\n", candidates[i].votes);   
        //}
    }*/
    return;
}














bool print_winner(void) // Printar o vencedor da eleição, caso seja apenas um
{
    int sum = 0;
    int high = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        int nv[i];
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes > high)
            {
                high = candidates[i].votes;
            }
            nv[i] = candidates[i].votes;
            sum = sum + nv[i];
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == high && (high > (sum / 2)))
        {
            fprintf(stdout, "%s\n", candidates[i].name);
            return true;
        }
        else
        {
            break;
        }
    }
    return false;
}

int find_min(void) // Retornar o número minimo de votos e os candidatos restantes
{
    int loss;
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min  && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    loss = min;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == loss && candidates[i].eliminated == false)
        {
            return loss;
        }
    }
    return 0;
}

bool is_tie(int min) // Retornar TRUE se a eleição teve empate com todos os candidatos, retornar FALSO caso o contrário
{
    int n = 0;
    int m = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes == min)
            {
                n++;
                m++;
            }
            else
            {
                n++;
            }
        }
    }
    if (m == n)
    {
        return true;
    }
    return false;
}

void eliminate(int min) // Eliminar o candidato (ou candidatos) em último lugar
{
    int n = 0;
    int m = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            n++;
            m++;
        }
        else
        {
            n++;
        }
    }
    if(n > m)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if(candidates[i].votes == min)
            {
                candidates[i].eliminated = true;    
            }
        }
    }
    return;
}