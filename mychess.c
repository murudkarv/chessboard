/*--------------------------------------------------------------
copyright(c)  vaibhav murudkar    murudkarv15.it@coep.ac.in
This program is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License 
as published by the Free Software Foundation, either 
version 3 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details. You should 
have received a copy of the GNU General Public License along with 
this program. If not, see <http://www.gnu.org/licenses/>
----------------------------------------------------------------*/
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
int cb[8][8], turn=0, c1=0, c2=0 ;
char filename[15] ;
void showboard() ;
void startfail() ;
void init() ;
void cleartext() ;
void check() ;
int endgame() ;
void gotoxy(int x,int y) ;
int pawn(int x, int y, int x1, int y1) ;
int knight(int x, int y, int x1, int y1) ;
int rook(int x, int y, int x1, int y1) ;
int bishop(int x, int y, int x1, int y1) ;
int queen(int x, int y, int x1, int y1) ;
int king(int x, int y, int x1, int y1) ;
int main(){
	FILE *fp;
	char ch, reborn;
	int x=-1, y=-1, x1=-1, y1=-1, b=0, kill=0, i, j;
//Graphics Initialization
	int gdriver = DETECT;
	int gmode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");

	setcolor(GREEN);
	outtextxy(50,90,"WELCOME TO THE CHESS");
	outtextxy(50,150,"(Two Player game)");
	getch();
	cleardevice();

	setcolor(12);
	outtextxy(50,10,"*During the game Press*");

	setcolor(6);
	outtextxy(50,60,"-F2 to save file");
	outtextxy(50,80,"-F3 to load file");
	outtextxy(50,100,"-ESC to exit game");
	outtextxy(50,120,"-U to undo selection");
	outtextxy(50,200,"**Press any key to play ");
	getch();
	cleardevice();
	cleartext();
	init();
	setcolor(9);
	outtextxy(10,400,"Player 1");
	for(;;){
		int game;
		game = endgame();
		if(game == 0){
			break;
			}
		ch = getch();
		if(ch == 0){
			ch = getch();
			if(ch == '<'){       //save
				for(;;){
					printf("\t\tEnter File name to save \n");
					gets(filename);  //Enter File Name
					fp = fopen(filename, "r+");
					if(fp != NULL){
						printf("File already exist\n");
						}
					else{
						fp = fopen(filename, "w+");
						if(fp == NULL){
							printf("Invalid File Name\n");
							}
						else
							break;
						}
					}//for
				fprintf(fp, "%d\n", turn);
				for(i=0; i<8; i++){
					for(j=0; j<8; j++){
						fprintf(fp, "%d\n", cb[i][j]);
						}
					}
				fclose(fp);
				cleartext();
				x = -1;
				y = -1;
				x1 = -1;
				y1 = -1;
				continue;
				}//end saving

			if(ch == '='){		//Load
				for(;;){
					printf("\t\tEnter File name to Load \n");
					gets(filename);
					fp = fopen(filename, "r+");
					if(fp == NULL){
						printf("File does not exist\n");
						}
					else{
						break;
						}
					}//for
				fscanf(fp, "%d", &turn);
				for(i=0; i<8; i++){
					for(j=0; j<8; j++){
						fscanf(fp, "%d", &cb[i][j]);
						}
					}
				fclose(fp);
				showboard();
				cleartext();
				x = -1;
				y = -1;
				x1 = -1;
				y1 = -1;
				setcolor(0);
				outtextxy(10,400,"Player ?");
				if(turn != 0){
					check();
					setcolor(2);
					outtextxy(10,400,"Player 2");
					}
				else{
					check();
					setcolor(9);
					outtextxy(10,400,"Player 1");
					}
				continue;
				}//end loading
			}//end F options
		if(ch == 27){
			break;
			}//exiting the game
		else if(ch == 'u'|| ch == 'U'){
			x = -1;
			x1 = -1;
			y1 = -1;
			y = -1;
			cleartext();
			continue;
			}//undo
		if(x == -1){
			ch=toupper(ch);
			if(ch >= 65 && ch <= 72){
				printf("%c", ch);
				x = ch - 65;
				}
			}
		else if(y == -1){
			if(ch >= '1' && ch <= '8'){
				printf("%c", ch);
				y = ch - '1';
				if(cb[y][x] == 0){
					startfail();
					x = -1;
					y = -1;
					}
				else{
					if(turn == 0){
						if(cb[y][x] < 0){	 //wrong piece selected
							startfail();
							x = -1;
							y = -1;
							}
						}
					else if(turn != 0){
						if(cb[y][x] > 0){
							startfail();
							x = -1;
							y = -1;
							}
						}
					}
				}//completion of entering initial position
			if(x != -1 && y != -1)
				printf("\nenter final position  ? ");
			}
		else if(x1 == -1){
			ch = toupper(ch);
			if(ch >= 65 && ch <= 72){
				printf("%c", ch);
				x1 = ch - 65;
				}
			}
		else if(y1 == -1){
			if(ch >= '1' && ch <= '8'){
				printf("%c", ch);
				y1 = ch - '1';
				}
			if(abs(cb[y][x]) >= 9 && abs(cb[y][x]) <= 16){	//for pawn
				b = pawn(x, y, x1, y1);
				}
			else if(abs(cb[y][x]) == 2 || abs(cb[y][x]) == 7){   //for horse
				b = knight(x, y, x1, y1);
				}

			else if(abs(cb[y][x]) == 4){     //for queen
				b = queen(x, y, x1, y1);
				}
			else if(abs(cb[y][x]) == 5){	//for king
					b = king(x, y, x1, y1);
				 }
			else if(abs(cb[y][x]) == 1 || abs(cb[y][x]) == 8){    //for rook
				b = rook(x, y, x1, y1);
				}
			else if(abs(cb[y][x]) == 3 || abs(cb[y][x]) == 6){	// for bishop
				b = bishop(x, y, x1, y1);
				}

			if(b == 2){
				if(abs(cb[y][x]) >= 9 && abs(cb[y][x]) <= 16){
					printf("\n\t\twhich piece Q,R,H,B");
					reborn = getch();
					if(turn == 0){
						if(reborn == 'r')
							cb[y1][x1] = 1;
						else if(reborn == 'h')
							cb[y1][x1] = 2;
						else if(reborn == 'b')
							cb[y1][x1] = 3;
						else if(reborn == 'q')
							cb[y1][x1] = 4;
						}
					else{
						if(reborn == 'r')
							cb[y1][x1] = -1;
						else if(reborn == 'h')
							cb[y1][x1] = -2;
						else if(reborn == 'r')
							cb[y1][x1] = -3;
						else if(reborn == 'q')
							cb[y1][x1] = -4;
						}
					cb[y][x] = 0;
					kill = 1;
					}
				else if(abs(cb[y][x]) == 5){
					if(cb[y][x] == 5){
						if(c1 == 1)
						;
						startfail();
						}
					else if(cb[y][x] == -5){
						if(c1 == 1)
						;
						startfail();
						}
					else{
						cb[y][x+1] = cb[y1][x1];
						cb[y][x+2] = cb[y][x];
						cb[y1][x1] = 0;
						cb[y][x] = 0;
						kill = 1;
						}
					}
				showboard();
				}//end of special moves
			else if(b == 1){
				if(turn == 0){
					if(cb[y1][x1] < 0){
						cb[y1][x1] = cb[y][x];
						cb[y][x] = 0;
						kill = 1;
						}
					}
				if(turn != 0){
					if(cb[y1][x1] > 0){
						cb[y1][x1] = cb[y][x];
						cb[y][x] = 0;
						kill = 1;
						}
					}
				if(cb[y1][x1] == 0){
					int temp = cb[y][x];
					cb[y][x] = cb[y1][x1];
					cb[y1][x1] = temp;
					kill = 1;
					}
				showboard();
				}
			else{
				startfail();
				x = -1;
				y = -1;
				x1 = -1;
				y1 = -1;
				continue;
				}
			x = -1;
			y = -1;
			x1 = -1;
			y1 = -1;
			setcolor(0);
			outtextxy(30, 340, "Check");
			if(kill == 0){
				startfail();
				continue;
				}
			cleartext();
			setcolor(0);
			outtextxy(10, 400, "Player ?");
			if(turn == 0){
				check();
				turn = 1;
				setcolor(2);
				outtextxy(10, 400, "Player 2");
				}
			else{
				check();
				turn = 0;
				setcolor(9);
				outtextxy(10, 400, "Player 1");
				}
			}//end move
		}//end infinite for
	getch();
	closegraph();
	return 0;
	}//end main
void showboard(){
	int i, j;
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if((i+j)%2 == 0)
				setcolor(WHITE);
			else
				setcolor(BLACK);
			outtextxy(270+(j*45), 105+(i*45), "??");
			if(cb[i][j] < 0)
				setcolor(GREEN);
			else if(cb[i][j] > 0)
				setcolor(9);
			if(abs(cb[i][j]) >= 9){
				outtextxy(270+(j*45), 105+(i*45), "P");
				}
			else if(abs(cb[i][j]) == 1 || abs(cb[i][j]) == 8){
				outtextxy(270+(j*45),105+(i*45),"R");
				}
			else if(abs(cb[i][j]) == 2 || abs(cb[i][j]) == 7){
				outtextxy(270+(j*45), 105+(i*45), "H");
				}
			else if(abs(cb[i][j]) == 3 || abs(cb[i][j]) == 6){
				outtextxy(270+(j*45), 105+(i*45), "B");
				}
			else if(abs(cb[i][j]) == 4){
				outtextxy(270+(j*45), 105+(i*45), "Q");
				}
			else if(abs(cb[i][j]) == 5){
				outtextxy(270+(j*45), 105+(i*45), "K");
				}
			}
		}
	}

void check(){
	int t=0,i,j,x1,y1;
	if(turn==0){
		for(i=0;i<=7;i++){
			for(j=0;j<=7;j++){
				if(cb[i][j]==-5){
					y1=i;
					x1=j;
					break;
					}
				}
			}
		for(j=0;j<=7;j++){
			for(i=0;i<=7;i++){
				if (t==1){
					setcolor(9);
					outtextxy(30,340,"Check");
					break;
					}
				if(cb[j][i]>=9 && cb[j][i]<=16)
					t = pawn(i,j,x1,y1);
				else if(cb[j][i]==2 || cb[j][i]==7)
					t = knight(i,j,x1,y1);
				else if(cb[j][i]==4)
					t = queen(i,j,x1,y1);
				else if(cb[j][i]==1 || cb[j][i]==8)
					t = rook(i,j,x1,y1);
				else if(cb[j][i]==3 || cb[j][i]==6)
					t = bishop(i,j,x1,y1);

				}//
			}//fors
		}//end turn==0
	else {
		for(i=0;i<=7;i++){
			for(j=0;j<=7;j++){
				if(cb[i][j]==5){
					y1=i;
					x1=j;
					break;
					}
				}
			}
		for(j=0;j<=7;j++){
			for(i=0;i<=7;i++){
				if (t==1){
					setcolor(GREEN);
					outtextxy(30,340,"Check");
					break;
					}
				if(cb[j][i]>=(-9) && cb[j][i]<=(-16))
					t = pawn(i,j,x1,y1);
				else if(cb[j][i]==(-2) || cb[j][i]==(-7))
					t = knight(i,j,x1,y1);
				else if(cb[j][i]==(-4))
					t = queen(i,j,x1,y1);
				else if(cb[j][i]==(-1) || cb[j][i]==(-8))
					t = rook(i,j,x1,y1);
				else if(cb[j][i]==(-3) || cb[j][i]==(-6))
					t = bishop(i,j,x1,y1);

				}//
			}//  fors
		}// end else
	}//check
int endgame(){
	int i, j, p=0, q=0;
	for(i=0; i<=7; i++){
		for(j=0; j<=7; j++){
			if(cb[i][j] == 5){
				q = 1;
				}
			if(cb[i][j] == -5){
				p = 1;
				}
			}
		}
	return 1;
	}

int knight(int x, int y, int x1, int y1){
	int p = 0;
	if((y1 == y+2 && x1 == x+1)
		||(y1 == y+2 && x1 == x-1)
		||(y1 == y+1 && x1 == x+2)
		||(y1 == y+1 && x1 == x-2)
		||(y1 == y-1 && x1 == x+2)
		||(y1 == y-1 && x1== x-2)
		||(y1 == y-2 && x1 == x+1)
		||(y1 == y-2 && x1 == x-1)) {
			p = 1;
			}
	return p;
	}
int king(int x, int y, int x1, int y1){
	int p = 0;
	if((y1 == y+1 && x1 == x)
		||(y1 == y-1 && x1 == x)
		||(y1 == y+1 && x1 == x+1)
		||(y1 == y+1 && x1 == x-1)
		||(y1 == y-1 && x1 == x+1)
		||(y1 == y-1 && x1 == x-1)
		||(y1 == y && x1 == x+1)
		||(y1 == y && x1 == x-1)){
			p = 1;
			}
	else if(cb[y][x+1] == 0           //castling
		&& cb[y][x+2] == 0
		&& (abs(cb[y1][x1]) == abs(cb[y][x+3]) == 1
		|| abs(cb[y1][x1]) == abs(cb[y][x+3]) == 8)){
			p=2;
			}
	if(p == 1){
		if(cb[y][x] == 5)
			c1 = 1;
		if(cb[y][x] == -5)
			c2 = 1;
		}
	return p;
	}
int bishop(int x, int y, int x1, int y1){
	int p = 1,i;
	if(abs(x1 - x) != abs(y1 - y)){
		p = 0;
		}
	if((x < x1) && (y < y1)){
		for(i=1; (i+x) < x1; i++){
			if(cb[y+i][x+i] != 0)
				p = 0;
			}
		}
	else if((x > x1) && (y > y1)){
		for(i=1; (x-i) > x1; i++){
			if(cb[y-i][x-i] != 0){
				p = 0;
				}
			}
		}
	else if((x > x1) && (y < y1)){
		for(i=1; (x-i) > x1; i++){
			if(cb[y+i][x-i] != 0){
				p = 0;
				}
			}
		}
	else if((x < x1) && (y > y1)){
		for(i=1; (y-i) > y1; i++){
			if(cb[y-i][x+i] != 0){
				p = 0;
				}
			}
		}
	return p;
	}
int rook(int x, int y, int x1, int y1){
	int p = 1, i;
	if(y1 == y){
		for(i=x+1; i < x1; i++){
			if(cb[y1][i] != 0){
				p = 0;
				break;
				}
			}
		for(i=x-1; i > x1; i--){
			if(cb[y1][i] != 0){
				p = 0;
				break;
				}
			}
		}
	else if(x1 == x){
		for(i=y+1; i < y1; i++){
			if(cb[i][x1] != 0){
				p = 0;
				break;
				}
			}
		for(i=y-1; i > y1; i--){
			if(cb[i][x1] != 0){
				p = 0;
				break;
				}
			}
		}
	else{
		p = 0;
		}
	return p;
	}
int queen(int x, int y, int x1, int y1){
	if(x == x1 || y == y1){
		return rook(x, y, x1, y1);
		}
	else if(abs(x1-x) == abs(y-y1)){
		return bishop(x, y, x1, y1);
		}
	else
		return 0;
	}
int pawn(int x, int y, int x1, int y1){
	int p = 0;
	if(turn == 0){
		if(y == 1){
			if(y1 == (y+2) && x1 == x){
				if(cb[y1][x1] == 0 && cb[y+1][x] == 0){
					p = 1;
					}
				}
			}
		if(y1 == y+1 && x1 == x){
			if(cb[y1][x1] == 0){
				p = 1;
				}
			}
		else if(y1 == (y+1) && (x1 == (x+1) || x1 == (x-1))){
			if(cb[y1][x1] < 0){
				p = 1;
				}
			}
		}
	else if(turn == 1){
		if(y == 6){
			if( y1 == (y-2) && x1 == x){
				if(cb[y1][x1] == 0 && cb[y-1][x] == 0){
					p = 1;
					}
				}
			}
		if( y1 == (y-1) && x1 == x){
			if(cb[y1][x1] == 0){
				p = 1;
				}
			}
		else if(y1 == (y-1) && (x1 == (x-1) || x1 == (x+1))){
		if(cb[y1][x1] > 0){
			 p = 1;
			 }
		  }
	}
	if(p == 1){
		if(turn == 0){
			if(y1 == 7)
				return 2;
			}
		else {
			if(y1 == 0)
				return 2;
			}
		}
	return p;
	}
void cleartext(){
	int i,j;
	for(i=1; i<=27; i++)
		for(j=1; j<=16; j++){
			gotoxy(i,j);
			printf(" ");
			}
	gotoxy(1,1);
	printf("enter initial position ? ");
	}
void startfail(){
	int i,j;
	char ch;
	printf("\nWrong Input\nPress any key to continue...");
	ch=getch();
	if(ch == 0){
		getch();
		}
	for(i=1; i<=30; i++){
		for(j=1; j<=4; j++){
			gotoxy(i,j);
			printf(" ");
			}
		}
	gotoxy(1,1);
	printf("enter initial position ? ");
}
void init(){
	int i, j;
	setcolor(WHITE);
	rectangle(250, 90, 610, 450);
	for (i=250; i<610; i=i+90){
		for(j=90; j<450; j=j+90){
			bar(i, j, i+45, j+45);
			bar(i+45, j+45, i+90, j+90);
			}
		}
	for(i=2; i<=5; i++){
		for(j=0; j<=7; j++){
			cb[i][j] = 0;
			}
		}
	for(j=0; j<=7; j++){
		 cb[0][j] = j+1;
		 cb[1][j] = j+9;
		 cb[7][j] = 0-(j+1);
		 cb[6][j] = 0-(j+9);
		 }
	showboard();
	setcolor(YELLOW);
	outtextxy(265, 55, "A");
	outtextxy(310, 55, "B");
	outtextxy(355, 55, "C");
	outtextxy(400, 55, "D");
	outtextxy(445, 55, "E");
	outtextxy(490, 55, "F");
	outtextxy(535, 55, "G");
	outtextxy(580, 55, "H");
	outtextxy(220, 105,"1");
	outtextxy(220, 150, "2");
	outtextxy(220, 195, "3");
	outtextxy(220, 240, "4");
	outtextxy(220, 285, "5");
	outtextxy(220, 330, "6");
	outtextxy(220, 375, "7");
	outtextxy(220, 420, "8");
	}
void gotoxy(int x,int y){
	printf("%c[%d;%df",0x1B,y,x);
	}
