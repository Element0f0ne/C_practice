/*This example shows a stack data structure, but is limited to "one" stack for example purposes.  The global variables and pointers
  represent the stack and the ways to keep up with it.
  --SEE stackExample2.c for practical implementation using structures for multiple stacks--
*/

#include <stdio.h>
#define MAX_STACK_SIZE 5 //symbolic constant
int *topOfStack; //References top of stack (first value)
int *pointer; //Reference current value (most recent)
int theStack[MAX_STACK_SIZE];

//Set both top and current pointer to first element in stack array
void initStack()
{
	topOfStack = theStack;
	pointer = theStack;
}

//Push value into stack
void pushStack(int inputValue)
{
	if(pointer != topOfStack + MAX_STACK_SIZE) //If current value hasn't extended max size (length of array)
	{
		*pointer = inputValue; //Set pointer to the value of inputValue (changes the element's value to inputValue)
		pointer++; //Move to the next pointer's memory address (which is the next element of the array)
	}				//NOTE: These lines use the pointer's int values as conditionals because we're filling the array with ints
					// If we used strings, The pointer's string value's would be conditionals + awareness of array positions
}

//Pop value off stack
int* popStack()
{
	if(pointer != topOfStack) //If current pointer doesn't point to oldest element
	{
		pointer--; //Move pointer backwards to oldest element (pointer++ and -- will move along the array)
		return pointer; //Due to the nature of this example program, this is with the understanding the pointer has been "pushed"
						//out of bounds of the array (the next mem address of unknown value), but decremented back "into" the array
						//by going back to the previous mem address that contains the last array element
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	initStack(); //Set stack pointers
	int i;
	for (i = 0; i < MAX_STACK_SIZE; i++) //Fill stack from 0 to 4
		pushStack(i);

	int *popValue = popStack(); //Set pop value (first one in, last one out) (Again, it's 4 because we use ints, otherwise, we'd use index values)
	while(popValue != NULL) //Starting at newest value, pop value out to screen
	{
		printf("%d\n", *popValue);
		popValue = popStack();
	}
	return 0;
}

