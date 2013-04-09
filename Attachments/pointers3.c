
#include <stdio.h>

int main()
{
	int value = 1234; //Declare variable and value
	int *n;  //Declare pointer
	n = &value;  //Set pointer to point to the memory address of the variable "value"
	printf("value = %i\n", value); //Print the actual variable's value (named value)
	printf("n = %i\n", *n); //Print the value of the variable (named value) using the pointer (which points to the value of "value")
	return 0;
}
