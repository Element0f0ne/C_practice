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

//Sort that starts at first element, and closes "gap" from lst element while comparing values to be sorted
void combSortArray(int arr[])
{
	int gap = SIZE, swaps = 1, i = 0;
	while(gap > 1 || swaps == 1) //Initially set gap to length of array, and while swaps are left
	{
		gap = (int)((float)gap / 1.247330950103979); //Setting gap size
		if(gap < 1) //If gap goes below 1, set to 1
			gap = 1;
		i = 0;
		swaps = 0; //set iteration's swap to 0 intially
		for(i = 0; i + gap < SIZE; i++) //Start at 1st element, end at last element
		{
			if(arr[i] > arr[i+gap]) //If 1st element is greater than last element, swap them
			{
				arr[i] ^= arr[i+gap]; //bitwise XOR compare that swaps two values, creates "key" to then compare to arr[i+gap]
				arr[i+gap] ^= arr[i]; //bitwise XOR compare that swaps two values, creates original arr[i] value, stores in arr[i+gap]
				arr[i] ^= arr[i+gap]; //bitwise XOR compare that swaps two values, creates original arr[i+gap] value. stores in arr[i]
				swaps = 1; //Set swap to 1
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
	combSortArray(numbersArray); //Execute sort function on array
	printf("\nSorted: \n");
	printArray(numbersArray); //Print sorted array
	return 0;
}
