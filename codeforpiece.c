#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <ctype.h>		
#include <dos.h>  
int knight(int x,int y,int x1,int y1){
	int p=0;
	if((y1==y+2 && x1==x+1)
		||(y1==y+2 && x1==x-1)
		||(y1==y+1 &&x1==x+2)
		||(y1==y+1 && x1==x-2)
		||(y1==y-1 && x1==x+2)
		||(y1==y-1 &&x1==x-2)
		||(y1==y-2 && x1==x+1)
		||(y1==y-2 && x1==x-1)) {
			p = 1;
			}
	return p;
	}
int king(int x,int y,int x1,int y1){
	int p = 0;
	if((y1==y+1 && x1==x)
		||(y1==y-1 && x1==x)
		||(y1==y+1 &&x1==x+1)
		||(y1==y+1 && x1==x-1)
		||(y1==y-1 && x1==x+1)
		||(y1==y-1 &&x1==x-1)
		||(y1==y && x1==x+1)
		||(y1==y && x1==x-1)){                         
			p = 1;
			}
	else if(cb[y][x+1]==0
		&&cb[y][x+2]==0
		&&(abs(cb[y1][x1])==abs(cb[y][x+3])==1
		||abs(cb[y1][x1])==abs(cb[y][x+3])==8)){           
			return 2;
			}
	if(a==1){
		if(cb[y][x]==5)
			c1=1;
		if(cb[y][x]==-5)
			c2=1;
		}
	return p;
	}
int bishop(int x,int y,int x1,int y1){
	int p=1,i;
	if(abs(x1 - x) != abs(y1 - y)){
		p=0;
	}
	
	if((x<x1)&&(y<y1)){
		for(i=1;(i+x)<x1;i++){
			if(cb[y+i][x+i]!=0)
				p=0;
			}
		}

	else if((x>x1)&&(y>y1)){
		for(i=1;(x-i)>x1;i++){
	 		if(cb[y-i][x-i]!=0)
	    			p=0;
	 		}
		}
	else if((x>x1)&&(y<y1)){
		for(i=1;(x-i)>x1;i++){
			if(cb[y+i][x-i]!=0)
	    			p=0;
	 		}
		}
	else if((x<x1)&&(y>y1)){
		for(i=1;(y-i)>y1;i++){
	 		if(cb[y-i][x+i]!=0)
	    			p=0;
	 		}
		}
	return p;
	}
int rook(int x,int y,int x1,int y1){
	int p=1;
	if(y1==y){
		for(int i=x+1;i<x1;i++){
			if(cb[y1][i]!=0){
				p = 0;
				break;
				}
			}
		for(i=x-1;i>x1;i--){
			if(cb[y1][i]!=0){
				p = 0;
				break;
				}
			}
		}
	else if(x1==x){
		for(int i=y+1;i<y1;i++){
			if(cb[i][x1]!=0){
				p = 0;
				break;
				}
			}
		for(i=y-1;i>y1;i--){
			if(cb[i][x1]!=0){
				p = 0;
				break;
				}
			}
		}
	else{
		p=0;
		}
	return p;
	}
int queen(int x,int y,int x1,int y1){
	if(x==x1||y==y1){                        
		return rook(x,y,x1,y1);
   		}
   	else if(abs(x1-x)==abs(y-y1)){      
		return bishop(x,y,x1,y1);
   		}
   	else
		return 0;
	}
int pawn(int x,int y,int x1,int y1){
	int p=0;
	if(turn==0){
		if(y==1){
			if(y1==(y+2) && x1==x){
				if(cb[y1][x1]==0&&cb[y+1][x]==0){
					p = 1;
			   		}
				}
			}
		if(y1==y+1 && x1==x){
			if(cb[y1][x1]==0){
				p = 1;
				}
			}
	   	else if(y1==(y+1) && (x1==(x+1)||x1==(x-1))){
		   	if(cb[y1][x1]<0){
			 	p = 1;
			 	}
		  	}
		}
	else if(turn==1){
		if(y==6){
			if( y1==(y-2) && x1==x){
				if(cb[y1][x1]==0&&cb[y-1][x]==0){
					p = 1;
			   		}
				}
		      	}
		if( y1==(y-1) && x1==x){
			if(cb[y1][x1]==0){
				p = 1;
				}
			}
	   	else if(y1==(y-1) && (x1==(x-1)||x1==(x+1))){
		if(cb[y1][x1]>0){
			 p = 1;
			 }
		  }
	}
	if(p==1){
		if(turn==0){
			if(y1==7)
	 			return 2;
     			}
     		else {
			if(y1==0)
				return 2;
     			}
    		}
 	return p;
	}



