#include <stdio.h>
#include <string.h>

typedef int bool;  //creating bool data type typedef'd from int
#define TRUE 1
#define FALSE 0

bool containsDuplicates(char*);

int main(int argc, char const *argv[])
{
	char string[255];
	strcpy(string, argv[1]);

	printf("Does your string, %s contains duplicates? %d\n", string, containsDuplicates(string)); 
	return 0;
}


//function to scan through a string and fine duplicate characters (example of O(N^2))
bool containsDuplicates(char* string)
{
	int i;
	for (i = 0; i < strlen(string); i++)
	{	
		int j;
		for (j = 0; j < strlen(string); j++)
		{
			if (i == j) //Don't compare char with itself
				continue;
			if (string[i] == string[j])
				return TRUE;
		}
	}
	return FALSE;
}