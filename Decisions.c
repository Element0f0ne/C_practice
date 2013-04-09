#include <stdio.h>

int main(int argc, char const *argv[])
{
	//Nested for and if loops example
	int u = 65; //ASCII decimal value for 'A'
	int l = 97; //ASCII decimal value for 'a'

	for (int i = l; i < (l + 26); i++) //For each lowercase letter (97 to 122)
	{
		printf("%c -> ", i);  //Print each lowercase character with arrow
		for (int j = u; j < (u+26); j++) //For each uppercase letter(65 to 90)
		{
			if (j == (u+25))  //If last uppercase letter,
			{
				printf("%c", j);  //print without comma
			} else
			{
				printf("%c,", j); //Else, print each uppercase character and comma on each lowercase character's row
			}
		}
		printf("\n"); //Newline, move to next lowercase character
	}

	return 0;
}