/*FILE THAT HANDLES THE CORE MECHANICS OF GAME*/
#ifdef _WIN32
#define window 0
#include <Windows.h>
#else
#define unix 1
#include <unistd.h>
#endif
#include "./constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char board[3][3] = {"   ",
                    "   ",
                    "   "};
// function prototypes
void drawBoard(int);
void inputPlayer(char, char *, char *);
char checkWinner();
int freespaces();
void resetBoard();
void pvp();
void bot();
void printWinner(char);
void playerMove();

void drawBoard(int n)
{
    int i, j, k;
    switch (n)
    {
    case true:
        if (!unix)
        {
            system("cls");
            break;
        }
        system("clear");
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

void inputPlayer(char turn, char *player1, char *player2)
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
            printf("ERROR!!TRY AGAIN INPUTTING\n");
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
void pvp() // player v player
{
    char turn, winner, ch;

    do
    {
        resetBoard();
        int i = 0;
        winner = ' ';
        printf("Enter player1: ");
        scanf(" %s", player1);
        printf("Enter player2: ");
        scanf(" %s", player2);
        do
        {
            turn = i % 2 == 0 ? p1 : p2;
            drawBoard(true);
            inputPlayer(turn, player1, player2);
            i++;
            winner = checkWinner();
            if (winner != ' ')
            {
                drawBoard(true);
            }
        } while (winner == ' ' && freespaces() != 0);
        fflush(stdin);
        drawBoard(true);
        printWinner(winner);
        printf("\nDo you want to play another game?y[yes]/n[no]\n=>");
        scanf(" %c", &ch);
        printf("\n-----------------------------------------------\n");
        sleep(1);
        system("clear");
        ch = toupper(ch);
    } while (ch == 'y');
}

void computerMove()
{
    srand(time(0));
    int x, y;
    if (freespaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;

        } while (board[x][y] != ' ');
        board[x][y] = p2;
    }
}
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row number(r): ");
        scanf("%d", &x);
        x--;
        printf("Enter cols number(r): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = p1;
            break;
        }
    } while (board[x][y] != ' ');
}
void bot()
{
    char winner = ' ';
    char response = ' ';

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while (winner == ' ' && freespaces() != 0)
        {
            drawBoard(true);

            playerMove();
            winner = checkWinner();
            if (winner != ' ' || freespaces() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || freespaces() == 0)
            {
                break;
            }
        }

        drawBoard(true);
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("Thanks for playing!");
}

void printWinner(char winner)
{
    switch (winner)
    {
    case p1:
        printf("%s[X] is winner\n", player1);
        break;
    case p2:
        printf("%s[O] is winner\n", player2);
        break;
    default:
        printf("DRAWWW\n");
    }
}