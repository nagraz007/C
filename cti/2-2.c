#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node Node;
void AddtoList(Node **Head,int data);
void PrintList(Node **Head);
int nth2last(Node **Head,int n);
int main()
{
	Node *head = NULL;
	Node *current = NULL;
	Node *temp = NULL;
	AddtoList(&head, 1);
	AddtoList(&head, 2);
	AddtoList(&head, 3);
	AddtoList(&head, 1);
	AddtoList(&head, 3);
	current = head;
	PrintList(&head);
	printf("nth to last%d",nth2last(&head, 2));

return 0;
}
int nth2last(Node **Head, int n)
{
Node *ptr1 = *Head;
Node *ptr2 = *Head;
int i;
	for(i=0;i<n-1;i++)
	{
		ptr2 = ptr2->next;
	}
	while(ptr2->next !=NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
return ptr1->data;
}

void AddtoList(Node **Head,int data)
{
Node *head = *Head;
Node *current = *Head;
	if(head == NULL)
	{head = (Node *)malloc(sizeof(Node));
	 head->data = data;
	 head->next = NULL;
	 *Head = head;
	}
	else
	{	while(current->next != NULL)
		current = current->next;	
		current->next = (Node *)malloc(sizeof(Node));
		current->next->data = data;
		current->next->next = NULL;
	}
}

void PrintList(Node **Head)
{
	Node *current = *Head;
	while(current!= NULL)
	{	printf("%d\n",current->data);
		current = current->next;
	}
}

