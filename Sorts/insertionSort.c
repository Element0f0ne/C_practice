#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

//Creating random number generator
void randomizeTimer()
{
	time_t seconds; //time_t is a C data type that describes time since epoch (UNIX time, or UTC, January 1 1970)
	time(&seconds); //time function function that takes time_t as a parameter and returns time as current calendar time
	srand((unsigned int) seconds); //seeding random number generator using time as it's parameter
}

//loading random numbers into array that is SIZE large, and given a max random int
void loadNumbersArray(int arr[], int max)
{
	randomizeTimer();
	int i;
	for(i = 0; i < SIZE; i++)  //For every element of the array,
		arr[i] = rand() % max + 1;  //assign random number between 1 and max.
}

//Prints array
void printArray(int arr[])
{
	int i;
	for(i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);
}


//
void insertionSortArray(int arr[])
{
	int i;
	for (i = 1; i < SIZE; i++) //For loop that starts at 1
	{
		int value = arr[i]; //Set's value to 2nd element
		int j = i - 1; //Sets j = to 1st element
		int done = 0; //end while condition
		do
			{
				if (arr[j] > value) //If 1st element is greater than 2nd element
				{
					arr[j+1] = arr[j]; //Store 2nd element's value into 1st element
					j--;
					if(j < 0) //Also, now if j is less than 0, set end while condition to true
						done = 1;
				}
				else
					done = 1; //Else, end while loop
			} while (!done);
			arr[j+1] = value; //Keep 2nd element's value in the same location
	}
}

int main(int argc, char const *argv[])
{
	int numbersArray[SIZE];
	loadNumbersArray(numbersArray, 100); //Build array of random numbers from 1-100
	printf("Unsorted: \n");
	printArray(numbersArray); //Print unsorted array
	insertionSortArray(numbersArray); //Execute sort function on array
	printf("\nSorted: \n");
	printArray(numbersArray); //Print sorted array
	return 0;
}


