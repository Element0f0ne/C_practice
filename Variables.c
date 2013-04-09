#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num = 931;
	printf("The number 'num' is %d.\n", num);

	float fnum = 2.7548; //floating point number out to 6 decimal places
	printf("The number \"fnum\" is $%.2f.\n", fnum); //%.2f means take only 2 places after decimal

	char c = 'K'; //single character
	printf("My name is %cevin.\n", c);

	char listOfCharacters[50]; //character array
	int cnum = 8675309;

	sprintf(listOfCharacters, "%d", cnum); //stores variable from formatted variable
	printf("Our list of characters are: %s.\n", listOfCharacters);

	//Operators
	int n = 1;
	int m = 1;

	printf("Increment operator before: ++%d. //++1\n", ++n);
	printf("Increment operator after: %d++. //1++\n", m++);

	char x = '\x1'; //HEX value of 1
	char y = 'A'; //ASCII decimal value is 65
	char z = x + y;

	printf("x plus y equals %d (decimal).\n", z);
	printf("x plus y equals %c (character). //'A''s ASCII value: 65 plus 1, which is 'B''s ASCII value of 66.\n", z);

	return 0;
}