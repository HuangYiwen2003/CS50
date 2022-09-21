#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int score[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");
    int score1 = 0, score2 = 0;
    int index;
    for (int i = 0; player1[i] != '\0'; i++)
    {
        if (player1[i] >= 'a' && player1[i] <= 'z')
        {

            index = player1[i] - 'a';
            score1 = score1 + score[index];
        }
        else if (player1[i] >= 'A' && player1[i] <= 'Z')
        {

            index = player1[i] - 'A';
            score1 = score1 + score[index];
        }
    }
    for (int i = 0; player2[i] != '\0'; i++)
    {
        if (player2[i] >= 'a' && player2[i] <= 'z')
        {

            index = player2[i] - 'a';
            score2 = score2 + score[index];
        }
        else if (player2[i] >= 'A' && player2[i] <= 'Z')
        {

            index = player2[i] - 'A';
            score2 = score2 + score[index];
        }
    }
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}