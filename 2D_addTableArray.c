#include <stdio.h>

int main(int argc, char const *argv[])
{
	//declaring constants for # of rows and columns because array size can't be allocated at runtime
	const int rows = 3, cols = 5;
	//Create array
	int additionTable[rows][cols];

	for (int i = 0; i < rows; i++) //For every row
	{
		for (int j = 0; j < cols; j++) //For every column
		{
			additionTable[i][j] = i + j; //Add current values of i and j together, and store at additionTable[i][j] 
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d", additionTable[i][j]);  //Print addition table
		}
		printf("\n");
	}
	return 0;
}