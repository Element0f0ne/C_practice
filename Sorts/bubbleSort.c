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

//Bubble sort
void bubbleSortArray(int arr[])
{
	int i;
	for (i = 0; i < SIZE; i++) //Loop through array
	{
		if ((i < SIZE - 1) && (arr[i] > arr[i+1])) //If iteration is less than SIZE-1 (if we're not at the end of the array)
												   // and current element is greater than the next element
		{
			arr[i] ^= arr[i+1]; //bitwise XOR compare that swaps two values, creates "key" to then compare to arr[i+1]
			arr[i+1] ^= arr[i]; //bitwise XOR compare that swaps two values, creates original arr[i] value, stores in arr[i+1]
			arr[i] ^= arr[i+1]; //bitwise XOR compare that swaps two values, creates original arr[i+1] value. stores in arr[i]
			i = -1; //Set count to -1 (resets for-loop to go back to start of array)
		}
	}
}

int main(int argc, char const *argv[])
{
	int numbersArray[SIZE];
	loadNumbersArray(numbersArray, 100); //Build array of random numbers from 1-100
	printf("Unsorted: \n");
	printArray(numbersArray); //Print unsorted array
	bubbleSortArray(numbersArray); //Execute bubble sort function on array
	printf("\nSorted: \n");
	printArray(numbersArray); //Print sorted array
	return 0;
}





