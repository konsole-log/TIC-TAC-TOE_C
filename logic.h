/*FILE THAT HANDLES THE CORE MECHANICS OF GAME*/
#include "./constants.h"
#include <stdio.h>
#include <stdlib.h>

// TODO:add a computer logic and add whether a winner is computer or player
char board[3][3] = {"   ",
                    "   ",
                    "   "};
void drawBoard(int n)
{
    int i, j, k;
    switch (n)
    {
    case true:
        system("clear");
        break;
    case false:
        break;
    }

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            for (k = 0; k < 3; k++)
            {
                if (k == 0)
                {
                    printf("    c%d", k + 1);
                }
                else
                {
                    printf("   c%d", k + 1);
                }
            }
            printf("\n   -------------\n");
        }
        printf("r%d |", i + 1);
        for (j = 0; j < 3; j++)
        {

            if (j != 2)
            {
                printf(" %c |", board[i][j]);
            }
            else
            {
                printf(" %c |", board[i][j]);
            }
        }
        if (i != 2)
        {
            printf("\n    ---|---|----\n");
        }
        else
        {
            printf("\n   -------------\n\n");
        }
    }
}

void inputPlayer(char turn, char player1[80], char player2[80])
{
    int r, c;
    do
    {
        if (turn == p1)
        {
            printf("%s[X] turn\n", player1);
        }
        else
        {
            printf("%s[O] turn\n", player2);
        }
        printf("Enter row number(r): ");
        scanf("%d", &r);
        r--;
        printf("Enter cols number(c): ");
        scanf("%d", &c);
        c--;
        if (board[r][c] != ' ')
        {
            printf("there is player already\n\n");
        }
        else
        {
            board[r][c] = turn;
            break;
        }
    } while (board[r][c] != ' ');
}

char checkWinner()
{
    int i, j;

    // checking rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // checking cols
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // checking diagnols
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

int freespaces()
{
    int i, j;
    int freespaces = 9;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}

void resetBoard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
