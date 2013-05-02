#include <stdio.h>

//Program to scan through a file and output formatted word or words

int main(int argc, char const *argv[])
{
	FILE *f;  //File pointer declaration
	f = fopen(__FILE__, "r"); //Open "this file" and read only mode
	char word[255]; //Word variable

	while(!feof(f)) //While we are not at the end of the file handle. feof(f) returns true(1) if current position is at end of file
					// and returns false(2) if current position is not at end of file.
	{
		fscanf(f, "%s", word); //pass file pointer, the string format, and the word variable, when the cursor reaches a space
								//  it puts the word to the output, then check eof again, if not, put word, etc...
								// You can pass multiple strings by adding %s and char[]'s
		puts(word); //Outputs word to user
	}

	fclose(f);

	return 0;
}