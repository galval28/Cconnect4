//connect 4 V1 user v user
//created by Valery Smith

//includes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//constants

const int NUMROW = 6;
const int NUMCOL = 6;
const int SIDELENGTH = 7;

void boardPrint(char array[], int SIDELENGTH){  
   //local 2D array for printing the GB
    char thick[SIDELENGTH][SIDELENGTH];
   //to keep track of where it is at in the 1D array
    int counter = 0;
   //fill the local array
   for( int i=0; i<SIDELENGTH; i++){
         
    for (int j=0; j<SIDELENGTH; j++){
          
         thick[i][j]= array[counter] ;  
          counter++;  
   }}
   //print the local 2D array
    for(int i=0; i<SIDELENGTH; i++){
        printf(" \n");
        for (int j=0; j<SIDELENGTH; j++){
         
            printf("| %c ", thick[i][j]);
            }
         printf("| \n");
     }  
}

void resetGameBoard(char array[], int SIDELENGTH){
     int arrayLength=(SIDELENGTH*SIDELENGTH);
     for(int i=0; i<arrayLength; i++){
         array[i]=' ';
        
     } 
}

void turner(char array[], char player, int arrayLength, int input){
     int incr = (SIDELENGTH-1);
     int exi = 0;
     while(exi==0){
          if(array[input+(incr*SIDELENGTH)]=='X'||array[input+(incr*SIDELENGTH)]=='O'){
          
          } 
          if(array[input+(incr*SIDELENGTH)]==' '){
             array[input+(incr*SIDELENGTH)]= player;
             exi++;
          }
          incr=incr-1;
      }   
}

int win(char array[], int SIDELENGTH){
    int win=0;
   //check vertical
    int verA;
    for(int i=0; i<(SIDELENGTH*(SIDELENGTH-3)); i++){ 
       if(array[i]=='X' && array[i+SIDELENGTH]== 'X' && array[i+(2*SIDELENGTH)]== 'X' && array[i+(3*SIDELENGTH)]=='X'){    
          win=win+1; 
          printf("player1 has won the game!!");
       }
       if(array[i]== 'O' && array[i+SIDELENGTH]== 'O' && array[i+(2*SIDELENGTH)]== 'O' && array[i+(3*SIDELENGTH)]=='O'){    
         win=win+1;
         printf("player2 has won the game!!");  
       }
    }
   //check horizontal
    int horA=0;
    while(horA<(SIDELENGTH*SIDELENGTH)){
       if(array[horA]=='X' && array[horA+1]== 'X' && array[horA+2]== 'X' && array[horA+3]=='X'){    
         win=win+1; 
         printf("player1 has won the game!!");
       }
       if(array[horA]== 'O' && array[horA+1]== 'O' && array[horA+2]== 'O' && array[horA+3]=='O'){    
          win=win+1; 
          printf("player2 has won the game!!");
       }
       horA++;
       if((horA-(SIDELENGTH-3))%(SIDELENGTH)==0){
         horA=horA+4;
       }
     }
    //check diagonal
     int diagB=0;  
     while(diagB<(1+((SIDELENGTH-4)*(SIDELENGTH+1)))){
          if(array[diagB+(SIDELENGTH+1)]=='X' && array[diagB+(2*(SIDELENGTH+1))]== 'X' && array[diagB+(3*(SIDELENGTH+1))]== 'X' && array[diagB]=='X'){    
          win=win+1; 
          printf("player1 has won the game!!");
       }
       if(array[diagB+(SIDELENGTH+1)]== 'O' && array[diagB+(2*(SIDELENGTH+1))]== 'O' && array[diagB+(3*(SIDELENGTH+1))]== 'O' && array[diagB]=='O'){    
         win=win+1;
         printf("player2 has won the game!!");
       }
       diagB++;
       if((diagB-SIDELENGTH)%(SIDELENGTH-3)==0){
         diagB=diagB+(SIDELENGTH-2);
       }
    }
    int diagA=3;  
    while(diagA<((SIDELENGTH-3)*(SIDELENGTH))){
       if(array[diagA+(SIDELENGTH-1)]=='X' && array[diagA+(2*(SIDELENGTH-1))]== 'X' && array[diagA+(3*(SIDELENGTH-1))]== 'X' && array[diagA+(4*(SIDELENGTH-1))]=='X'){    
          win=win+1; 
          printf("player1 has won the game!!");
       }
       if(array[diagA+(SIDELENGTH-1)]=='O' && array[diagA+(2*(SIDELENGTH-1))]== 'O' && array[diagA+(3*(SIDELENGTH-1))]== 'O' && array[diagA+(4*(SIDELENGTH-1))]=='O'){    
         win=win+1;
         printf("player2 has won the game!!");
       }
       diagA++;
       if(diagA%(SIDELENGTH-3)==0 &&diagA%(SIDELENGTH-4)==0){
         diagA=diagA+(SIDELENGTH-3);
       }
    }
    return win;
}

int randomGen(){
   int num;
   num = (rand()%2); 
   return num; 
 }

 
int main(void){
    char gameBoard[SIDELENGTH*SIDELENGTH];
    int gameBoardSpaces = SIDELENGTH*SIDELENGTH;
    int input;
    int exi = 0;
    char player1 = 'X';
    char player2 = 'O';
     
    resetGameBoard(gameBoard, SIDELENGTH);
    boardPrint(gameBoard, SIDELENGTH); 
    while(exi==0){
    
          //printf("\n %d", exi);

          printf("\n Player1: please choose the collum you would like to drop your picece into (0-5)\n");
          scanf("%d", &input); 
          turner(gameBoard, player1, gameBoardSpaces, input);
          boardPrint(gameBoard, SIDELENGTH);

          exi=win(gameBoard, SIDELENGTH);
 
          printf("\n Player2: please choose the collum you would like to drop your picece into (0-5)\n");
          scanf("%d", &input);
          turner(gameBoard, player2, gameBoardSpaces, input);
          boardPrint(gameBoard, SIDELENGTH);
          exi=win(gameBoard, SIDELENGTH);
     }
    

    return 0;
}
