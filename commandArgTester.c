#include <stdio.h>
#include "WiBitCommandLineArgs.h"

int main(int argc, char const *argv[])
{
	char buffer[255];
	CmdArgsInit(argc,argv);

	if(CmdArgsIsSwitchValued("-p"))
	{
		CmdArgsStoreArgument(buffer, "-p");
		puts(buffer);
	}

	CmdArgsClean();
	return 0;
}