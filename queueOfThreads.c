//This is an example of multi-threading by creating two seperate subroutines to push and pop the queue
// Both routines will have a form of communication betwen them to prevent from pushing and popping the same element at the same time

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //We can't incliude windows.h or process.h, so this is how we do real POSIX threading
#include <time.h>
#include <stdbool.h>
#include "queue.h"

//Function to tell the program to sit and wait equal to the number of milliseconds passed in.
void sleep(unsigned int mill)
{
	clock_t start = clock();  //Calling clock function, grabbing milliseconds that this process has been alive. (Common C headers)
	while(clock() - start < mill) { } //While the (current # of milliseconds a process has been alive, 
									  // minus the time it has started) is less than mill, we will sit and hold.
}

//Whether or not the fill thread is running
bool fillThreadRunning = false;
//Value will be true if something is processing the queue, "locks queue"
bool queueIsProcessing = false;


//All threads require void functions
void fillQThread(struct queue* localQ)
{
	fillThreadRunning = true;
	FILE* codeFile = fopen(__FILE__, "r");

	int c = 0, b; //c is count, b is byte (once we fill the file, or we reach the end of the queue)
	b = getc(codeFile);
	while(c < localQ->max || b != EOF) //While count is less than max or we have not reached EOF
	{
		sleep(rand() % 50); //Sleep randomly between 0 and 49 milliseconds
		while(queueIsProcessing) {} //While other routine is processing, just chill, as soon as it's done, jump in
		queueIsProcessing = true; //Lock for my local push
		pushQueue(localQ, b); //Passed in as a pointer, with the input value as the current byte in the file
		c++;
		b = getc(codeFile);
		queueIsProcessing = false; //Release
	}

	fclose(codeFile);
	fillThreadRunning = false;
	pthread_exit(NULL);
}


void popQThread(struct queue* localQ)
{
	sleep(10); //Setting this because it gives the other thread a "head start". Usually, we'd implement a 
				//check to see if the other thread has begun or not, then start based on that condition

	QUEUE_DATATYPE* popPtr = NULL;

	while(fillThreadRunning || localQ->count > 0)
	{
		while(queueIsProcessing) {} //While other routine is processing, just chill, as soon as it's done, jump in
		queueIsProcessing = true; //Lock for me
		popPtr = popQueue(localQ); //Set pop pointer
		if(popPtr != NULL) putchar(*popPtr); //if pointer is not NULL, print value at pointer
		queueIsProcessing = false; //Release
	}
	pthread_exit(NULL);
}



int main(int argc, char const *argv[])
{
	void *status;

	pthread_t thread1, thread2; //Declaring pthread type
	pthread_attr_t attr;

	//Initialize and set thread detached attribute
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	system("clear");
	srand(time(NULL));
	struct queue q;
	initQueue(&q);
		//windows-only BULLOCKS...
	//HANDLE fillThread = (HANDLE)_beginthread(fillQThread, 0, &q);
	//HANDLE popThread = (HANDLE)_beginthread(popQThread, 0, &q);
	//WaitForSingleObject(fillThread, 1000 * 300); //timeout
	//WaitForSingleObject(popThread, 1000 * 300); //timeout
	pthread_create(&thread1, &attr, fillQThread, &q);
	pthread_create(&thread2, &attr, popQThread, &q);
	pthread_attr_destroy(&attr);	
	pthread_join(thread2, &status);

	pthread_exit(NULL);

	return 0;
}
