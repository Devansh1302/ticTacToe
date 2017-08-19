#include "ticTacToeHead.h"
char options[9] = {'1','2','3','4','5','6','7','8','9'};

int main(){

    char playAgain;
    int winner;
    register int i;
    printf("\n\n\n");
    resetboard();
    createboard();


    for (i=0;i<9;i++){
        ((i%2) == 0) ? get_player_one():get_player_two();
        createboard();
        winner = checkwin();
        if(winner != '\0'){
        printf("%c WINSSSSS\n",winner);
        printf("play again\?(y/n)\n");
        scanf(" %c",&playAgain);
        if ((playAgain == 'y') || (playAgain == 'Y')){
            main();
        }else
            exit(0);
        }

        if (i == NUMSQUARE) printf("DRAW\n\nGame made by Devansh");
    }
    return 0;
}
