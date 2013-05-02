/*
##      ## #### ########  #### ########     ##    ## ######## ######## 
##  ##  ##  ##  ##     ##  ##     ##        ###   ## ##          ##    
##  ##  ##  ##  ##     ##  ##     ##        ####  ## ##          ##    
##  ##  ##  ##  ########   ##     ##        ## ## ## ######      ##    
##  ##  ##  ##  ##     ##  ##     ##        ##  #### ##          ##    
##  ##  ##  ##  ##     ##  ##     ##    ### ##   ### ##          ##    
 ###  ###  #### ########  ####    ##    ### ##    ## ########    ## 
*/
#include <stdio.h>
#include "wibitcommandlineargs.h"
#include "wibitconfigfile.h"

int main(int argc, const char* argv[])
{
	CmdArgsInit(argc, argv);
	ConfigFileSet(CmdArgsGetArgument("-c"));
	
	char testParam[256];
	ConfigFileStore(testParam, "testParam");
	
	puts(testParam);
	
	CmdArgsClean();
	return 0;
}