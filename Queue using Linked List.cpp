/////////////  Implementation of Queue using Linked List  //////////////

#include<stdio.h>
#include<malloc.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct node
{
	int data;
	struct node *next;
};
/////////////////////////////////////////
//This function add element in queue.
void enqueue(struct node **first, struct node **rear, int value)
{	
struct node *newn = NULL;
newn = (struct node*)malloc(sizeof(struct node));
	newn -> data = value;
	newn -> next = NULL;
	if((*first == NULL)&&(*rear==NULL))
	{
		*first = *rear = newn; 
	}
	else
	{
		(*rear) -> next = newn;
		(*rear)= (*rear) -> next;
	}
}

/////////////////////////////////////////////////////////////////////////
//Remove element from queue.
int dequeue(struct node **front,struct node **rear)
{
	struct node *temp=*front;
	int ret=-1;
	if(*front==*rear==NULL)			//Empty queue
{
	return -1;
}
	else if(*front==*rear)
{
	ret=(*front)->data;
	free(*front);
*front=*rear=NULL;
}
	else
	{
		ret=(*front)->data;
		(*front) = (*front)->next;
		free(temp);
	}
	return ret;
}
/////////////////////////////////////////////////////////////////////////
//This function displays contents of queue.
void traverse( struct node *front )
{
	while(front!=NULL)
	{
		printf(" -> |%d| ", front->data);
		front = front -> next;
	}
}
////////////////////////////////////////////

int main(int argc, char *argv[])
{
	struct node *head = NULL,*tail=NULL;

	enqueue(&head,&tail,11);
	enqueue(&head,&tail,20);
	enqueue(&head,&tail,31);
	
traverse(head);

printf("%d",dequeue(&head,&tail)); 
	return 0;
}


