#include <iostream.h>
#include <conio.h>

char board[3][3] = {{' ',' ',' '},
					{' ',' ', ' '},
					{' ',' ',' '}};

//ASCII code to symbol.
void styling (int sym)
{
	char symbol = sym;
	textcolor(BLACK);
	cprintf("%c",symbol);
}
//border styling
void borderstyle(){
	gotoxy(35,10);
	styling(218);       //upper left corner
	
	for(int i=36; i<=42; i++){
		gotoxy(i,10);
		styling(196);		//upper row
	}
	
	gotoxy(43,10);			
	styling(191);			 //upper right corner
	
	for(int j=11; j<=13; j++){
		gotoxy(35,j);
		styling(179);			 // left side
	}
	
	for(int m=11; m<=13; m++){
		gotoxy(43,m);
		styling(179);			 // right side
	}
	
	gotoxy(35,14);
	styling(192);			//lower left corner
	
	for(int k=36; k<=42; k++){
		gotoxy(k,14);
		styling(196);			 // lower row
	}
	
	gotoxy(43,14);  		//lower right corner
	styling(217);
}


////print board on screen
void printBoard(){
	
	borderstyle();
	
	int x;
	int y = 11;
	textcolor(YELLOW);
	gotoxy(37,7);
	cprintf("Board");

	for(int i=0; i<3 ;i++){
		x = 37;
		for(int j=0; j<3; j++){
			gotoxy(x,y);
			
			if(board[i][j] == 'X'){
				textcolor(MAGENTA);
				cprintf("%c",board[i][j]);
			}else if(board[i][j] == 'O'){
				textcolor(BROWN);
				cprintf("%c",board[i][j]);
			}else{
				cout<<board[i][j];
			}
			

//			cout<<board[i][j]<< " ";
			x+=2;
		}
		cout<<endl;
		y++;
	}
}

//check is the position is empty 
int isEmpty(int row, int col){
	if(board[row][col] == ' '){
		return 0;
	}
	return 1;
		
}

//check win function.
int checkWin(char player){
//	check col wise
	for(int i=0; i<3; i++){
		if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
			return 1;
		}
	}
	
//	check row wise
	for(int k=0; k<3; k++){
		if(board[k][0] == player && board[k][1] == player && board[k][2] == player){
			return 1;
		}
	}
	
//	check diagnol
	if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
		return 1;
	}
	if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
		return 1;
	}
	
	return 0;
}

//check is boardfull
int isBoardFull(){
	int count = 0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(isEmpty(i,j)){
				count++;
				
			}
		}
	}
	return count;
}


//main function
int main (){
//	background color.
	textbackground(CYAN);
    clrscr();
	
	gotoxy(25,5);
	textcolor(YELLOW);
    cprintf("***** Wellcome to the Game *****");
//    cout<<"**** Wellcome to the Game ****";
	cout<<endl; 
	 
	printBoard();
	char currentPlayer = 'X';
	while(1){		
		
	 	int row, col;
	 	gotoxy(2,21);
	 	textcolor(BLUE);
    	cprintf("%c",currentPlayer);
		cprintf("'s turn. Enter row (1-3) and column (1-3): ");
//	 	cout<<currentPlayer<<"'s turn. Enter row (1-3) and column (1-3): ";
		
		textcolor(BLACK);
	 	cin>>row >>col;
	 	if(row == 1 || row == 2 || row == 3 && col == 1 || col == 2 || col == 3){
	 		row--;
	 		col--;
	 		
			//check if the move is valid.
			int checkValue = isEmpty(row,col);
			if(checkValue){
				textcolor(RED);
				cprintf("Invalid move. Please try again.");
//				cout<<"Invalid move. Please try again.";
				cout<<endl;
				continue;
				}
			
			//place move on board.
			board[row][col] = currentPlayer;
			
			//check win.
			if(checkWin(currentPlayer)){
				gotoxy(36,17);
				textcolor(YELLOW);
    			cprintf("%c",currentPlayer);
    			textcolor(GREEN);
				cprintf(" Wins ");
//				cout<<currentPlayer<<" Wins"<<endl;
				cout<<endl;
				printBoard();
				break;
			}
			
			//check for tie.
			int boardFullValue = isBoardFull();
			if(boardFullValue == 9){
				gotoxy(34,17);
				textcolor(RED);
				cprintf("It's a tie! ");
//				cout<<"It's a tie! "<<endl;
				cout<<endl;
				printBoard();
				break;
			}
			
			// Switch player
    		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
			
			clrscr();
			printBoard();
							 		
		}else{
			textcolor(RED);
			cprintf("Invalid row and col");
//		 	cout<<"Invalid row and col"<<endl;
			cout<<endl;
		}
	}
	 		 	
	 getche();
	return 0;
}
