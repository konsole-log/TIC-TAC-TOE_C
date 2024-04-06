/*MAIN PROGRAM TO INCLUDE DIFFFERENT C PROGRAMS*/
#include "./logic.h"

int main()
{
    int mode;

    printf("################# WELCOME TO TIC-TAC-TOE #################\n");
    sleep(3);
    printf("Here are some rules for how to give inputs:\n");
    printf("--------------------------------------------\n");
    drawBoard(false);
    printf("Here r specifies row number and c specifies cols number\nto enter your game values\n");
    printf("1. enter row number specified by the game\n");
    printf("2. enter the cols number\n");
    printf("-------------------------------------------\n");
    printf("This game is single and multiplayer.press\n");
    printf("1.player vs computer\n2.Player1 vs Player2\n=>");
    scanf("%d", &mode);
    printf("--------------------------------------------------------------\n");
    sleep(3);

    switch (mode)
    {
    case 1:
        bot();
        break;
    case 2:
        pvp(); // for player vs player
        break;
    default:
        printf("Enter either 1 or 2");
    }
    // TODO:add computer and ask user to play with either computer or with another friend

    return 0;
}
