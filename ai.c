// A C++ Program to play tic-tac-toe 

#include<bits/stdc++.h> 
using namespace std; 

#define COMPUTER 1 
#define HUMAN 2 

#define SIDE 3 // Length of the board 

// Computer will move with 'O' 
// and human with 'X' 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X' 

// A function to show the current board status 
void showBoard(char board[][SIDE]) 
{ 
	
	printf("\t\t\t %c | %c | %c \n", board[0][0], 
							board[0][1], board[0][2]); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t %c | %c | %c \n", board[1][0], 
							board[1][1], board[1][2]); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t %c | %c | %c \n\n", board[2][0], 
							board[2][1], board[2][2]);  
} 

// A function to show the instructions 
void showInstructions() 
{ 
	printf("\t\t\t Tic-Tac-Toe\n\n"); 
	printf("Choose a cell numbered from 1 to 9 as below"
			" and play\n\n"); 
	
	printf("\t\t\t 1 | 2 | 3 \n"); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t 4 | 5 | 6 \n"); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t 7 | 8 | 9 \n\n"); 
} 


// A function to initialise the game 
void initialise(char board[][SIDE], int moves[],int keep[]) 
{ 
	// Initiate the random number generator so that 
	// the same configuration doesn't arises 
	srand(time(NULL)); 
	
	// Initially the board is empty 
	for (int i=0; i<SIDE; i++) 
	{ 
		for (int j=0; j<SIDE; j++) 
			board[i][j] = ' '; 
	} 
	
	// Fill the moves with numbers 
	for (int i=0; i<SIDE*SIDE; i++) 
		moves[i] = i; 
	
	for(int i=0;i<SIDE*SIDE;i++)
		keep[i]=0;

	// randomise the moves 
	random_shuffle(moves, moves + SIDE*SIDE); 
	
	return; 
} 

// A function to declare the winner of the game 
void declareWinner(int whoseTurn) 
{ 
	if (whoseTurn == COMPUTER) 
		printf("COMPUTER has won\n"); 
	else
		printf("HUMAN has won\n"); 
	return; 
} 

// A function that returns true if any of the row 
// is crossed with the same player's move 
bool rowCrossed(char board[][SIDE]) 
{ 
	for (int i=0; i<SIDE; i++) 
	{ 
		if (board[i][0] == board[i][1] && 
			board[i][1] == board[i][2] && 
			board[i][0] != ' ') 
			return (true); 
	} 
	return(false); 
} 

// A function that returns true if any of the column 
// is crossed with the same player's move 
bool columnCrossed(char board[][SIDE]) 
{ 
	for (int i=0; i<SIDE; i++) 
	{ 
		if (board[0][i] == board[1][i] && 
			board[1][i] == board[2][i] && 
			board[0][i] != ' ') 
			return (true); 
	} 
	return(false); 
} 

// A function that returns true if any of the diagonal 
// is crossed with the same player's move 
bool diagonalCrossed(char board[][SIDE]) 
{ 
	if (board[0][0] == board[1][1] && 
		board[1][1] == board[2][2] && 
		board[0][0] != ' ') 
		return(true); 
		
	if (board[0][2] == board[1][1] && 
		board[1][1] == board[2][0] && 
		board[0][2] != ' ') 
		return(true); 

	return(false); 
} 

// A function that returns true if the game is over 
// else it returns a false 
bool gameOver(char board[][SIDE]) 
{ 
	return(rowCrossed(board) || columnCrossed(board) 
			|| diagonalCrossed(board) ); 
} 

// A function to play Tic-Tac-Toe 
void playTicTacToe(int whoseTurn) 
{ 
	// A 3*3 Tic-Tac-Toe board for playing 
	char board[SIDE][SIDE]; 
	
	int moves[SIDE*SIDE];
	int keep[SIDE*SIDE];
	
	// Initialise the game 
	initialise(board, moves, keep); 
	
	// Show the instructions before playing 
	showInstructions(); 
	
	int moveIndex = 0, x, y; 
	
	//printf("\nmoves=[");
	//for(int i = 0; i < SIDE*SIDE; i++)
	//	printf("%d ",moves[i]+1);
	//printf("]\n\n");
	
	// Keep playing till the game is over or it is a draw 
	while (gameOver(board) == false && 
			moveIndex != SIDE*SIDE) 
	{ 
		//printf("moveIndex=%d\n",moveIndex);
		
		//printf("keep=[");		
		//for(int i=0; i < SIDE*SIDE; i++)
		//	printf("%d ",keep[i]);
		//printf("]\n");
		
		int n;
		if (whoseTurn == COMPUTER) 
		{ 
			if(keep[moves[moveIndex]]==0)
			{
				x = moves[moveIndex] / SIDE; 
				y = moves[moveIndex] % SIDE; 
				board[x][y] = COMPUTERMOVE; 
				printf("COMPUTER has put a %c in cell %d\n\n", COMPUTERMOVE, moves[moveIndex]+1);
				keep[moves[moveIndex]]=1;					
				showBoard(board); 
				moveIndex ++; 
				whoseTurn = HUMAN;
			}
			else if(keep[moves[moveIndex]]==1)
			{
				int i;
				for( i=0; i<SIDE*SIDE; i++)
					if(keep[i]==0)
						break;
				x = i / SIDE; 
				y = i % SIDE; 
				board[x][y] = COMPUTERMOVE; 
				printf("COMPUTER has put a %c in cell %d\n\n", COMPUTERMOVE, i+1);
				keep[i]=1;					
				showBoard(board); 
				moveIndex ++; 
				whoseTurn = HUMAN;
			}
		} 
		
		else if (whoseTurn == HUMAN) 
		{
			printf("You can insert in the following positions : ");
			for(int i=0;i<SIDE*SIDE;i++)
				if(keep[i]!=1)
					printf("%d ",i+1);
			printf("\n");
                        printf("Enter the position=");
			scanf("%d",&n);
			n--;
			if(keep[n]==0 && n<9 && n>=0)
			{
				x = n / SIDE; 
				y = n % SIDE; 
				board[x][y] = HUMANMOVE; 
				printf ("HUMAN has put a %c in cell %d\n\n", HUMANMOVE, n+1); 
				keep[n]=1;
				showBoard(board); 
				moveIndex ++; 
				whoseTurn = COMPUTER;
			}
			else if(keep[n]==1 && n<9 && n>=0)
			{
				printf("Position is occupied, select any one place from the available places\n");
			}
			else if(n<0 || n>8)
			{
				printf("Invalid position\n");
			}
		} 
	} 

	// If the game has drawn 
	if (gameOver(board) == false && 
			moveIndex == SIDE * SIDE) 
		printf("It's a draw\n"); 
	else
	{ 
		// Toggling the user to declare the actual 
		// winner 
		if (whoseTurn == COMPUTER) 
			whoseTurn = HUMAN; 
		else if (whoseTurn == HUMAN) 
			whoseTurn = COMPUTER; 
		
		// Declare the winner 
		declareWinner(whoseTurn); 
	} 
} 

// Driver program 
int main() 
{ 
	// Let us play the game with COMPUTER starting first
	char cont='y';
	do
	{
		char choice;
	 	printf("Do you want to start first?(y/n) : ");
	 	scanf(" %c", &choice);
		if(choice=='n')
			playTicTacToe(COMPUTER);
		else if(choice=='y')
			playTicTacToe(HUMAN);
		else
			printf("Invalid choice\n"); 
        
		printf("Do you want to quit(y/n) : ");
       		scanf(" %c", &cont);
	}while(cont=='n');
	return (0); 
} 
