#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <ctype.h>		
#include <dos.h>  
void cleartext(){
	for(int i=1;i<=27;i++)
		for(int j=1;j<=8;j++){
			gotoxy(i,j);
			printf(" ");
			}
	gotoxy(1,1);
	printf("enter initial position ? ");
	}
void init(){
	int i,j;
	setcolor(WHITE);
	rectangle(250,90,610,450);
	for (i=250;i<610;i+=90)
		for( j=90;j<450;j+=90){
			bar(i,j,i+45,j+45);
			bar(i+45,j+45,i+90,j+90);
			}
	for(i=2;i<=5;i++){
		for(j=0;j<=7;j++){
		 	cb[i][j] = 0;
			}
		}
	for(j=0;j<=7;j++){
		 cb[0][j] = j+1;
		 cb[1][j] = j+9;     
		 cb[7][j] = 0-(j+1);
		 cb[6][j] = 0-(j+9);
		 }
	printboard();
	setcolor(YELLOW);
	outtextxy(265,55,"A");
	outtextxy(310,55,"B");
	outtextxy(355,55,"C");
	outtextxy(400,55,"D");
	outtextxy(445,55,"E");
	outtextxy(490,55,"F");
	outtextxy(535,55,"G");
	outtextxy(580,55,"H");
	outtextxy(220,105,"1");
	outtextxy(220,150,"2");
	outtextxy(220,195,"3");
	outtextxy(220,240,"4");
	outtextxy(220,285,"5");
	outtextxy(220,330,"6");
	outtextxy(220,375,"7");
	outtextxy(220,420,"8");
}

