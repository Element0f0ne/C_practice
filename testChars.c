#include <stdio.h>
#include <string.h>
#include <ctype.h> //Showing useful ctype.h functions for testing types of chars. LOLOLOL

void testCharacters(char* cList) //Takes a char*
{
	int i;
	for (i = 0; i < strlen(cList); i++) //for each character
	{
		char testChar = cList[i];
		printf("Testing '%c'\n", testChar);

		if(isalnum(testChar))
			printf("'%c' is Alphanumeric\n", testChar);
		if(isalpha(testChar))
			printf("'%c' is Alphabetic\n", testChar);
		if(iscntrl(testChar))
			printf("'%c' is a Control Character\n", testChar);
		if(isdigit(testChar))
			printf("'%c' is a Digit\n", testChar);
		if(islower(testChar))
			printf("'%c' is Lower Case\n", testChar);
		if(isupper(testChar))
			printf("'%c' is Upper Case\n", testChar);
		if(isprint(testChar))
			printf("'%c' is a Printable ASCII Character\n", testChar);
		if(ispunct(testChar))
			printf("'%c' is a Punctuation Character\n", testChar);
		if(isspace(testChar))
			printf("'%c' is a Space Character\n", testChar);
		putchar('\n');
	}
}

int main(int argc, char const **argv) //Notice **, this allows you to have the argument's pointer to be passed by reference
{
	testCharacters(argv[1]); //Pass in the first agurment
	return 0;
}
