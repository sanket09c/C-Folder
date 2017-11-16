/*
* Linkage: internal
* Default value: 0,0.0,\0
* Scope: file scope
* Lifetime: global lifetime
* Memory: data segment
* Static variables are initialized only once in the program.
* A static variable in a function definition will retain its value across multiple calls to the function.
* //Need: 
	Void fun()
	{	
		Int i=10;
		I++;
		If(i<15)
		{
			Fun();
		}
	}
	Int main()
	{
		Fun();
		Return 0;
	}
For every fn call, separate stack frame gets created which contains value of 1 as 10;
Thus condtn inside functn is never executed as memory for local var ‘I’ gets allocated on every functncall.
Due to this drawback our pgm terminates abnormally when memory for that stack gets finished(Stack overflow exception).
We can avoid this by making ‘i’ static.
//Modified code:-
Void fun()
{
	Static int i=10;
       i++;
if(i<15)
{
	fun();
}
}
 

*/

#include<stdio.h>

/*
There are two types of static variables as 
1. Local Static : static variable inside a method or function retains its value between invocations.
2. Global Static : static variable declared globally can called by any function or method as long as those functions appear in the same file as that of the static variable.

Similarity between both is ‘both maintains values throughout exe of pgm’
Difference: block scope vs file scope 
*/

static int Global_static  = 10;	
//global var can be accessed outside file by using 	’extern’ keyword
//But global static var has internal linkage,thus cannot be accessed 			//outside the file.


void Fun()
{
	// This is local static variable
	// whose value persist throughout the function call.
	// Initialisation of static variable only once

	static int local = 10 ;

	local++;

	printf("\nValue of local from Fun is %d",local);
	printf("\nAddress of static variable is %u",&local);

}

// Recursive function which uses static variable
void Gun_Recursive_Static()
{
	static int i = 5;

	i--;

	if(i != 0)
	{
		printf("\nIn Gun_Recursive_Static value of is is %d",i);
		Gun_Recursive_Static();
	}
}

// Recursive function which uses auto variable
// This function runs infinitely due to the auto variables
void Gun_Recursive_Auto()
{
	auto int i = 5;

	i--;

	if(i != 0)
	{
		printf("\nIn Gun_Recursive_Auto value of is is %d",i);
		Gun_Recursive_Auto();
	}
}

int main()
{

// Calling function multiple time
Fun();
Fun();
Fun();

Gun_Recursive_Static();

//Gun_Recursive_Auto();

return 0;
}
