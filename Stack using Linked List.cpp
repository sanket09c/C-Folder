//			Implementation of Stack using Linked List
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<malloc.h>
# define MAX 10

struct node
{
	int value;
	struct node *next;
};

//counts number of elements in stack.
int Count(struct node *first)
{
	int no = 0;
	while(first != NULL)
	{
		no++;
		first = first -> next;
	}
	return no;
}

//checks whether stack is empty or not.
int IsStackEmpty(struct node *first)
{
	if(first == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//checks whether stack is full or not.
int IsStackFull(struct node *first)
{
	if(Count(first) == MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// displays contents of stack.
void Display( struct node *first )
{
	if(first == NULL)
	{
		return;
	}
	while(first)
	{
		printf(" |%d| \n", first->value);
		first = first -> next;
	}
}
// remove element from stack.
int pop(struct node **first)
{
	int no = 0;
	struct node *temp1,*temp2;
	temp1 = temp2 = ( *first );

	if(IsStackEmpty(*first))
	{
		return -1;
	}
	else
	{
		while(temp1 -> next != NULL)
		{
			temp2 = temp2 -> next;
			temp1 = temp2 -> next;
		}
		temp2 -> next = NULL;
		no = temp1 -> value;
		free(temp1);
		return no;
	}
}

//add element in stack.
void push(struct node **first, int no)
{
	struct node *temp;
	struct node *newn = (struct node*)malloc(sizeof(struct node));
	newn -> value = no;
	temp = (*first);

	if(IsStackFull(*first))
	{
		free(newn);
		return;
	}

	if(*first == NULL)
	{
		newn -> next = NULL;
		(*first) = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
		newn -> next = NULL;
	}
}

int main(int argc, char *argv[])
{
	struct node *head = NULL;

	push(&head,10);
	push(&head,20);
	push(&head,30);
	push(&head,40);

	printf("Elements in stack : \n");
	Display(head);

	printf("Poped element => %d\n",pop(&head));
	printf("Poped element => %d\n",pop(&head));

	printf("Elements in stack =>\n");
	Display(head);
	return 0;
}
