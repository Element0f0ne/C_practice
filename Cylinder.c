#include <stdio.h>
#define PI 3.14

int main(int argc, char const *argv[])
{
	float diameter;
	float height;
	float radius;
	float surfaceArea;

	printf("Please enter the diameter: ");
	scanf("%f", &diameter);
	printf("Please enter a height: ");
	scanf("%f", &height);

	printf("\nDiameter is %f, and height is %f\n", diameter, height );
	radius = diameter / 2;
	//Surface area of a cylinder is 2PIr^2 + 2PIrh
	printf(".. calculating, please wait..\n");
	surfaceArea = (2 * PI * (radius * radius)) + (2 * PI * radius * height);
	printf("The surface area of your cylinder is %.3f\n", surfaceArea );

	return 0;
}