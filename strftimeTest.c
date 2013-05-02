#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	time_t rawTime;
	if(argc == 1) //If no agurments, use current UNIX time
		rawTime = time(NULL);
	else
		rawTime = atoi(argv[1]); //Else, use argument (UNIX time), and convert ASCII to int

	struct tm *sTime = localtime(&rawTime); //Create time struct pointer called sTime, from the result of localtime(argument)
	char strBuffer[255]; //Create string buffer of size 255 chars

	strftime(strBuffer, 255, "%Y/%m/%d %H:%M:%S", sTime); //strftime takes char array, size, format, and time struct
	puts(strBuffer); //Puts string to screen
	return 0;
}