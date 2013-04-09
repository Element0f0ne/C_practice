
#include <stdio.h>
int main()
{
	int *p;  //Declare pointer
	int n;   //Declare regular variable
	*p = 100;  //Assign pointer value 200 at a memory location
	n = 200; //Assign literal n = 200
	printf("Address [%p] = [%d]\n", p, *p); //Prints HEX value of pointer's memory address it points to (%p for p)
											// and the value stored in that memory location (%d for *p)
	
	printf("Address [%p] = [%d]\n", &n, n); //Prints HEX value of actual variable's memory address, and the value
											// stored in that memory location.
											// (No pointer used, but shows memory address of variable)
	return 0;
}
