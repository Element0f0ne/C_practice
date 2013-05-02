#include <stdio.h>
#define MAX_STACK_SIZE 255
//Creating bool data type
#define TRUE 1
#define FALSE 0
#define bool unsigned short int

//Define struct called stack and it's attributes/members
struct stack
{
	int *topOfStack;
	int *pointer;
	int count; //Number of element's currently pushed into stack array
	int max; //Max number of elements in stack array
	int theStack[MAX_STACK_SIZE];
};

void initStack(struct stack *stackStruct)
{
	stackStruct->topOfStack = stackStruct->theStack;
	stackStruct->pointer = stackStruct->theStack;
	stackStruct->max = MAX_STACK_SIZE;
	stackStruct->count = 0;
}

bool pushStack(struct stack *stackStruct, int inputValue)
{
	if (stackStruct->count < stackStruct->max) //If count of elements is less than max, keep pushing
	{
		*stackStruct->pointer = inputValue;
		stackStruct->count++;
		stackStruct->pointer++;  //This will increment pointer 1 element beyond set array
		return TRUE;
	}
	else
		return FALSE; //If count has reached max, stop pushing
}

int* popStack(struct stack *stackStruct)
{
	if(stackStruct->count > 0)
	{
		stackStruct->pointer--; //The first run of this is brining pointer back into set array and points to most recent element
		stackStruct->count--;
		return stackStruct->pointer;
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	struct stack s[4]; //create struct array of 4 stack structs
	int c = 1;
	int i;
	for (i = 0; i < 4; i++)  //Loop through each stack struct
	{
		initStack(&s[i]); //and initStack (set pointers)
		int j;
		for (j = 0; j < 3; j++) //For each stack array element, push value into it consecutivlely
		{
			pushStack(&s[i], c);
			c++;
		}
	}

	int *popValue;
	for (i = 0; i < 4; i++) //For every stack struct
	{
		popValue = popStack(&s[i]); //Set popValue to last element on stack
		while(popValue != NULL)
		{
			printf("s[%d] %d\n", i, *popValue); //Print pop value for each iteration
			popValue = popStack(&s[i]); //Move to next popValue (until no more are left/NULL)
		}
		putchar('\n'); //Print newline between each iteration
	}
	return 0;
}
