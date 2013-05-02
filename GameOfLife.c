#include <stdio.h>
#include <time.h>
#define ROWS 20
#define COLS 79

int generation = 0;
int population = 0;
int populationMax = 0;
int populationMin = 0;
int tempGrid[ROWS][COLS];  //Needed for "two arrays" (build grid and live/active grid)

int getUserInput();
void initGrid(int, int, int[ROWS][COLS]);  //First int is ROWS, second is COLS, third sets. Compiler needs to know how big the array is
void processGeneration(int, int, int[ROWS][COLS]); 
int countNeighbors(int, int, int[ROWS][COLS], int, int); //pass in ROWS and COLS, then set them, then X and Y coords of neighbor.
void printGrid(int, int, int[ROWS][COLS]);
void sleep(unsigned int);

int main(int argc, char const *argv[])
{
	srand((unsigned int) time(NULL)); //Takes the current time and uses it as a seed for the random number generator
	int grid[ROWS][COLS]; //Make grid
	initGrid(ROWS, COLS, grid); //Initialize grid
	printGrid(ROWS, COLS, grid); //Print grid to screen

	int i, g;
	g = getUserInput();

	for (i = 0; i < g; i++)
	{
		generation++;
		processGeneration(ROWS, COLS, grid);
		printGrid(ROWS, COLS, grid);
		sleep(100);
	}
	return 0;
}


//Function tht simply grabs the amount of generations the player wants to watch.
int getUserInput()
{
	int g;
	printf("Thanks for playing The Game of Life!\n");
	printf("How many generations do you want to watch? ");
	scanf("%d", &g);
	return g;
}


//Function that initializes grid. Takes # of rows, # of columns and int array as arguments.
void initGrid(int rows, int cols, int g[rows][cols])
{
	int i, j, k;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			/*
				This is a common grid because it allows you to ignore accounting for corners, or going out of array bounds.
			 [-1] [-1] [-1] [-1] [-1]
			 [-1] [  ] [  ] [  ] [-1]
			 [-1] [  ] [  ] [  ] [-1]
			 [-1] [-1] [-1] [-1] [-1]
			*/
			 if (i == 0 || i == (rows - 1) || j == 0 || j == (cols - 1)) //Sets first and last rows/cols to -1 to create container.
			 	g[i][j] = -1;
			 else	//Else will target inner cells (playable area).
			 {
			 	k = rand() % 3; //One in three chance that the cell will be valued. Random number from 0 to 2.
			 	if(k == 0)
			 	{
			 		g[i][j] = 1;  //Fill cell with 1, which represents a person.
			 		population++;  //Add one to our population count
			 	} 
			 	else g[i][j] = 0;
			 }
		}
	}
	processGeneration(rows, cols, g);
}


//Function that determines save, kill or born action based on neighbors for each generation
void processGeneration(int rows, int cols, int g[rows][cols])
{
	int i, j, neighbors;
	for (i = 0; i < rows; i++)  //Loop to determine death of existing person or birth of new person.
	{
		for(j = 0; j < cols; j++)
		{
			if(g[i][j] == -1) continue; //Checks if border cell, if so, stop and go on to the next iteration (moves to next cell in loop).
			neighbors = countNeighbors(rows, cols, g, i, j);  //Finds # of neighbors for the cell we're on

			if(g[i][j] == 1 && (neighbors < 2 || neighbors > 3)) //If person is alive and has <2 or >3 neighbors, 
				tempGrid[i][j] = 0;  //person dies.
			else if((g[i][j] == 0) && (neighbors == 3))  //If cell is empty, and has exactly 3 neighbors,
				tempGrid[i][j] = 1; // a person is born.
		}
	}

	population = 0; //Reset population temporarily
	for (i = 0; i < rows; i++) //Loop to fill real grid from temp grid and set new population
	{
		for(j = 0; j < cols; j++)
		{
			if(g[i][j] == -1) continue; //Checks if border cell, if so, stop and go on to the next iteration (moves to next cell in loop).
			if(tempGrid[i][j] == 1) population++; //If person is alive, add to population count.
			g[i][j] = tempGrid[i][j]; //Cell in real grid will get overwritten with cell in temp grid
		}
	}
	//Keep track of popMax and popMin to see our lowest and highest populations
	if(population > populationMax)	//If pop reaches highest count, store into new popMax
		populationMax = population; 
	if(population < populationMin || populationMin == 0) //If pop reaches lowest count, store into new popMin
		populationMin = population;
}


//Function to count neighbors based on current cell
int countNeighbors(int rows, int cols, int g[rows][cols], int x, int y) //Pass in values of size of int array, int array, and x/y of current cell
{
	/*
	X is cell in question, start by moving back one cell, up one cell, then scanning the row.
		Everytime you see a 1 in the row, add one to the neighbors, see a 0, do nothing, and -1, we don't count it.
		Then move to next row, but only allow first and last to be counted.
		Then move to last row, and do same process as first row.

	[ ] [ ] [ ]
	[ ] [X] [ ]
	[ ] [ ] [ ]
	*/
	int n = 0, i, j; //# of neighbors
	//For loop that moves through playable grid by avoiding out of bounds cells. (From POV of active cell by passing X/Y coords).
	for(j = y - 1; j < y + 2; j++) //Up a row, if j is greater than 2, it's outside of range.
	{
		for(i = x - 1; i < x + 2; i++) //Left a col, if i is greater than 2, it's outside of range.
		{
			if(i == x && j == y) continue;  //If we're on active position, stop and move to next cell 
			if(g[i][j] != -1) n+= g[i][j]; //If cell is not -1, add current value (0 or 1 in this case) to n (neighbor count).
		}
	}
	return n;  //Returns number of neighbors
}

//Function that will print the grid to the screen
void printGrid(int rows, int cols, int g[rows][cols])
{
	system("clear"); //Allows you to execute a command on the command prompt, in this case, running "clear" on the command prompt
	printf("Welcome to the Game of Life -- Generation: %d\n", generation);
	printf("Population: %d (MAX: %d MIN: %d)\n", population, populationMax, populationMin);

	int i, j;
	for(i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			switch(g[i][j])
			{
				case -1: putchar('+'); break;
				case  0: putchar(' '); break;
				case  1: putchar('$'); break;
				default: break;
			}
		}
		putchar('\n');
	}
}


//Function to tell the program to sit and wait equal to the number of milliseconds passed in.
void sleep(unsigned int mill)
{
	clock_t start = clock();  //Calling clock function, grabbing milliseconds that this process has been alive. (Common C headers)
	while(clock() - start < mill) { } //While the (current # of milliseconds a process has been alive, 
									  // minus the time it has started) is less than mill, we will sit and hold.
}
