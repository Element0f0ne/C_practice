#include <stdio.h>

void recTest(int i) //Simple recursive function
{
	if(i > 0) //If i is greater than 0, call recTest(i-1)
	{
		recTest(i-1);	//Calling self, passing one less the current value as the current value
		printf("%d\n", i); //Command put on stack for each i, but then "pops" off in reverse order ((LIFO) Last In, First Out)
						   // after if check returns false.
	}
}

int main(int argc, char const *argv[])
{
	recTest(5);
	return 0;
}