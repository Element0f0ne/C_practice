#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	time_t myTime = 0;
	if(argc == 1)
		time(&myTime); //If no argument was passed, find current time, and store in myTime
	else myTime = atoi(argv[1]); //Else, use the value passed in, converting ASCII to int

	struct tm *TIME = localtime(&myTime); //Declare time struct pointer called TIME, and use localtime to convert single argument and fill struct

	printf("Day of the Year: %d\n", TIME->tm_yday + 1); //Add one due to day of years starting at 0
	printf("Year: %d\n", TIME->tm_year + 1900); //Add 1900 because year attribute starts at 1900, so we need to count up from 1900
	printf("Month: %d\n", TIME->tm_mon + 1); //Add 1 again because months of year start at 0
	printf("Day: %d\n", TIME->tm_mday); //For some reason days do start at 1 and go to 31. DAY ZERO IS A LIE

	printf("Hour: %d\n", TIME->tm_hour);
	printf("Minute: %d\n", TIME->tm_min);
	printf("Second: %d\n", TIME->tm_sec);
	printf("Day of Week: ");
	switch(TIME->tm_wday)		//tm_wday goes from index 0 - 6, we assign Sunday at 0, etc.
	{
		case 0: printf("Sunday\n"); break;
		case 1: printf("Monday\n"); break;
		case 2: printf("Tuesday\n"); break;
		case 3: printf("Wednesday\n"); break;
		case 4: printf("Thursday\n"); break;
		case 5: printf("Friday\n"); break;
		case 6: printf("Saturday\n"); break;
		default: printf("UNKNOWN\n"); break;
	}
	
	return 0;
}