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
	char firstName[255];
	char lastName[255];
	int luckyNumber;
	printf("Enter: FIRSTNAME LASTNAME LUCKYNUMBER\n");
	scanf("%s %s %d", firstName, lastName, &luckyNumber);
	printf("Hello, %s %s! Your lucky number is %d!\n", firstName, lastName, luckyNumber);
	return 0;
}
