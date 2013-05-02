#ifndef WIBIT_COMMAND_LINE_ARGS
#define WIBIT_COMMAND_LINE_ARGS
#include <stdlib.h>
#include <string.h>

int __argc; //Argument count
char** __args = NULL; //Holding command line args (array of char* / pointer of pointers)

void cmdArgsInit(int argc, const char *argv[]) //Initialize arguments
{
	int i;
	__argc = argc; //Grab count
	__args = (char**)calloc(argc, 8); //Allocate array with argument count # of elements, and each element is 8 bytes 

	for(i = 0; i < argc; i++) //for every argument
	{
		__args[i] = (char*)calloc(strlen(argv[i]), 8); //Allocate 2nd dimension array in each element of first that are lenth of current argv and 8 bytes
		strcpy(__args[i], argv[i]);
	}
}


void cmdArgsClean() //Free's up memory created from Init
{
	int i;
	for(i = 0; i < __argc; i++) //Loop through argc
		free(__args[i]); //Free element
	free(__args); //Free argument array
}


unsigned short int cmdArgsIsSwitchValued(char* switchTarget) //Find if switch is valid
{
	int i;
	for(i = 0; i < __argc; i++) //Loop through array of arguments
		if(strcmp(__args[i], switchTarget) == 0) //Compare argument to target
			return 1;
	return 0;
}


void cmdArgsStoreArgument(char* strBuffer, char* switchTrigger)
{
	int i;
	for(i = 0; i < __argc; i++)
	{
		if(strcmp(__args[i], switchTrigger) == 0 && (i+1) < __argc) //Protects from extending the bound of the array
		{
			strcpy(strBuffer, __args[i+1]); //Copy value of argument into buffer
			return;
		}
	}
	strcpy(strBuffer, "");
}

char* cmdArgsGetArgument(char* switchTrigger)
{
	int i;
	for(i = 0; i < __argc; i++)
	{
		if(strcmp(__args[i], switchTrigger) == 0 && (i+1) < __argc) //Protects from extending the mound of the array
		{
			return __args[i+1]; //Return value of argument
		}
	}
	return "";
}

#endif

