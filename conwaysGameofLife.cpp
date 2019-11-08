/* Elizabeth Messina
   September 20th, 2018
   Data Structures
   Project - "Conway's Game of Life"
   
   Known Bugs: runtime error - LOOK BELOW, line 180 explanation
*/

//Project Notes & Rules:
/*	
	Rules:
	
	1. Survival: Each cell that has two or three adjacent cells survives until the next generation.
	2. Death: Each cell that has at least four adjacent cells disappears (or dies) by overpopulation. Also, each cell that has at most one adjacent cell dies by isolation.
	3. Birth: Each empty square (i.e., dead cell) that is adjacent to exactly three cells gives birth to a new cell for the next generation. 
	
	-- need to check all 8 spaces surrounding it and add/count with each 1 - if val = 2 or 	  3, nothing happens/survives; if val >= four or val <=1, the space = 0 instead of      1/dies; each cell that already is dead or = 0 and has val = 3 will birth or become    1 again
	-- make a for loop that counts up/gets a numAdj for each value
	-- then separate for loop for killing/birthing depending on the values
*/

#include <iostream>
#include <random>
using namespace std;

//Global Variables
const int LIVE = 1;
const int DEAD = 0;
const int rows = 14, cols = 14;

//Functions
void printBoard(int board[rows][cols]);
void copyBoard(int ogBoard[rows][cols], int newBoard[rows][cols]);

int main () {
	//int numTerm;
	int newBoard[rows][cols];
	
	system("clear");  //clear screen
	
	//introducing the game
	cout << "\nHi! Welcome to Conway's Game of Life. \nHere are the games' rules: " << endl;
	cout << "\n1. Survival: Each cell that has two or three adjacent cells survives until the next generation.\n\n2. Death: Each cell that has at least four adjacent cells disappears (or dies) by overpopulation.\nAlso, each cell that has at most one adjacent cell dies by isolation.\n\n3. Birth: Each empty square (i.e., dead cell) that is adjacent to exactly three cells gives birth\nto a new cell for the next generation. " << endl;
	cout << "\n--------------------------------------------------------------------------------------------" << endl;
	
	cout << "\nHere is the original board: " << endl;
	
	srand( time(NULL) ); //Randomize seed initialization
	
	// example grid, doesn't take in the user's dimensions
	int grid[14][14] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,0,1,0,0,0,1,0,1,1,0,0},
		{0,0,1,0,0,0,1,0,1,0,1,0,0,0},
		{0,1,0,1,0,0,0,1,1,1,0,1,0,0},
		{0,0,0,0,1,0,0,0,1,0,1,0,1,0},
		{0,0,0,1,1,0,0,0,0,1,1,0,1,0},
		{0,0,0,0,1,1,0,0,0,1,1,0,0,0},
		{0,1,1,0,0,1,1,0,0,0,1,0,1,0},
		{0,0,1,0,0,0,1,0,0,1,0,0,0,0},
		{0,1,1,1,0,1,0,1,0,0,1,1,0,0},
		{0,1,0,1,0,0,0,1,1,0,0,1,0,0},
		{0,0,1,1,0,1,0,0,0,1,1,1,0,0},
		{0,0,1,0,1,1,0,1,0,1,0,0,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0} 
	};
	
	cout << endl << "Original Board:" << endl;
	
	//Prints out Original Board
	printBoard(grid);
	
	int cnt = 0;
	char nextTerm = 'n';
	
	cout << "Would you like to see the first termination? (y/n): ";
	cin >> nextTerm;
	cout << endl;
	
	//Creates New Board Based off of Previous Board
	while (nextTerm == 'y' || nextTerm == 'Y'){
		//Creating a New Board Based on Rules
		for(int i=1; i<rows-1; i++) {
			for(int j=1; j<cols-1; j++) {

				int liveCnt = 0;
				//counting the # of live (aka val of 1) adjacent cells for each cell (not checking the border)
				if (grid[i-1][j-1] == LIVE)
				{
					liveCnt++;
				}
				if (grid[i-1][j] == LIVE)
				{
					liveCnt++;
				}
				if (grid[i-1][j+1] == LIVE)
				{
					liveCnt++;
				}
				if (grid[i][j-1] == LIVE)
				{
					liveCnt++;
				}
				if (grid[i][j+1] == LIVE)
				{
					liveCnt++;
				}
				if (grid[i+1][j-1] == LIVE)
				{
					liveCnt++;
				}
				if (grid[i+1][j+1] == LIVE)
				{
					liveCnt++;
				}
				if (grid[i+1][j] == LIVE)
				{
					liveCnt++;
				}

				//Initializing newBoard
				newBoard[i][j] = 0;

				//making new board depending on the game rules

				if (grid[i][j] == LIVE && (liveCnt == 2 || liveCnt == 3)) {

					newBoard[i][j] = LIVE;
				}

				else if (grid[i][j] == LIVE && (liveCnt >= 4 || liveCnt <= 1)) {

					newBoard[i][j] = DEAD;
				}

				else if (grid[i][j] == DEAD && liveCnt == 3) {

					newBoard[i][j] = LIVE;
				}

				else { //(grid[i][j] == DEAD && liveCnt != 3)

					newBoard[i][j] = DEAD;
				}
			}
		}
		
		cnt++;
		
		cout << "Termination " << cnt << ":" << endl << endl;
		copyBoard(grid, newBoard);
		
		cout << "Would you like to see another termination? (y/n): ";
		cin >> nextTerm;
		cout << endl;
	}
	
	cout << "Exiting game. Have a nice day!" << endl << endl;
	
	return 0;
}

//Gen. Function that Prints the Board/Array
void printBoard(int board[rows][cols]) {
	
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//Function that Copies New Board to Previous and Prints New Board
void copyBoard(int ogBoard[rows][cols], int newBoard[rows][cols]) {
	
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
				
			//Important Line: Makes "grid" = the new array so the game can update
			ogBoard[i][j] = newBoard[i][j];
			cout << newBoard[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;	
}

/*BUGS:
    having an issue with random #s appearing at end of boards
	not a memory problem..
*/



