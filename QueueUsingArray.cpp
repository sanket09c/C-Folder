///////////    Implementation of Queue using Array    ///////////
#include<stdio.h>
#include<malloc.h>
#define MAX 10
typedef int BOOL
#define TRUE 1
#define FALSE 0

int arr[MAX];
int front = 0;
int rare = 0;

//check whether queue is empty or not.
BOOL IsQueueEmpty()
{
	if(front==rare == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/////////////////////////////////////////////////
//This function checks whether queue is full or not.
int IsQueueFull()
{
	if(rare == MAX )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/////////////////////////////////////////////////////////////////////////
//This function add element in queue.
void enqueue(int no)
{
	if(!IsQueueFull( ))
	{
		arr[rare++]=no;
	}
}
/////////////////////////////////////////////////////////////////////////
//This function remove element from queue.
int dequeue()
{
	if(!IsQueueEmpty())
	{
		return arr[front++];
	}
}

int main()
{
enqueue(11);
enqueue(21);
enqueue(31);
printf("%d",dequeue());
}
