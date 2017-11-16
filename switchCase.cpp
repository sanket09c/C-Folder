#include<stdio.h>

// This program demonstates concept of switch case

int main()
{

	// Use of switch case
	int num = 4;
	if (num == 15)
	{
		printf("Value of num is 15");
	}
	else if (num == 6)
	{
		printf("Value of num is 6");	
	}
	else if (num == 9)
	{
		printf("Value of num is 9");			
	}
	else
	{
			printf("Value of num is not within the range");	
	}
/*
	 Above code can be written with the help of switch case
	 Switch case evaluates faster as compared to if-elseif (as it internally uses jump.)
*/
	switch(num)
	{
		case 15:
			printf("Value of num is 15");
		break;

		case 6:
			printf("Value of num is 6");	
		break;

		case 9:
			printf("Value of num is 9");			
		break;

		default :
				printf("Value of num is not within the range");	
	}
/*
	// We cannot implement ranges in switch case
	if (no < 10 && no > 30)
	{
		printf("Value of no is in between 10 and 30");
	}
	else if (no < 30 && no > 40)
	{
		printf("Value of no is in between 30 and 40");
	}
	else if (no < 50 && no > 70)
	{
		printf("Value of no is in between 50 and 70");
	}


*/
// If particular case is matched then control goes in that case
// And instructions are evaluated till ‘break’

int	m = 14;
	switch(m)
	{
		case 10:	printf("Value of m is 10\n");
			break;

		case 11:	printf("Value of m is 11\n");
			break;
		
		case 14:	printf("Value of m is 14\n");
			// After executing this case control is transferred to next case

		case 15:	printf("Value of no is 15\n");
			break;
	}

	// Identical case not allowed in switch case
/*
	switch(no)
	{
	case 10:

		break;

	case 11:

		break;

	case 10:			// Error

		break;
	}
*/
/*
 If there is no appropriate case then control is passed to default case
 Note:- writing default case is not compulsary
*/
int	a = 50;
	switch (a)
	{
	case 20:

		break;

	case 31 :

		break;

	default :
		printf("Inside the dafault case\n");
		break;
	}

	int no1;
	int i = 10,j = 20;
	switch (no1)
	{
		case 10:				// Allowed
			break;

		case 10+2*2:		// Allowed
			break;

		case 'A':				// Allowed
			break;

		case 10/3 :			// Allowed
			break;

		//case i+j:			// Not allowed

		case 15:
		//	continue;			// We cannot use continue in 								//swich case
			break;
	}


return 0;
}
