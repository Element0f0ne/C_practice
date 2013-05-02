#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
	struct queue q;
	initQueue(&q);
	int i;
	for (i = 0; i < 5; i++) //How many element's we're pushing (5 in this case)
		pushQueue(&q, i + 65); //For the "char" type, we are pushing i+65 because we wan't to start at "A" (65 is int value of A)

	char* pValue = popQueue(&q);
	while(pValue != NULL)
	{
		printf("%c\n", *pValue);
		pValue = popQueue(&q);
	}
	return 0;
}