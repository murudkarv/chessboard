#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <ctype.h>		
#include <dos.h>   
int cb[8][8], turn=0, c1=0, c2=0 ;
char filename[15] ; 

void showboard() ;    
void failedstart() ;     
void init() ;     
void cleartxt() ;
void checkmate() ;
int endgame() ;
int pawn(int x, int y, int x1, int y1) ;
int knight(int x, int y, int x1, int y1) ;
int rook(int x, int y, int x1, int y1) ;
int bishop(int x, int y, int x1, int y1) ;
int queen(int x, int y, int x1, int y1) ;
int king(int x, int y, int x1, int y1) ;


int main(){
	int gdriver = DETECT;
	int gmode;
	initgraph( &gdriver, &gmode, "e:\\borlandc\\bgi" );
	init();
	char ch ;
	int x=-1, y=-1, x1=-1, y1=-1 ;
	setcolor(9);
	outtextxy(10, 400, "Player 1");
	for(;;){
	       int game;
		 game=endgame();
		   if(game==0){
			 break;
		   }
	}


return 0;
}

