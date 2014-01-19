#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element * previous;
	struct element * next;
};
typedef struct element Node;
Node * Newnode(int data);
void Insertnode(Node **head,int data);
int main()
{
	Node *head = NULL;
	//head->next = NULL;
	//head->previous = NULL;
	Insertnode(&head , 1);
	Insertnode(&head, 2);
	while(head != NULL)
	{
	printf("%d\n", head->data);
	head= head->next;
	}
return 0;
}

Node * Newnode(int data)
{
	Node *current = NULL;
	current = (Node *)malloc(sizeof(Node));
	current->data = data;
	current->previous = NULL;
	current->next = NULL;

return current;
}

void Insertnode(Node **head,int data)
{
	Node *Head = *head;
	Node *current = *head;
	Node *newNode = NULL;
	if(Head == NULL){
	
		Head = Newnode(data);
		current = Head;
	}
	else
	{
		while(current->next != NULL)
		{ 	 current = current->next;
		
		}	
			newNode = Newnode(data);
			Head->previous = newNode;
			newNode->next = Head->previous;
			newNode->previous = current->next;
	}

}
