/* Elizabeth Messina
   September 20th, 2018
   Data Structures
   Project - "Conway's Game of Life"
   
   Known Bugs: runtime error - LOOK BELOW, line 60 explanation
*/


/*
	Project Notes
	
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


static std::random_device rd;  // Random device engine, usually based on /dev/random on UNIX systems
	static std::mt19937_64 rng(rd()); // Initialize Mersennes' twister using rd to generate the seed

	// Generate random doubles in the interval [initial, last)
	double random_real(double initial, double last) {
    	std::uniform_real_distribution<double> distribution(initial, last);
    	return distribution(rng);  // Use rng as a generator
	}

// Generate random int in the interval [initial, last]
	int random_int(int initial, int last) {
    	std::uniform_int_distribution<int> distribution(initial, last);
    	return distribution(rng);  // Use rng as a generator
	}

int main () {
	int rows, cols;
	int grid[cols][rows];
	
	cout << "Hello World" << endl;
	cout << "Enter number of columns/rows: ";
	cin >> cols;
	rows = cols;
	
	srand( time(NULL) ); //Randomize seed initialization
	
	
	//making a test grid
	for(int i=1; i<=cols-1; i++) {
		for(int j=1; j<=rows-1; j++) {
			grid[i][j] = random_int(0,1);
			if(grid[i][j] == 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	
	//testing
	cout << "The value at 4/5 is " << grid[4][5] << endl;
	
	for(int i=2; i<=cols-2; i++) {
		cout << grid[i][4] << " ";
	}
	
	return 0;
}
