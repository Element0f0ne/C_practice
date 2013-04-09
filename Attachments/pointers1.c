#include <stdio.h>

int main()
{
	//NOT CORRECT USAGE, JUST SHOWING "THIS IS A POINTER"
	int *n; //Define the pointer
	*n = 20; //Assign the pointer. The memory address that the pointer points to, now holds a value of 20.
			 //This would normally be an existing variable's memory address in the form of "n = &variable"
	printf("%d\n", *n); //Prints the value of the memory address that *n points to.
	printf("%d\n", n);  //Prints the (%d) integer representation of the pointer's
					    //memory location. (pointer is binary value) [gcc warning]
	return 0;
}