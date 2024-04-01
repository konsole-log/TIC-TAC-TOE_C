/*MAIN PROGRAM TO INCLUDE DIFFFERENT C PROGRAMS*/
#include "./logic.h"

int main()
{
    char turn, winner, ch;
    char player1[80], player2[80];

    printf("################# WELCOME TO TIC-TAC-TOE #################\n");
    sleep(3);
    printf("Here are some rules for how to give inputs:\n");
    printf("--------------------------------------------\n");
    drawBoard(false);
    printf("Here r specifies row number and c specifies cols number\nto enter your game values\n");
    printf("1. enter row number specified by the game\n");
    printf("2. enter the cols number\n");
    printf("3. boom game will fill that cell for you.\n");
    printf("now you are ready to go and ask a friend to play with you!!!!\n");
    printf("--------------------------------------------------------------\n");
    sleep(3);
    printf("\nletss gooo\n\n");

    // TODO:add computer and ask user to play with either computer or with another friend
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
        switch (winner)
        {
        case p1:
            printf("%s[X] is winner\n", player1);
            break;
        case p2:
            printf("%s[O] is winner\n", player2);
            break;
        default:
            drawBoard(true);

            printf("DRAWWW\n");
        }
        printf("\nDo you want to play another game?y[yes]/n[no]\n=>");
        scanf(" %c", &ch);
        printf("\n-----------------------------------------------\n");
        sleep(1);
        system("clear");
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
