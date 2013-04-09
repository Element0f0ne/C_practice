#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int shift = atoi(argv[1]); //ASCII to int conversion, storing amount of shift passed from 1st argument into "shift"

	char message[255]; 
	strcpy(message, argv[2]); //Copying argument two (message to be shifted) into message char array

	int i;
	for (i = 0; i < strlen(message); i++)  //For each character in message
	{
		printf("%c", message[i] + shift);  //output it's ASCII value shifted (negative = backwards shift)
	}
	putchar('\n'); //Newline
	return 0;
}