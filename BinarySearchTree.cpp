// Program which is used to demonstrate working of Binary Search Tree

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *createbst(struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int countnodes(struct node *);
void insertnode(struct node *,int);
struct node *deletenode(struct node *,int);

int main()
{
	struct node *root, *root1;
	int choice, flag, no, level;
	root = NULL;

	while (1)
	{
		printf("\n   BST Creation & Traversals\n\n");
		printf("1. Create BST\n");
		printf("2. Preorder\n");
		printf("3. Inorder\n");
		printf("4. Postorder\n");
		printf("5. To count nodes in BST\n");
		printf("6. To insert a node in BST\n");
		printf("7. To delete a node from BST\n");
		printf("8. Exit\n");

		printf("Enter your choice :- ");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
				root = createbst(root);
				break;

			case 2:
				preorder(root);
				break;

			case 3:
				inorder(root);
				break;

			case 4:
				postorder(root);
				break;

			case 5:
				printf("No. of nodes in BST are %d",countnodes(root));
				break;

			case 6:
				printf("Enter the value of node to insert in BST :- ");
				scanf("%d",&no);
				insertnode(root,no);
				break;

			case 7:
				printf("Enter the value of node to delete from BST :- ");
				scanf("%d",&no);
				root = deletenode(root,no);
				break;

			case 8:
				return 0;;
		}
	}
}

// This function is used to create BST
struct node *createbst(struct node *root)
{
	struct node *newnode, *temp;
	char ask = 'y';

	while (ask == 'y')
	{
		newnode = (struct node *) malloc(sizeof(struct node));
	
		printf("Enter data for newnode :- ");
		scanf("%d",&newnode->data);

		newnode->left = NULL;
		newnode->right = NULL;

		if (root == NULL)
			root = newnode;
		else
		{
			temp = root;
			while (1)
			{
				if (newnode->data < temp->data)
				{
					if (temp->left == NULL)
					{
						temp->left = newnode;
						break;
					}
					else
						temp = temp->left;
				}
				else 
				{
					if (temp->right == NULL)
					{
						temp->right = newnode;
						break;
					}
					else
						temp = temp->right;
				}
			} 
		} 
		printf("Do you want to add more nodes to BST ? ");
		scanf("%c",&ask);
	}  
	return root;
}

// This function is used to print the contents in preorder
void preorder(struct node *temp)
{
	if (temp != NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->left);   /* recursive call */
		preorder(temp->right);
	}
}

// This function is used to print the contents in inorder
void inorder(struct node *temp)
{
	if (temp != NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}

// This function is used to print the contents in postorder
void postorder(struct node *temp)
{
	if (temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}

// This function is used to count number of nodes in BST
int countnodes(struct node *temp)
{
	static int cntr = 0;

	if (temp != NULL)
	{
		cntr++;
		countnodes(temp->left);
		countnodes(temp->right);
	}
	
	return cntr;
}
// This function is used to insert node in BST
void insertnode(struct node *temp,int no)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = no;
	newnode->left = NULL;
	newnode->right = NULL;
	while (1)
	{
		if (newnode->data == temp->data)
		{
			printf("Node with data %d exists in BST",no);
			return;
		}

		if (newnode->data < temp->data)
		{
			if (temp->left == NULL)
			{
				temp->left = newnode;
				break;
			}
			else
				temp = temp->left;
		}
		else 
		{
			if (temp->right == NULL)
			{
				temp->right = newnode;
				break;
			}
			else
				temp = temp->right;
		}
	} 
}

// This function is used to delete node from BST
struct node *deletenode(struct node *root,int no)
{
	struct node *temp, *parent_temp, *rn, *parent_rn, *son;
	parent_temp = NULL;

	temp = root;
	while (temp != NULL)
	{
		if (temp->data == no)   
			break;

		parent_temp = temp;
		if (no < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	
	if (temp == NULL)
	{
		printf("Node with data %d not found in BST",no);
		return root;
	}
	
	if (temp->left == NULL)
		rn = temp->right;
	else

	{
		if (temp->right == NULL)
			rn = temp->left;
		else 
		{
			parent_rn = temp;
			rn = parent_rn->right;
			son = rn->left;

			while (son != NULL)
			{
				parent_rn = rn;
				rn = son;
				son = son->left;
			}
			if (parent_rn != temp)
			{
				parent_rn->left = rn->right;
				rn->right = temp->right;
			}
			rn->left = temp->left;
		}
	}
	if (parent_temp == NULL)
		root = rn;
	else
	{
		if (parent_temp->left == temp)
			parent_temp->left = rn;
		else
			parent_temp->right = rn;
	}
	free(temp);
	printf("Node with data %d deleted ",no);

	return root;
}

