#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 //Número máximo de candidatos.

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name)) //Checkar um voto inválido.
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner(); //Printar o vencedor.
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    return false;
}

void print_winner(void) //Função para printar o vencedor(a/es/as).
{
    // TODO
    return;
}