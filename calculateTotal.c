#include <stdio.h>
#include <stdarg.h> //Header file needed that contains series of preprocessor macros that
					//handle parsing lists of parameters into functions.

int calculateTotal(int n, ...) //Must include elipses (...) to denote that the number of arguments is not fixed.
{
	va_list arguments;  //Macro defined data type that stores the list of arguments. (queue data structure)
	va_start (arguments, n);  //Function that initializes the argument list with the va_list and the first parameter passed to the
							  // parent function.
	int localTotal = 0; //Variable to hold local total.  

	int i;
	for (i = 0; i < n; i++)  //Loop that goes from 0 to amount of arguments (n)
	{
		int currentArgument = va_arg (arguments, int);  //"va_arg" is a function that retrieves a single argument from the va_list
														// and specifying the data type to cast it as. (Get next top argument)
		localTotal += currentArgument; // Add current argument to localTotal
	}
	va_end(arguments);  //Stops using the arguments by passing the va_list that is storing them. Cleans up memory that was being used
						// to contain variables and functions.
	return localTotal; //Return localTotal
}

int main(int argc, char const *argv[])
{
	int total = calculateTotal(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);  //Implementation that takes (10) arguments and returns total.
	printf("%d\n", total);
	return 0;
}