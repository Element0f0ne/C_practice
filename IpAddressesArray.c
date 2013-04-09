#include <stdio.h>
#define ADDRESSES 5
#define OCTETS 4

int main(int argc, char const *argv[])
{
	int ips[ADDRESSES][OCTETS] = 
	{
		{192, 168, 1, 1},
		{192, 168, 1, 100},
		{12, 63, 10, 50},
		{68, 59, 241, 78},
		{127, 0, 0, 1}
	}; //Create array

	/* Alternate way of creating array and setting values (be sure to change from symbolic #define's
				to const int's below in for loops):

	const int addresses = 5, octets = 4; //Sets constants for ip array (row = addresses) (columns = octets)
	int ips[addresses][octets];  //ceate array

	ips[0][0] = 192, ips[0][1] = 168, ips[0][2] = 1, ips[0][3] = 1;  //Sets values for first address 
	ips[1][0] = 192, ips[1][1] = 168, ips[1][2] = 1, ips[1][3] = 100;  //Sets values for second address 
	ips[2][0] = 12, ips[2][1] = 63, ips[2][2] = 10, ips[2][3] = 50;  //Sets values for third address
	ips[3][0] = 68, ips[3][1] = 59, ips[3][2] = 241, ips[3][3] = 78;  //Sets values for fourth address 
	ips[4][0] = 127, ips[4][1] = 0, ips[4][2] = 0, ips[4][3] = 1;  //Sets values for fifth address 
	*/

	for (int i = 0; i < ADDRESSES; i++)
	{
		for (int j = 0; j < OCTETS; ++j)
		{
			printf("%d (x%X) , ", ips[i][j], ips[i][j]);  //prints array octets in decimal and HEX value
		}
		putchar('\n'); //newline
	}

	for (int i = 0; i < ADDRESSES; i++)
	{
		printf("%d.%d.%d.%d\n", ips[i][0], ips[i][1], ips[i][2], ips[i][3]);
	}

	return 0;
}