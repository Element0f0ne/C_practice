#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]) + 1;
	int i;
	for (i = 1+1; i <= n; i++)
	{
		printf("%d ", fibonacci(i));
	}
	printf("\n");
	return 0;
}

int fibonacci(int num)
{
	if((num == 0) || (num == 1))
		return num;
	else
		return fibonacci(num - 1) + fibonacci(num - 2); // F(n) = F(n-1) + F(n-2)
}