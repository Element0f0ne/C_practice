#include <stdio.h>
#include <string.h>

//structure definition
struct client 
{
	unsigned long clientId; //members/fields/attributes
	unsigned long phoneNumber;
};


//alternate declaration that creates (global) instances of client (prevents you from needing to intialize in main)
struct customer  
{
	unsigned long clientId; //members/fields/attributes
	unsigned long phoneNumber;
} customer1, customer2; //Names of instances initialized

//Complex structure declaration (using array's as attributes)
struct name
{
	char firstName[50];
	char middleName[50];
	char lastName[50];
};

//Super complex structure declaration (structure as an attribute to this structure)
struct guest
{
	struct name guestName;  //Declaring a name structure called guestName as an attribute to the guest structure
	unsigned long guestId;
	unsigned long phoneNumber;
};


int main(int argc, char const *argv[])
{
	//Example 1
	struct client c; //creates a variable titled "c" that is the type of client struct
	c.clientId = 1234567890; //setting attribute values through dot notation
	c.phoneNumber = 1112223456;

	//Example 2
	struct client d[5]; //creates a structure that has 5 elements that each contain thier own attributes
	int i;
	for(i = 0; i < 5; i++) //Loop through each element, setting thier clientId = to i
		d[i].clientId = (unsigned long)i;
	//Can be views as object model (bubbles with mini bubbles for attributes), 
	//or database model (spreadsheet d with columns = attributes, and each row equating to each element)

	//Example 3
	struct client e =  //alternate way of initializing structure by making code block and listing attribute values in same order of delcaration
	{				   //to assign the values
		1234567890,
		1112223456
	};

	//Example 4
	//Assigning attributes to "pre-initialized" customer structure instances (customer1 & 2 are names of structure variables)
	customer1.clientId = 0;
	customer1.phoneNumber = 1112223456;

	customer2.clientId = 0;
	customer2.phoneNumber = 1112223456;

	//Example 5 (complex structure)
	struct name n;
	strcpy(n.firstName, "WiBit"); //Using strcpy to fill structure array attributes
	strcpy(n.middleName, ".");
	strcpy(n.lastName, "net");

	//Example 6 ("super" complex structure, a structure as an attribute to a structure)
	struct guest g;
	g.guestId = 1234567890;
	g.phoneNumber = 1112223456;
	strcpy(g.guestName.firstName, "WiBit"); //Assigning guest's first name using double dot notation to access the firstName attribute in the name
											// attribute called guestName (that is a structure)
	strcpy(g.guestName.middleName, "."); //Same for middle name
	strcpy(g.guestName.lastName, "net"); //Same for last name

	printf("Client ID      : %ld\n", c.clientId);
	printf("Phone #        : %ld\n", c.phoneNumber);
	printf("\n");
	printf("Array Client D's ID  : %ld\n", d[0].clientId);
	printf("\n");
	printf("Guest ID            : %ld\n", g.guestId);
	printf("Guest's First Name  : %s\n", g.guestName.firstName);
	printf("Guest's Middle Name : %s\n", g.guestName.middleName);
	printf("Guest's Last Name   : %s\n", g.guestName.lastName);
	printf("\n");

	return 0;
}


