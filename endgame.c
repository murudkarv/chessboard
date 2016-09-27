//Check


void check(){
	int t=0,i,j,x1,y1;
	if(turn==0){
		for(i=0;i<=7;i++){
			for(j=0;j<=7;j++){
				if(board[i][j]==-5){
					y1=i; x1=j;
				  	break;
					}
		  		}
	     		}
       		for(j=0;j<=7;j++){
			for(i=0;i<=7;i++){

	 			if(board[j][i]>=9 && board[j][i]<=16)
					t = pawn(i,j,x1,y1);
	 			else if(board[j][i]==2 || board[j][i]==7)
					t = horse(i,j,x1,y1);
	 			else if(board[j][i]==4)
					t = queen(i,j,x1,y1);
	 			else if(board[j][i]==1 || board[j][i]==8)
					t = rook(i,j,x1,y1);
	 			else if(board[j][i]==3 || board[j][i]==6)
					t = bishop(i,j,x1,y1);

				}// for
       			}//  for
     		}//endif turn
    	else {
     		for(i=0;i<=7;i++){
      			for(j=0;j<=7;j++){
       				if(board[i][j]==5){
	 				y1=i; 
					x1=j;
	  				break;
	      				}
	  			}
       			}
       		for(j=0;j<=7;j++){
			for(i=0;i<=7;i++){

	 			if(board[j][i]>=(-9) && board[j][i]<=(-16))
					t = pawn(i,j,x1,y1);
	 			else if(board[j][i]==(-2) || board[j][i]==(-7))
					t = horse(i,j,x1,y1);
	 			else if(board[j][i]==(-4))
					t = queen(i,j,x1,y1);
	 			else if(board[j][i]==(-1) || board[j][i]==(-8))
					t = rook(i,j,x1,y1);
	 			else if(board[j][i]==(-3) || board[j][i]==(-6))
					t = bishop(i,j,x1,y1);

				}// for
       			}//  for
 		}// end else
	}


//GAME OVER
int gameover(){
	int i,j,a=0,b=0;

	for(i=0;i<=7;i++){
		for(j=0;j<=7;j++){
			if(board[i][j]==5)
				b=1;
		        if(board[i][j]==-5)
		       		a=1;
			}
		}
	return 1;
	}

