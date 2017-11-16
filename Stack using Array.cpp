//	 Stack using Array (Static Implementation)


#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
# define size 10


int top = -1;
int Stack[size];

///////////////////////////////////////////////////////////////////////
// checks whether stack is full or not.
int IsStackFull()
{
	if(top == (size-1))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
///////////////////////////////////////////////////////////////////////
//This function checks whether stack is empty or not.
int IsStackEmpty()
{
	if(top == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
///////////////////////////////////////////////////////////////////////
//This function add element in stack.
void push(int value)
{
	if(!IsStackFull( ))
	{
	Stack[++top] = value;
	}
}
///////////////////////////////////////////////////////////////////////
// remove element from stack.
int pop()
{
	int value;

	if(!IsStackEmpty())
	{
		value= Stack[top--];
		return value; 	
	}
	return -1;
}
////////////////////////////////////////////////////
int pipe()
{
	int value;
if(!IsStackEmpty())
{
	value=Stack[top];
	return value;
}
return -1;
}

int main(int argc, char *argv[])
{
	push(11);
	push(21);
	push(31);
	push(44);

	printf("\nPoped Element %d\n",pop());
	printf("Poped Element %d\n",pop());

printf("%d\n",pipe());

printf("Poped Element %d\n",pop());
return 0;
}

