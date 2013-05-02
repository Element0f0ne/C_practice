#include <stdio.h>
#include <string.h>
#include <ctype.h>

	//String to upper since "strupr" doesn't work.
	char* stoupper(char* s)
	{
		char *p = s;
		while (*p = toupper(*p)) p++;  //Starting at first character of string, set char to lowercase, move forward memory address space.
		return s;					   //NOTE: toupper returns an int, that can be implicitly casted to char, therefore anything
									   //that isn't \0, will return 1, and stay in whle loop until a NULL (\0 is met.)
	}

	//String to lower since "strlwr" doesn't work.
	char* stolower(char* s)
	{
		char* p = s;
		while (*p = tolower(*p)) p++;  //Same functionality/note as above, except lowercase conversion.
		return s;
	}

int main(int argc, char const *argv[])
{
	char str1[255];
	char str2[255];

	printf("What is your first string? "); gets(str1);
	printf("What is your second string? "); gets(str2);

	printf("The length of your first string, %s is %zd.\n", str1, strlen(str1)); //Example of strlen

	char str3[255];
	strcpy(str3, str1);
	printf("String 1 is now copied into string String 3. String 3 = '%s'.\n", str3); //Example of strcpy

	printf("This is an example of string concatenation: %s.\n", strcat(str1,str2)); //Example of strcat (only takes 2 arguments)

	printf("String 1 in all upper case (Remember the concatenation?): %s.\n", stoupper(str1)); //Prints string in all upper case
	printf("String 2 in all lower case: %s.\n", stolower(str2)); //Prints string in all lower case

	return 0;
}