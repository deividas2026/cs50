#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

void calculate_score(char *player_input, int *player_score, const int points[]);
void print_winner(int player_1_score, int player_2_score);

int main(void)
{
    const int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int player_1_score = 0;
    int player_2_score = 0;

    char *player_1_input = get_string("Player 1: ");
    char *player_2_input = get_string("Player 2: ");

    calculate_score(player_1_input, &player_1_score, points);
    calculate_score(player_2_input, &player_2_score, points);
    print_winner(player_1_score, player_2_score);

    return 0;
}

void calculate_score(char *player_input, int *player_score, const int points[])
{ 
    int i = 0;
    while (player_input[i] != '\0')
    {
        if ( !isalpha(player_input[i]) )
        {
            i++;
            continue;
        }

        int point_index = toupper(player_input[i]) - 'A';
        *player_score += points[point_index];
        i++;
    }
}

void print_winner(int player_1_score, int player_2_score)
{
    if (player_1_score > player_2_score)
        printf("Player 1 wins!\n");
    else if (player_2_score > player_1_score)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}
