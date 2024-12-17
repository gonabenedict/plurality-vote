
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char name[50];
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char* name);
void print_winner(void);

int main(int argc, char* argv[])
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
       strcpy( candidates[i].name , argv[i + 1]);
        candidates[i].votes = 0;
    }

    int voter_count = 0;
    printf("Number of voters:");
    scanf("%i",&voter_count);


    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[50];
        printf("vote:");
        scanf("%s",name);
        vote(name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char* name)
{
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name , name)==0)
        {
            candidates[i].votes+=1;
         return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count ; i++){
        for (int j= 0 ; j < (candidate_count-1) ; j++){
            if(candidates[j].votes>candidates[j+1].votes){
                candidate temp = candidates[j];
                candidates[j]= candidates[j+1];
                candidates[j+1]= temp;
            }
        }
    }
    if(candidates[candidate_count-1].votes>candidates[candidate_count-2].votes){
        printf("the winner is %s",candidates[candidate_count-1].name);
    }
    else if(candidates[candidate_count-1].votes==candidates[candidate_count-2].votes){
        printf("tie");
    }
}