#include<stdio.h>
struct node{
int data;
struct node* next;	
};
void Enqueue(struct node **Headref, int data)
{	
	struct node *head = *Headref;
	struct node *current = head;
	struct node *newnode = NULL;
	if(head == NULL)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = data;
		newnode->next = NULL;
		*Headref = newnode;
	}
	else
	{	
		while(current->next != NULL){
			current = current->next;
		}
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = data;
		newnode->next = NULL;
		current->next = newnode;
	}

}

int Dequeue(struct node **Headref)
{	int data;
	struct node *temp;
	if(*Headref != NULL)
	{	temp = (*Headref)->next;
		data = (*Headref)->data;
		(*Headref)->next = NULL;
		free(*Headref);
		*Headref = temp;
return data;
	}
	else return -1;
}

void Push(struct node **Headref, int data)
{	struct node *newnode = NULL;
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = data;
		newnode->next = *Headref;
		*Headref = newnode;

}
void PrintList(struct node *Headref)
{ struct node *current = Headref;
	while(current!= NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

