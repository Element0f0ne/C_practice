#include <stdio.h>
#include "WiBitCommandLineArgs.h"
#include "WiBitConfigFile.h"

int main(int argc, const char *argv[])
{
	cmdArgsInit(argc, argv);

	configFileSet(cmdArgsGetArgument("-c"));

	char testParam[255];
	configFileStore(testParam, "testParam");

	puts(testParam);
	
	cmdArgsClean();
	return 0;
}