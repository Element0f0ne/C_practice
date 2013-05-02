#ifndef WIBIT_GENERIC_LIB
#define WIBIT_GENERIC_LIB

#define MEM_CHAR 8

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Function to test whether file exists*/
bool fileExists(char* filePath)
{
	FILE* f = fopen(filePath, "r");
	if(!f)
		return false;
	fclose(f);
	return true;
}

/*Function to remove newline or return character from char*, and make sure there's a NULL terminator at the end (\0) */
void chomp(char* s)
{
	int endOfString = strlen(s) - 1; //-1 because we want to skip the NULL character at the end
	if(endOfString >= 0 && (s[endOfString] == '\n') || (s[endOfString] == '\r'))
		s[endOfString] = '\0';
}

/*Clears vector*/
void freeVector(char** inputV, int length)
{
	int i;
	for(i = 0; i < length; i++)
		free(inputV[i]);

	free(inputV);
}

//Function to split a string (Must deallocate this once it's done using freeVector)
char** splitString(int* length, char* inputString, char* splitToken)
{
	int i = 0;
	char* tmpStr = (char*)calloc(strlen(inputString) + 1, MEM_CHAR); //Creating copy of string for counting
	strcpy(tmpStr, inputString);

	char* token = strtok(tmpStr, splitToken); //Create token by splitting string at every spltToken char
	*length = 0;

	while(token != NULL)
	{
		*length = *length + 1; //Count up length of tokens
		token = strtok(NULL, splitToken); //Cut again until NULL
	}

	free(tmpStr); //Free tmpStr used for counting
	tmpStr = (char*)calloc(strlen(inputString) + 1, MEM_CHAR); //New copy of string for interting tokens into list array
	strcpy(tmpStr, inputString);

	char** list = (char**)calloc(*length, MEM_CHAR); //New char* array
	token = strtok(tmpStr, splitToken); //Create another token

	for(i = 0; i < *length; i++)
	{
		list[i] = (char*)calloc(strlen(token) + 1, MEM_CHAR); //for each element in list array
		strcpy(list[i], token); //Copy token into element
		token = strtok(NULL, splitToken); //split again
	}
	free(tmpStr); //Free tmp
	return list;
}

int getIndexOf(char* inputString, char seekChar)
{
	int i;
	for(i = 0; i < strlen(inputString); i++)
	{
		if(inputString[i] == seekChar)
			return 1;
	}
	return -1;
}

#endif
