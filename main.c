/*MAIN PROGRAM TO INCLUDE DIFFFERENT C PROGRAMS*/
#include "./logic.h"

int main() {
  char turn, winner, ch;

  printf(
      "\n~~~~~~~~~~~~~~~~~~~~~~ WELCOME TO TIC-TAC-TOE ~~~~~~~~~~~~~~~~~~~~~~\n");
  sleep(2);
  printf("Here are some rules for how to give inputs:\n");
  printf("+-----------------------------------------------------------+\n");
  drawBoard(false);
  printf("Here r specifies row number and c specifies cols number\nto enter "
         "your game values\n");
  printf("1. enter row number specified by the game\n");
  printf("2. enter the cols number\n");
  printf("3. Game will fill that cell for you.\n");
  printf("now you are ready to go and ask a friend to play with you!!!!\n");
  printf("+------------------------------------------------------------+\n");
  sleep(3);
  printf("\nletss gooo\n\n");

  do {
    resetBoard();
    int i = 0;
    winner = ' ';
    printf("Enter player1: ");
    scanf(" %s", player1);
    printf("Enter player2: ");
    scanf(" %s", player2);

    do {
      turn = i % 2 == 0 ? p1 : p2;
      drawBoard(true);
      inputPlayer(turn, player1, player2);
      i++;
      winner = checkWinner();
      if (winner != ' ') {
        drawBoard(true);
      }
    } while (winner == ' ' && freespaces() != 0);

    fflush(stdin);
    switch (winner) {
            case p1:
                //can add leaderboard functionality here
                printf("\t\t%s[X] is winner\n", player1);
                break;
            case p2:
                printf("\t\t%s[O] is winner\n", player2);
                break;
            default:
                drawBoard(true);
                printf("\t\tDRAWWW\n");
    }

    printf("\n\t\tDo you want to play another game?y[yes]/n[no]\n=>");
    scanf(" %c", &ch);
    printf("\n-----------------------------------------------\n");
    sleep(1);
    if (!unix) {
      system("cls");
    } else {
      system("clear");
    }
  } while (ch == 'y' || ch == 'Y');
  return 0;
}
