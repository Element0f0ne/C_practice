/*
##      ## #### ########  #### ########     ##    ## ######## ######## 
##  ##  ##  ##  ##     ##  ##     ##        ###   ## ##          ##    
##  ##  ##  ##  ##     ##  ##     ##        ####  ## ##          ##    
##  ##  ##  ##  ########   ##     ##        ## ## ## ######      ##    
##  ##  ##  ##  ##     ##  ##     ##        ##  #### ##          ##    
##  ##  ##  ##  ##     ##  ##     ##    ### ##   ### ##          ##    
 ###  ###  #### ########  ####    ##    ### ##    ## ########    ## 
*/
#ifndef WIBIT_COMMAND_LINE_ARGS
#define WIBIT_COMMAND_LINE_ARGS
#include <stdlib.h>
#include <string.h>

int __argc;
char** __args = NULL;

void CmdArgsInit(int argc, const char* argv[])
{
	int i;
	__argc = argc;
	__args = (char**)calloc(argc, 8);
	for(i = 0; i < argc; i++)
	{
		__args[i] = (char*)calloc(strlen(argv[i]), 8);
		strcpy(__args[i], argv[i]);
	}
}
/* ******************************************** */
void CmdArgsClean()
{
	int i;
	for(i = 0; i < __argc; i++)
		free(__args[i]);
	free(__args);
}
/* ******************************************** */
unsigned short int CmdArgsIsSwitchValued(char* switchTrigger)
{
	int i;
	for(i = 0; i < __argc; i++)
		if(strcmp(__args[i], switchTrigger) == 0) return 1;
	return 0;
}
/* ******************************************** */
void CmdArgsStoreArgument(char* strBuffer, char* switchTrigger)
{
	int i;
	for(i = 0; i < __argc; i++)
	{
		if(strcmp(__args[i], switchTrigger) == 0 && (i + 1) < __argc)
		{
			strcpy(strBuffer, __args[i + 1]);
			return;
		}
	}
	strcpy(strBuffer, "");
}
/* ******************************************** */
char* CmdArgsGetArgument(char* switchTrigger)
{
	int i;
	for(i = 0; i < __argc; i++)
	{
		if(strcmp(__args[i], switchTrigger) == 0 && (i + 1) < __argc)
			return __args[i + 1];
	}
	return "";
}
/* ******************************************** */

#endif