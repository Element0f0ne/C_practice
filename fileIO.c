#include <stdio.h>
#include <string.h>

//Various file i/o functions to show how to access files (fopen), print formatted strings to files (fprintf),
//  write C strings to file(fwrite), find current position of cursor in file(ftell), and print one char to file(fputc)
// and how to close a file(fclose)

int main(int argc, char const *argv[])
{
	FILE *f;  //Declare FILE object handle called (f), which is a pointer
	char* txt = "Hey, Buddy Guy!\n";

	f = fopen("MyFile.txt", "w"); //Sets pointer (f) to a file called "MyFile.txt", that didn't exist, but is created by "w" mode

	fprintf(f, "Hey, Buddy!\n"); //Prints to file by passing the file pointer (f), and the formated text you want to write to file.

	fwrite(txt, 1, strlen(txt), f); //Writes to file: <const array>, <element block size>, <# of elements>, <file pointer>
									// In this case, 1 char is the block size, and the length of txt is the # of blocks

	char* s = "Hey, Putter!\n";
	int i;
	for(i =0; i < strlen(s); i++) //Loops through string s
	{
		printf("%ld\n", ftell(f)); /*This will print to console the position of the cursor in the file.
								   		In this case, upon execution, we print to the console the values 28 - 40
								   		The value 28 is the position of the cursor in the file after the "H" in this for-loop.
								   		The printing to console is simply showing how the cursor moves in the file once's it's
								   		been open.*/
		fputc(s[i], f);  //prints char in the file: (<character>, <file pointer>)
	}

	fclose(f); //Closes the handle to the file


	return 0;
}