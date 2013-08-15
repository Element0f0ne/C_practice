#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *testString = "Testing!";
	printf("Hey, Buddy! This is a test of %s!\n", testString);

	char charArray[11];
	strcpy(charArray, "TheArray!$@");
	char* charStar = "TheArray!$@";

	printf("This is the last character index of charArray %c , not including the NULL terminator .\n", charArray[10]);
	printf("This is the last character index of charStar %c , not including the NULL terminator  .\n", charStar[10]);
	return 0;
}