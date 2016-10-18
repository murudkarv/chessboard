#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <ctype.h>		
#include <dos.h>  
void showboard(){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if((i+j)%2==0)
				setcolor(WHITE);
			else
				setcolor(BLACK);
			outtextxy(270+(j*45),105+(i*45),"??");
			if(cb[i][j]<0)
				setcolor(GREEN);
			else if(cb[i][j]>0)
				setcolor(9);
			if(abs(cb[i][j])>=9 && abs(cb[i][j])<=16){
				outtextxy(270+(j*45),105+(i*45),"P");}
			else if(abs(cb[i][j])==1 || abs(cb[i][j])==8){
				outtextxy(270+(j*45),105+(i*45),"R");}
			else if(abs(cb[i][j])==2 || abs(cb[i][j])==7){
				outtextxy(270+(j*45),105+(i*45),"H");
				}
			else if(abs(cb[i][j])==3 || abs(cb[i][j])==6){
				outtextxy(270+(j*45),105+(i*45),"B");
				}
			else if(abs(cb[i][j])==4){
				outtextxy(270+(j*45),105+(i*45),"Q");
				}
			else if(abs(cb[i][j])==5){
				outtextxy(270+(j*45),105+(i*45),"K");
				}
			}
		}
	}

