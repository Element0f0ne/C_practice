#include <stdio.h>
#include <stdlib.h>

//Greatest common divisor or Euclid's alorithm
int gcd(int, int);

int main(int argc, char const *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	printf("The greatest common divisor of %d and %d is %d.\n", a, b, gdc(a,b));

	return 0;
}

int gdc(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gdc(b, a % b);
}
	/*In the above function, we'll use 9 and 18:

	gdc(9, 18)

	Is 18 = 0?
	No, then execute gdc(18, 9 % 18). <a=18, b = 9>
	Is 9 = 0?
	No, then execute gdc(9, 18 % 9). <a=9, b = 0>
	Is 0 = 0?
	Yes, return 9.
	*/