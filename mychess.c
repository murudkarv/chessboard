
#include <stdlib.h>
#include <stdio.h>
int board[8][8],turn=0,count1=0,count2=0;
int gameover();
char strFileName[15];  //saving the game or loading the saved game
void printboard();     //learn outtextxy function from graphics.h
void wrongStart();     //////learn the graphics.h/////
void initialize();     
void cleartext();
void check();


//Prototypes
int pawn(int x,int y,int x1,int y1);
int horse(int x,int y,int x1,int y1);
int rook(int x,int y,int x1,int y1);
int bishop(int x,int y,int x1,int y1);
int queen(int x,int y,int x1,int y1);
int king(int x,int y,int x1,int y1);

