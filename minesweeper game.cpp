// A C++ Program to Implement and Play Minesweeper

#include<bits/stdc++.h>
using namespace std;

#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)

int SIDE ;      // side length of the board
int MINES ;     // number of mines on the board


// A Utility Function to check whether given cell (row, col) is a valid cell or not
bool isValid(int row, int col)
{
	// Returns true if row number and column number is in range
	return (row >= 0) && (row < SIDE) && (col >= 0) && (col < SIDE);
}


// A Utility Function to check whether given cell (row, col) has a mine or not.
bool isMine (int row, int col, char board[][MAXSIDE])
{
	if (board[row][col] == '*')
		return (true);
	else
		return (false);
}

// A Function to get the user's move
void makeMove(int *x, int *y)
{
	// Take the input move
	cout<<"Enter your move, (row, column) -> ";
	scanf("%d %d", x, y);
	return;
}

// A Function to print the current gameplay board
void printBoard(char myBoard[][MAXSIDE])
{
	int i, j;

	cout<<"  ";

	for (i=0; i<SIDE; i++)
		cout<<" "<<i;

	cout<<endl<<endl;

	for (i=0; i<SIDE; i++)
	{
		cout<<" "<<i;

		for (j=0; j<SIDE; j++)
			cout<< " "<<myBoard[i][j];
		cout<<endl;
	}
	return;
}

// A Function to count the number of mines in the adjacent cells
int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE])
{

	int i;
	int count = 0;

	/*
		Count all the mines in the 8 adjacent
		cells

		Cell-->Current Cell (row, col)
		    1st	Neighbour (row-1, col)
			2nd	Neighbour (row+1, col)
			3rd	Neighbour (row, col+1)
			4th	Neighbour (row, col-1)
			5th Neighbour (row-1, col+1)
			6th Neighbour (row-1, col-1)
			7th Neighbour (row+1, col+1)
			8th Neighbour (row+1, col-1)
	*/

	//----------- 1st Neighbour  ------------

		if (isValid (row-1, col) == true)
		{
			if (isMine (row-1, col, realBoard) == true)
			count++;
		}

	//----------- 2nd Neighbour  ------------

		if (isValid (row+1, col) == true)
		{
			if (isMine (row+1, col, realBoard) == true)
			count++;
		}

	//----------- 3rd Neighbour  ------------

		if (isValid (row, col+1) == true)
		{
			if (isMine (row, col+1, realBoard) == true)
			count++;
		}

	//----------- 4th Neighbour  ------------

		if (isValid (row, col-1) == true)
		{
			if (isMine (row, col-1, realBoard) == true)
			count++;
		}

	//----------- 5th Neighbour  ------------

		if (isValid (row-1, col+1) == true)
		{
			if (isMine (row-1, col+1, realBoard) == true)
			count++;
		}

	//----------- 6th Neighbour  ------------

		if (isValid (row-1, col-1) == true)
		{
			if (isMine (row-1, col-1, realBoard) == true)
			count++;
		}

	//----------- 7th Neighbour  ------------

		if (isValid (row+1, col+1) == true)
		{
			if (isMine (row+1, col+1, realBoard) == true)
			count++;
		}

	//----------- 8th Neighbour ------------

		if (isValid (row+1, col-1) == true)
		{
			if (isMine (row+1, col-1, realBoard) == true)
			count++;
		}

	return count;
}

// A Recursive Function to play the Minesweeper Game
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int *movesLeft)
{

	// Base Case of Recursion
	if (myBoard[row][col] != '-')
		return false;

	int i, j;

	// You opened a mine You are going to lose
	if (realBoard[row][col] == '*')
	{
		myBoard[row][col]='*';

		for (i=0; i<MINES; i++)
			myBoard[mines[i][0]][mines[i][1]]='*';

		printBoard (myBoard);
		cout<<"\nYou lost!"<<endl;
		return true ;
	}

	else
	{
		// Calculate the number of adjacent mines and put it on the board
		int count = countAdjacentMines(row, col, mines, realBoard);
		(*movesLeft)--;

		myBoard[row][col] = count + '0';

		if (!count)
		{
			/*
			Recur for all 8 adjacent cells

			Cell-->Current Cell (row, col)
			1st	Neighbour (row-1, col)
			2nd	Neighbour (row+1, col)
			3rd	Neighbour (row, col+1)
			4th	Neighbour (row, col-1)
			5th Neighbour (row-1, col+1)
			6th Neighbour (row-1, col-1)
			7th Neighbour (row+1, col+1)
			8th Neighbour (row+1, col-1)
			*/

				//----------- 1st Neighbour (North) ------------

			if (isValid (row-1, col) == true)
			{
				if (isMine (row-1, col, realBoard) == false)
				playMinesweeperUtil(myBoard, realBoard, mines, row-1, col, movesLeft);
			}

			//----------- 2nd Neighbour  ------------

			if (isValid (row+1, col) == true)
			{
				if (isMine (row+1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col, movesLeft);
			}

			//----------- 3rd Neighbour  ------------

			if (isValid (row, col+1) == true)
			{
				if (isMine (row, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col+1, movesLeft);
			}

			//----------- 4th Neighbour  ------------

			if (isValid (row, col-1) == true)
			{
				if (isMine (row, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col-1, movesLeft);
			}

			//----------- 5th Neighbour  ------------

			if (isValid (row-1, col+1) == true)
			{
				if (isMine (row-1, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col+1, movesLeft);
			}

			//----------- 6th Neighbour  ------------

			if (isValid (row-1, col-1) == true)
			{
				if (isMine (row-1, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col-1, movesLeft);
			}

			//----------- 7th Neighbour  ------------

			if (isValid (row+1, col+1) == true)
			{
				if (isMine (row+1, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col+1, movesLeft);
			}

			//----------- 8th Neighbour  ------------

			if (isValid (row+1, col-1) == true)
			{
				if (isMine (row+1, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col-1, movesLeft);
			}
		}

		return false;
	}
}


// A Function to place the mines randomly on the board
void placeMines(int mines[][2], char realBoard[][MAXSIDE])
{
	bool mark[MAXSIDE*MAXSIDE];

	memset (mark, false, sizeof (mark));

	// Continue until all random mines have been created.
	for (int i=0; i<MINES; )
	{
		int random = rand() % (SIDE*SIDE);
		//int x = random / SIDE;
		//int y = random % SIDE;

		// Add the mine if no mine is placed at this position on the board
		if (mark[random] == false)
		{
			// Row Index of the Mine
			mines[i][0]= random / SIDE;
			// Column Index of the Mine
			mines[i][1] = random % SIDE;

			// Place the mine
			realBoard[mines[i][0]][mines[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}

	return;
}

// A Function to initialise the game
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{
	// Initiate the random number generator so that the same configuration doesn't arises
	srand(time (NULL));

	// Assign all the cells as mine-free
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
		{
			myBoard[i][j] = realBoard[i][j] = '-';
		}
	}

	return;
}

// A Function to cheat by revealing where the mines are placed.
void cheatMinesweeper (char realBoard[][MAXSIDE])
{
	cout<<"The mines locations are-"<<endl;
	printBoard (realBoard);
	return;
}

// A function to replace the mine from (row, col) and put it to a vacant space
void replaceMine (int row, int col, char board[][MAXSIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
			{
				// Find the first location in the board which is not having a mine and put a mine there.
				if (board[i][j] != '*')
				{
					board[i][j] = '*';
					board[row][col] = '-';
					return;
				}
			}
	}
	return;
}

// A Function to play Minesweeper game
void playMinesweeper ()
{
	// Initially the game is not over
	bool gameOver = false;

	// Actual Board and My Board
	char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];

	int movesLeft = SIDE * SIDE - MINES, x, y;
	int mines[MAXMINES][2]; // stores (x,y) coordinates of all mines.

	initialise (realBoard, myBoard);

	// Place the Mines randomly
	placeMines (mines, realBoard);

	/*
	If you want to cheat and know where mines are before playing the game then uncomment this part

	cheatMinesweeper(realBoard);
	*/

	// You are in the game until you have not opened a mine
	// So keep playing

	int currentMoveIndex = 0;
	while (gameOver == false)
	{
		cout<<"Current Status of Board : "<<endl;
		printBoard (myBoard);
		makeMove (&x, &y);

		// This is to guarantee that the first move is always safe
		// If it is the first move of the game
		if (currentMoveIndex == 0)
		{
			// If the first move itself is a mine then we remove the mine from that location
			if (isMine (x, y, realBoard) == true)
				replaceMine (x, y, realBoard);
		}

		currentMoveIndex ++;

		gameOver = playMinesweeperUtil (myBoard, realBoard, mines, x, y, &movesLeft);

		if ((gameOver == false) && (movesLeft == 0))
		{
			cout<<"\nYou won !"<<endl;
			gameOver = true;
		}
	}
	return;
}


// A Function to choose the difficulty level of the game
void chooseDifficultyLevel ()
{
	/*
	--> BEGINNER = 9 * 9 Cells and 10 Mines
	--> INTERMEDIATE = 16 * 16 Cells and 40 Mines
	--> ADVANCED = 24 * 24 Cells and 99 Mines
	*/

	int level;

	cout<<"Enter the Difficulty Level"<<endl;
	cout<<"Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)"<<endl;
	cout<<"Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)"<<endl;
	cout<<"Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)"<<endl;

	cin>>level;

	if (level == BEGINNER)
	{
		SIDE = 9;
		MINES = 10;
	}

	if (level == INTERMEDIATE)
	{
		SIDE = 16;
		MINES = 40;
	}

	if (level == ADVANCED)
	{
		SIDE = 24;
		MINES = 99;
	}

	return;
}


int main()
{
	/* Choose a level between
	--> BEGINNER = 9 * 9 Cells and 10 Mines
	--> INTERMEDIATE = 16 * 16 Cells and 40 Mines
	--> ADVANCED = 24 * 24 Cells and 99 Mines
	*/
	chooseDifficultyLevel();

	playMinesweeper();

	return 0;
}