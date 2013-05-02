#include <stdio.h>
#include <stdlib.h>

//Example of how to read an enitre file using functions to get file size, store in buffer, and output to user

long getFileSize(FILE*);
char* readAllText(char*);

int main(int argc, char const *argv[])
{
	char* fileData = readAllText(__FILE__); //Everything we read in the file is stored in this char* (this file)
	puts(fileData); //Displays fileData to output for user
	free(fileData); //Free's the buffer used to hold the file, free's memory from malloc()
	return 0;
}

long getFileSize(FILE *filePointer)
{
	long fSize;
	fseek(filePointer, 0, SEEK_END); /*fseek sets the current position in the file (<file pointer>,<offset>,<origin>)
									  This is getting the last possible cursor position in the file. This doesn't need a loop
									  because it simply sets cursor to position based off <origin> and <offset> parameters.
									  SEEK_END is another global constant that equates to end of file (library dependant, therefore
									  non-portable) Other constants used here are SEEK_SET (beginning of file, and SEEK_CUR
									  (current position of file pointer) */
	fSize = ftell(filePointer);	// Stores size of file based of position of cursor (which was set to last position from fseek)
	rewind(filePointer); //Sets cursor back to beginning of file
	return fSize;  //Returns file size as a long
}

char* readAllText(char* filePath)
{
	FILE *f = fopen(filePath, "r");  //Create file pointer and sets it to argument filePath
	long fileSize = getFileSize(f); //Count of file size
	char* buffer = (char*)malloc(sizeof(char) *fileSize+1); //Allocating memory, sizeof a (char * value) (char * fileSize+1 in this case)
											//fileSize+1 is the amount of characters in the file + 1 for the \0
	fread(buffer, 1, fileSize, f); //Reads in file from file pointer (f), stores in buffer based off size of element (1 byte),
								   //and there are fileSize amount of elements.  (Buffer was created to fit precisely size of file)
	fclose(f);
	return buffer;
}