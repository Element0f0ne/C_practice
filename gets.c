#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	char favColor[20];
	printf("Hey Buddy! What's your favorite color? ");
	gets(favColor);										//Waits for user input
	printf("\nThanks Buddy! Now I know your favorite color is %s\n", favColor);

	bool stayAlive = true;
	char *userPrompt = "Do you want to exit this program (Y/N)?";
	char c;
	printf("%s\n", userPrompt);
	while(stayAlive)
	{
		c = getchar(); //Fills c with a queue of characters that made of the user input ("n<enter>"" will make queue of "n\n")
		if (c == "\n")
			continue;
		else if (c == 'Y' || c == 'y')
			stayAlive = false;
		else
			printf("%s", userPrompt);
	}
	puts("\n\nHave a nice day, Buddy!");

	return 0;
}