#include <stdio.h>

/*Logic explanation: (Setting n = 5)
					 -Is 5 > 1? Yes.
					 -Then set local = to n * getFactorial(5-1) <I don't know what that is yet, but I'll run it>
					 -Is 4 > 1 now? Yes.
					 -Set local = n * getFactorial(4-1) <I still don't know it, I'll run it again...>
					 -Keeps going until if check returns false which should equal your "end game value", in this case, 1.
					 -On to: 
					 	Is 2 > 1 now? Yes.
					 	Then set local = to n * getFactorial(2-1) <I don't know the value, I'll run it again>
					 	Is 1 > 1 now? No.
					 	Then return 1, but not before returning local total from previous loop. 
					 		(Stack pops local = 2 * 1(current n) = 2,
					 		  		    local = 3 * 2(popped value) = 6,
					 				    local = 4 * 6(popped value) = 24,
					 				    local = 5 * 24(popped value) = 120,
					 			returns local = (value at bottom of stack) 120) 
					 											
					 		Else if 1 was passed in, 1 > 1 will fall into else, returning 1.
					 (Note, there is still only one return in the function execution. Do NOT think this is creating
					 multiple returns for one function.  The function returns local only once, after n-1 loops, or
					 returns 1 if loop never executes.  In this case, the function runs 4 times, then returns loop.)
*/
unsigned int getFactorial(unsigned int n) //using unsigned int for larger values.
{
	unsigned int local;
	if(n > 1)
	{
		local = n * getFactorial(n-1);
		return local;
	} else
	{
		return 1;
	}
}

int main(int argc, char const *argv[])
{
	unsigned int value = atoi(argv[1]);
	printf("%d! = \n", value);
	printf("%u\n", getFactorial(value));
	return 0;
}


