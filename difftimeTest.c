#include <stdio.h>
#include <time.h>

//Same as clock test in terms of finding diffference between start and end time, but using difftime instead
int main(int argc, char const *argv[])
{
	time_t startTime = time(NULL); //Set start to current UNIX time

	long i;
	for(i = 0; i < 999999999; i++) {} //Loop for a bit
	time_t endTime = time(NULL); //Set endTime to current UNIX time at this point

	printf("Time diff: %f\n", difftime(endTime, startTime)); //Precise difference between two time_t values, in this case, end and start time
	return 0;
}