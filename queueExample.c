/* This is a simple example of a queue, but the problem is that this is a one dimensional, single purpose type of queue.
	see queue.h and queue.c for the more robust, practical implementation of the queue data structure
*/

#include <stdio.h>
#define MAX_QUEUE_SIZE 255

struct queue
{
	int *pointer;
	int currentValue;
	int count;
	int max;
	int theQueue[MAX_QUEUE_SIZE];
};

void initQueue(struct queue *queueStruct)
{
	queueStruct->max = MAX_QUEUE_SIZE;
	queueStruct->pointer = queueStruct->theQueue;
	queueStruct->count = 0;
}

int pushQueue(struct queue *queueStruct, int inputValue)
{
	if(queueStruct->count < queueStruct->max)
	{
		*queueStruct->pointer = inputValue;
		queueStruct->count++;
		queueStruct->pointer++; //This increments pointer to one element beyond set array
		return 1;
	}
	else
		return 0;
}

//Key difference from stack (FIFO)
int popQueue(struct queue *queueStruct)
{
	if(queueStruct->count > 0)  //If elements are greater than 0
	{
		queueStruct->currentValue = *queueStruct->theQueue; //Set current value equal to last element (most recent); (already pushed values)
		queueStruct->count--; //Remove element from count
		queueStruct->pointer--; //First run will bring pointer back into set array, pointing to last element (most recent)

		//After we pop the value
		int i;
		for (i = 0; i < queueStruct->count; i++) //For each remaining element, shift them forward
		{
			int *currentPointer = queueStruct->theQueue + i; //set current pointer to oldest value (theQueue[0]+0, then theQueue[0]+1)
			int *nextPointer = currentPointer + 1; //set next pointer to the value after oldest value
			*currentPointer = *nextPointer; //Set curren pointer to the new value
		}
		return queueStruct->currentValue;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	struct queue q; //Create 1 queue
	initQueue(&q); //Init pointers/attirbutes
	pushQueue(&q,1); //Push 1
	pushQueue(&q,2); //Push 2
	pushQueue(&q,3); //Push 3

	int popValue = popQueue(&q); //Set popValue = to most first element (most recent)

	while(popValue != -1) //While element exists
	{
		printf("%d\n", popValue); //print to screen
		popValue = popQueue(&q); //Move to next pop value
	}
	return 0;
}
