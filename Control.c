#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x = 10;
	int y = 50;
	int z = 100;

	if (x != y) //Logical not comparison
	{
		printf("%i is not equal to %i.\n", x, y);
	}

	if (x > y || y < z) //Logical OR comparison
	{
		printf("Boo!!!!\n");
	}

	if (x > y && y < z) //Logical AND comparison
	{
		printf("Boo!!!!\n");
	}
		else
		{
			printf("Grrr!!!!\n");
		}

	int num = 100;

	switch(num) //Generic switch statement
	{
		case 50:
			printf("The value is 50.\n");
		break;
		case 100:
			printf("The value is 100.\n");
		break;
		default:
			printf("The value is not 50 and not 100.\n");
		break;
	}

	int a = 20;
	int b = 0;

	b = (a == 20) ? 0 : 1; //conditional assignment (ternary if statement)
	printf("b == %d.\n", b);

	int c = 0;
	while (c < 3) //while loop example
	{
		printf("c equals %d while c < 3.\n", c);
		c++;
	}

	int d = 0;
	do //do while loop example
	{
		printf("d Does equal %d while d < 3.\n", d);
		d++;
	} while (d < 3);

	int i;
	for (i = 0; i < 3; i++) //for loop example
	{
		printf("For i is less than 3, print %d. Then increment i.\n", i);
	}

	return 0;
}