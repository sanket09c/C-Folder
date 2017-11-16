/*
VOID POINTER
Void: nothing, not known
It is considered as generic ptr bcoz that ptr can store add of any datatype.
> void var;	//Error,object of type void cannot be created. We can create ptr to void (void*)generic ptr i.e can point to any type of object
use this concept when pointed datatype is not known

 */


#include<stdio.h>

int main()
{

	int i = 18;
	int *ptr = &i;		// Allowed
	//char *ch = &i;		// Error
	int arr[]={10,20,30,40,50,60};
	void *v1 = arr;
	void *v2 = arr + 4;




	// void pointer can store address of any data type
	char ch = 'h';
	float fl = 3.12f;
	double dl = 45.12;

	void *vptr1 = &i;		// Allowed
	void *vptr2 = &ch;		// Allowed
	void *vptr3 = &fl;		// Allowed
	void *vptr4 = &dl;		// Allowed

/*	 At time of de-referencing void pointer, we have to use specific typecasting otherwise there is error.(since compiler does not know what kind of object void ptr is pointing to. Hence, the precise no. of bytes to which ptr refers is not known.)
*/

	printf("%d\n",*(int*)vptr1);
	printf("%c\n",*(char*)vptr2);
	printf("%f\n",*(float*)vptr3);
	printf("%lf\n",*(double*)vptr4);

	// We cannot use pointer arithmetic on void pointer directly.
	// But we can use pointer arithmetic using appropriate typecasting

	printf("Value of vptr4 before operation %d\n",vptr4);
	//vptr4 = vptr4 + 1;			// Error	
	vptr4 = (double*)vptr4 + 1;	// Allowed	
	printf("Value of vptr4 after operation %d\n",vptr4);



	
	printf("v1 : \t\t%d\n",v1);
	printf("v1 : \t\t%d\n",v2);

	// Addition of pointer with integral constant
	printf("(int*)v1 + 3 : \t\t%d\n",(int*)v1 + 3);

	// Subtraction of two pointers
	printf("(int*)v2 - (int*)v1 : \t\t%d\n",(int*)v2 - (int*)v1);

	// Subtraction of pointer with integral constant.
	printf("(int*)v2 - 2 : \t\t%d\n",(int*)v2 - 2);
	
	// Accessing the contents using pointers
	printf("*(int*)v2 : \t\t%d\n",*(int*)v2);

	// We can not use multiplication and division operations on //pointers.


	// We can assign any pointer to void pointer directly
	vptr2 = ptr;
	vptr1 = ptr;

	return 0;
}
