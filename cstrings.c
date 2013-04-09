#include <stdio.h>
int main()
{
	char str1[255];
	char str2[255];
	printf("Enter str1: ");gets(str1);
	printf("Enter str2: ");gets(str2);
	
	if(strcmp(str1, str2) == 0)	//String compare are comparing the values of two c string.  Cannot directly compare (str1 == str2)
								// because they are inherently pointers and str1 and str2 are the memory addresses of the values, and
								// will never equal.
		printf("Strings are equal!");
	else
		printf("Strings are NOT equal!");
	putchar('\n');
	return 0;
}

//View more info by researching <string.h> library for string functions