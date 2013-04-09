
#include <stdio.h>

int main()
{
	int value = 1234;
	int *n;
	n = &value;
	*n = *n + 1; //Adding 1 to the value of "value" using the pointer. So, because *n = the value of value,
				 //operations can be done to the pointer that actually affects the value of of the value variable.
	printf("value = %i\n", value);
	printf("n = %i\n", *n);

	int value2 = 4321;
	int *n1;//Declaring pointers n1 to n4
	int *n2;
	int *n3;
	int *n4;

	n1 = &value2;  //Setting pointer n1 to the memory address that holds the value of value2.
	n2 = n1;  	   //Setting pointer n2 = n1, which points to the memory address that holds the value of value2.
	n3 = n2;		//Keep going with n3 and n4.
	n4 = n3;

	printf("value2 = %i\n", value2);
	printf("n1 = %i\n", *n1);  //Prints the value of value2 since each pointer ultimately points to the memory address that
	printf("n2 = %i\n", *n2);  //holds the value of value2.
	printf("n3 = %i\n", *n3);
	printf("n4 = %i\n", *n4);
	return 0;
}
