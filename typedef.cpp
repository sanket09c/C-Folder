#include<iostream>

using namespace std;

int main()
{
/* By using typedef we are assigning a new name(alias) to as existing data types
For using familiar naming convention, shortcut to big names
*/

// Integer is a new type which is same as int
	typedef int MyInteger;
	MyInteger i;

	// Floating_Point is a new type which is same as float
	typedef float MyFloatingPoint;
	MyFloatingPoint f;

	// Character is a new type which is same as char
	typedef char MyCharacter;
	MyCharacter c;


// NewStructX is new type which is same as struct demo
	typedef struct demo
	{
		int i;
		char c;
	}NewStructX;

	NewStructX object;
// This statement is same as struct demo object;
 
	struct demoX
	{
		int k;
	};

// We can also create typedef for struct in this way also
	typedef struct demoX NewDemo;

	NewDemo objX;
// typedefs are generally used to avoid typing of complicated datatypes
	typedef unsigned long int * New_Type;

// t is a pointer to unsigned long integer
	New_Type t;


// We can also skip name of structure while creating typedef
	typedef struct
	{
		char ch;
	}Unnamed;

	Unnamed myObj;

// We can also create two new type names for the structure.
	typedef struct
	{
		int i;
	}NewUnnamed1,NewUnamed2;


	typedef struct gun
	{
		int i;
	}*Sptr;
// Sptr is a new type which is a pointer to structure gun.

	Sptr s = new gun;
	// s is a pointer which stores address of struct gun


// Creating typedef for function pointers.
// fptr is a new data type which is a pointer
// to function which accept two integers and
// return integer.

	typedef int(*fptr)(int , int);

	fptr fp;

	return 0;
}

// This is typedef for a class which is similar as typedef for struct
/*
typedef class
{
public:
	int k;

}demo;
*/
