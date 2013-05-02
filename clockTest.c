#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	clock_t start;
	clock_t end;
	clock_t clockTicks;

	start = clock(); //Returns # of milliseconds since process execution
	clockTicks = start / CLOCKS_PER_SEC; //Dividing by this macro stores time in seconds
	printf("Start time: %ld seconds.\n", clockTicks);
	long i;
	for(i = 0; i < 5432109876; i++) {} //Loop running an amount of time
	end = clock(); //Captures the # of milliseconds since process exection at this point
	clockTicks = end / CLOCKS_PER_SEC; //Dividing by this macro stoes time in seconds
	printf("End time: %ld seconds.\n", clockTicks);

														//Elapsed time by subtracting start from end and dividing my macro to view seconds
	printf("Time elapsed during program execution: %ld seconds.\n", (end - start) / CLOCKS_PER_SEC);

	return 0;
}