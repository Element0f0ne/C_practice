#include <stdio.h>

//This program is just an example of how to read through a file one byte or char at a time

int main(int argc, char const *argv[])
{
	FILE *f;  //File pointer
	f = fopen(__FILE__, "r"); // __FILE__ is a global macro that represents this c code file instead of some other file we have
							  // (Just to make this self-sufficent) (setting mode r for read only to prevent the singularity)
	int b; //Current byte we're looking at
	int i; //For-loop counter
	//Loop that reads one byte at a time
	for(i = 0; (b = getc(f)) != EOF; i++) //EOF is a global macro of type int that (GNU) expands into -1, indicating end of file
		printf("Byte %d = (HEX)%X (CHAR)%c\n", i+1, b, (char)b); //Prints out each HEX value and char value of each byte in the 
																 //file starting at first byte until reaching EOF.
	fclose(f);
	return 0;
}