#include <stdio.h>
#define LENGTH_OF_WEEK 7 //Pre-proccessor directive

int main(int argc, char const *argv[])
{
	int daysOfWeek[LENGTH_OF_WEEK] = {0,1,2,3,4,5,6};
	int offset = 0; //set for what day of the week you want your week to start
	char* dayName = NULL;

	int i;
	for (i = 0; i < LENGTH_OF_WEEK; ++i) //Loop through daysOfWeek array
	{
		switch (daysOfWeek[(i+offset) % 7]) //switch statement determines what value (day) 
											//equals what array index value (daysOfWeek[i]) and sets it
		{
			case 0: dayName = "Sunday"; break;
			case 1: dayName = "Monday"; break;
			case 2: dayName = "Tuesday"; break;
			case 3: dayName = "Wednesday"; break;
			case 4: dayName = "Thursday"; break;
			case 5: dayName = "Friday"; break;
			case 6: dayName = "Saturday"; break;
		}
		printf("Today is the greatest, day I've ever known... it's %s\n", dayName); //Prints array
	}
	return 0;
}