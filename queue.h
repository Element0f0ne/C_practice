// This will differ in that we will be able to take in any kind of data type. (Change the data type we use, based on a pre-processer directive)
// Also, this shows a normal way of program design by using the header file and c file appropriately

#ifndef WIBIT_QUEUE
#define WIBIT_QUEUE
#include <stdbool.h>

#define MAX_QUEUE_SIZE 1024
#define QUEUE_DATATYPE char  //Set queue datatype, which can be changed to anything. It will simply be inserted into array as that type and 
							 //pushed & popped as usual.

struct queue
{
	QUEUE_DATATYPE *pointer;
	QUEUE_DATATYPE currentValue;
	int count;
	int max;
	QUEUE_DATATYPE theQueue[MAX_QUEUE_SIZE];
};


void initQueue(struct queue *queueStruct)
{
	queueStruct->max = MAX_QUEUE_SIZE;
	queueStruct->count = 0;
	queueStruct->pointer = queueStruct->theQueue;
}


bool pushQueue(struct queue *queueStruct, QUEUE_DATATYPE inputValue)
{
	if(queueStruct->count < queueStruct->max)
	{
		*queueStruct->pointer = inputValue;
		queueStruct->count++;
		queueStruct->pointer++;
		return true;
	}
	else
		return false;
}


QUEUE_DATATYPE* popQueue(struct queue *queueStruct)
{
	int i;
	QUEUE_DATATYPE* currentPointer = NULL;
	QUEUE_DATATYPE* nextPointer = NULL;

	if(queueStruct->count > 0)
	{
		queueStruct->currentValue = queueStruct->theQueue[0]; //Set current value to first element
		queueStruct->count--;
		queueStruct->pointer--;

		for (i = 0; i < queueStruct->count; i++)
		{
			currentPointer = queueStruct->theQueue + i;
			nextPointer = currentPointer + 1;
			*currentPointer = *nextPointer;
		}
		return &queueStruct->currentValue;
	}
	else
		return NULL;
}

#endif
