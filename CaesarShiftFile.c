#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This will output an encrypted file using the CaesarShift

void getExtension(char*, char*);

int main(int argc, char const *argv[])
{
	int shift = atoi(argv[1]); //ASCII to int conversion, storing amount of shift passed from 1st argument into "shift"
	int byte, i;

	char filename[255];
	char newFileName[255];
	char ext[4]; //char array that hold extension
	char enc[4] = "enc";

	FILE *f_in; //Input file pointer to read
	FILE *f_out; //Output file pointer to write

	strcpy(filename, argv[2]); //Copy 2nd argument as string into filename variable
	strcpy(newFileName, filename); //Copies filename into newFileName 
	getExtension(filename, ext); //function to grab extension

	if(strcmp(ext, "enc") == 0) //Compare filename extension to "enc" (our extention for encrpyted), return 0(true), go into if 
	{
		//We have an encrypted file here, we want to decrypt.
		newFileName[strlen(newFileName) - 4] = '\0'; //Sets the "." in the filename to the NULL terminator
		f_in = fopen(filename, "r"); //Opens input file as read only
		strcat(newFileName, ".dec"); //Places ".dec" on output file (denotes decrypted file)
		f_out = fopen(newFileName, "w"); //Open output file pointer to NewFileName and sets write mode
		for(i = 0; (byte = getc(f_in)) != EOF; i++) //Scan every byte in input file to EOF 
		{
			fputc(byte - shift, f_out); //Decrypt input file by replacing each char with shift value, puts to output file
		}
	}else
		{
			//We want to encrypt a new file.
			f_in = fopen(filename, "r"); //Opens untouched file
			strcat(newFileName, ".enc"); //Adds .enc extension to newFileName
			f_out = fopen(newFileName, "w"); //Opens output file pointer to newFileName and sets write mode
			for(i = 0; (byte = getc(f_in)) != EOF; i++) //Scan every byte in new input file to EOF
			{
				fputc(byte + shift, f_out); //Encrypt new input file by replacing each char with the shift value, puts to output file with .enc
			}
		}

		fclose(f_in);
		fclose(f_out);

	return 0;
}

//Function to pull out the three character file extension
void getExtension(char* file, char* ext)
{
	  //Size for three char extention + \0
	int i; //counter for filename length - 3 to end of filename
	int j = 0; //j = position in ext array
	for(i = (strlen(file) - 3); i < strlen(file); i++) //Starting at less than 3 chars the size of the filename, until the length of the filename
	{
		ext[j] = file[i]; //Put the character into the ext array
		j++; //Iterate to next index in ext array
	}
	ext[j] = '\0'; //At this point, set j[3] = \0
}



