#include <stdio.h>
#include <stdlib.h>


struct node{
  int x;
  struct node *next;
};
typedef struct node Node;
void printList(Node * root)
{
	Node * temp = root;
	while(temp !=NULL)
	{
		printf("%d->",temp->x);
		temp = temp->next;
	}
	printf("NULL\n");
}
void addNode(Node * root, int element)
{
	Node * temp = root;
	if(temp == NULL)
	{
		temp->next = NULL;
		temp->x = element;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	Node * newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->x = element;
	temp ->next = newNode;
}
void clearList(Node * root)
{
	Node * temp;
	Node * destroyer;
	destroyer = root;
	while(destroyer != NULL)
	{
		temp = destroyer->next;
		free(destroyer);
		destroyer = temp;
	}
}
int main()
{
    /* This won't change, or we would lose the list in memory */
    Node *root;       
	char keep_going = 'y';
	int element;
    root = malloc( sizeof(Node) );
	root->next = NULL;
	root->x = 0;
	do{
		printf("Please enter a number\n");
		scanf("%d",&element);
		addNode(root,element);
		printf("Continue y/n?");
		scanf(" %c",&keep_going);

	}while(keep_going == 'y');
    /* Creates a node at the end of the list */
	printList(root);
	clearList(root);
    return 0;
}
