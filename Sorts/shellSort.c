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

void shellSortArray(int arr[])
{
	int j, i, k, m;
	for (m = SIZE/2; m > 0; m = m/2) //For loop start at middle of array, stop at beginning, split array in half on each iteration
	{
		for(j = m; j < SIZE; j++) //For loop gets element at middle of array, 
		{
			for (i = j - m; i >= 0; i = i - m) //For loop that gets first element in first half of array
			{
				if(arr[i+m] >= arr[i]) //If middle element is greater than first element, break, fall back, iterate j
					break;
				else //Swap the elements
				{
					arr[i] ^= arr[i+m]; //bitwise XOR compare that swaps two values, creates "key" to then compare to arr[i+m]
					arr[i+m] ^= arr[i]; //bitwise XOR compare that swaps two values, creates original arr[i] value, stores in arr[i+m]
					arr[i] ^= arr[i+m]; //bitwise XOR compare that swaps two values, creates original arr[i+m] value. stores in arr[i]
				}
			}
		}	
	}
}

int main(int argc, char const *argv[])
{
	int numbersArray[SIZE];
	loadNumbersArray(numbersArray, 100); //Build array of random numbers from 1-100
	printf("Unsorted: \n");
	printArray(numbersArray); //Print unsorted array
	shellSortArray(numbersArray); //Execute sort function on array
	printf("\nSorted: \n");
	printArray(numbersArray); //Print sorted array
	return 0;
}





