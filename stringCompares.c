#include <stdio.h>
#include <string.h>
#include <ctype.h>

//String compare, case insensetive.
	int strcmpi(char* strA, char* strB)
	{
		char* p = strA; //Setting local pointer to argument strA (char array passed in)
		char* q = strB; //Setting local pointer to argument strB (char array passed in)

		while(*p && *q && //While *p and *q does not = \0
		      (tolower(*p) == tolower(*q))) //Set char to lowercase, compare both chars, if equal, move forward memory address space
			{
				p++; //Iterate through strA
				q++; //Iterate through strB
			}
		if (!(*p)&&!(*q)) //If pointer positions values are equal, return 0 for success. (SEE NOTE BELOW)
			return 0;
		else if (*p < *q) //If pointer position value in *p is alphabetically first, return -1.
			return -1;
		else
			return 1; //Else, the pointer position value in *q is alphabetically first, return 1.
	}

	/*NOTE for line 17: pointer p and pointer q are equal to the last character value in the string at this time,
		Three cases can be had:
		1.) *p has a value of \0, *q has a value of \0. Both are false, and then evaluated to !(false), which equals true.
				Both true conditions equate to a true IF statement, returning 0. 
		2.) *p has a value greater than \0, *q has a value greater than \0. Both are true, and then evaluated to !(true), which
				equals false. Both conditions equate to a true IF statement, returning 0.
		3.) *p or *q has a value of \0, while the other has a value greater than \0. One is false, and the other is true, 
				which, they evaluate to !(false) and !(true), which equates true and false. Both conditions are not equal, therefore
				equating to a false IF statement, which allows program to continue executing.

		Lastly, the last char in strA is compared to last char in strB. Which ever comes first alphabetically is equated to the 
			"smaller" value, so if *p comes before *q, return a -1, otherwise, *q comes first, and return 1. */


int main(int argc, char const *argv[])
{
	char str1[255];
	char str2[255];

	printf("What is your first string? "); gets(str1);
	printf("What is your second string? "); gets(str2);

	if (strcmp(str1, str2) == 0)
		printf("String one and string two are exactly equal!\n");  //Compares two strings, moving though char array, comparing ASCII values.
	else
		printf("String one and string two are not equal!\n");

	printf("\nNow let's see case insensetive comparison!\n");

	if (strcmpi(str1, str2) == 0)
		printf("String one and string two are equal, when ignoring case!\n");
	else if(strcmpi(str1, str2) == -1)
		printf("String one and string two are NOT equal!\n");
	else if(strcmpi(str1, str2) == 1)
		printf("String one and string two are NOT equal!\n");
	else 
		printf("Something went wrong, you shouldn't see this!\n");
	return 0;
}