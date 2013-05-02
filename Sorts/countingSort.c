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

//Sort that find the min and max in an array, and then creates a temp array for each instance of numbers from min to max, then counts all
// the instances of numbers, and finally inserts them into the original array from lowest to higest
void countingSortArray(int arr[])
{
	int i, min, max;
	min = arr[0]; max = arr[0]; //Set min and max to 1st element
	for (i = 1; i < SIZE; i++) //For every element past 1st
	{
		if(arr[i] < min) //if current element is less than 1st
			min = arr[i]; //set min to value of current element
		else if(arr[i] > max) //if current element is greater than 1st
			max = arr[i];	//set max to value of current element
	} //Found min and max values

	int range = max - min + 1; //Set range for count array
	int *count = calloc(range * sizeof(int), sizeof(int)); //Creating block of memory for array, (size of range * 1 byte, each element being 1 byte)
														   // and (attempts) to set all values to zero
	for(i = 0; i < range; i++) //Assures count array is set to zeros
		count[i] = 0;

	for(i = 0; i < SIZE; i++)  //Loop through randomArray
		count[arr[i] - min]++; //Add one to the value at countArray index = randomArray value place (min to max, each element corrsesponds
							   // to a potential value in randomArray, in a perfect world, count[0] = 1, count[1] = 2... etc.)

	int z = 0;
	for(i = min; i <= max; i++)  //From min to max
	{
		int j;
		for(j = 0; j < count[i - min]; j++) //For each instance that the randomArray value appears
			arr[z++] = i; //store sequenceially in randomArray, then increment index
	}

	free(count);  //Free memory that count array used
		
}

int main(int argc, char const *argv[])
{
	int numbersArray[SIZE];
	loadNumbersArray(numbersArray, 100); //Build array of random numbers from 1-100
	printf("Unsorted: \n");
	printArray(numbersArray); //Print unsorted array
	countingSortArray(numbersArray); //Execute sort function on array
	printf("\nSorted: \n");
	printArray(numbersArray); //Print sorted array
	return 0;
}
