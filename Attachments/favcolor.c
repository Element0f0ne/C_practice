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
int main()
{
	char favColor[20];
	printf("Hey, Buddy! What is your favorite color? ");
	gets(favColor);
	printf("\nThanks, Buddy! Now I know that your favorite color is %s\n", favColor);
	return 0;
}
