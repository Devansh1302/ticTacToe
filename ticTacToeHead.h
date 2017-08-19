#include<stdio.h>
#include<stdlib.h>
#define ONE 49
#define NUMSQUARE 8
extern char options[9];

char checkwin();
void createboard();
void get_player_one ();
void get_player_two ();
void resetboard();

void createboard(){

    int i, j;
    for( j = 0; j < 3; j++){
    for (i = 0; i < 3; i++){
            if(i > 0) printf("\t\t |\t |\t \n");
            else if(!j) printf("\t\t%c|\t%c|\t%c\n",options[j],options[j+1],options[j+2]);
            else if (j == 1) printf("\t\t%c|\t%c|\t%c\n",options[j+2],options[j+3],options[j+4]);
            else if (j == 2) printf("\t\t%c|\t%c|\t%c\n",options[j+4],options[j+5],options[j+6]);
    }
        if (j != 2){
        printf("\t___________________________\n");
        }
    }
}

void get_player_one (){

    int player1;
    printf("player 1 write the square where u want to put 'X'\n");
    scanf("%d", &player1);
    if ((options[player1 -1] == 'O')||(options[player1 -1] == 'X')){
        printf("error... square aready taken\n");
        get_player_one();
    }else if (player1 < 1){
        printf("You sir, have tried to input to a cell that doesnt exist :/\n");
        get_player_one();
    }else{
        options[player1 - 1] = 'X';


    }
}

void get_player_two(){


    int player2;
    printf("player 2 write the square where u want to put 'O'\n");
    scanf("%d", &player2);

    if ((options[player2 -1] == 'O')||(options[player2 -1] == 'X')){
        printf("error... square aready taken\n");
        get_player_two();
    }else if (player2 < 1){
        printf("You sir, have tried to input to a cell that doesnt exist :/\n");
        get_player_two();
    }else{
        options[player2 - 1] = 'O';

}
}

char checkwin(){
    register int i;
    //checking for vertical pattern//
    for (i = 0; i <= 2; i++){
        if ((options[i] == options[i+3]) && (options[i] == options[i+6])){
                if(options[i] == 'X') return 'X';
                else return 'O';
        }
    }

    //checking for horizontal rows//
    for (i = 0; i <= 6; i += 3){
        if ((options[i] == options[i+1])&&(options[i] == options[i+2])){
            if (options[i] == 'X') return 'X';
            else return 'O';
        }
    }

    //checking for diagonals//
    for (i = 0; i <= 2; i += 2){
        if (i == 0){
            if ((options[i] == options[i+4])&&(options[i] == options[i+8])){
                if (options[i] == 'X') return 'X';
                else return 'O';
            }
        }else if (i == 2) {
             if ((options[i] == options[i+2])&&(options[i] == options[i+4])){
                if (options[i] == 'X') return 'X';
                else return 'O';
            }
        }
    }
return '\0';
}

void resetboard(){
    register int i;
    for (i = 0; i <= 8; i++){
        options[i] =  ONE + i;
    }

}







