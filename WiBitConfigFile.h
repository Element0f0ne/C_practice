#ifndef WIBIT_CONFIG_FILE
#define WIBIT_CONFIG_FILE
#define CFG_FILE_BUFFER_SIZE 2048
#include "WiBitLib.h"

FILE* _configFilePtr = NULL;

//Function to initialize file for use from calling program
bool configFileSet(char* filePath)
{
	if(!fileExists(filePath))
		return false;
	_configFilePtr = fopen(filePath, "r");
		return true;
}

//Parsing function to grab variables
bool configFileStore(char* buffer, char* variableName)
{
	if(_configFilePtr == NULL)
		return false;

	char fileBuffer[CFG_FILE_BUFFER_SIZE];
	char fileVariableName[255];
	int visitIndex;
	int i;

	

	while(!feof(_configFilePtr)) //While not at end of file
	{
		fgets(fileBuffer, CFG_FILE_BUFFER_SIZE, _configFilePtr); //store file into buffer	
		chomp(fileBuffer); //Cut off newline and carriage return

		if(strlen(fileBuffer) == 0) //Skip if file is empty
			continue;

		if(fileBuffer[0] = '#')
			continue;

		visitIndex = getIndexOf(fileBuffer, '='); //Get index of =
		if(visitIndex < 0) //If there are not ='s
			continue;

		for(i = 0; i < visitIndex; i++) //Between the first char and the equal
			fileVariableName[i] = fileBuffer[i]; //Store variable name

		fileVariableName[i] = '\0'; //Set variable to NULL

		if(strcmp(fileVariableName, variableName)) //Skip variables already stored
			continue;

		i = 0;
		for(++visitIndex; visitIndex < strlen(fileBuffer); visitIndex++) //For every char in variable name starting at char after =
		{
			buffer[i] = fileBuffer[visitIndex]; //Store each char of variable
			i++; //Move to next char in variable
		}
		buffer[i] = '\0'; //Set last char to \0
		break;
	}
	rewind(_configFilePtr); //set file pointer back to start of file
	return true;
}

#endif

