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
void DeleteFromList(Node **Head, int data); 
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
	//DeletFromList(&(head),1);
	PrintList(&head);

	while(current!= NULL)
	{	temp = current;
		while(temp->next!=NULL)
		{	DeleteFromList(&(temp->next), current->data);
			temp = temp->next;
		}
	current = current->next;
	}
return 0;
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

void DeleteFromList(Node **Head, int data)
{
	Node *head = *Head;
	Node *current = head;
	Node *temp = NULL;
	if(head == NULL)
	{
	}
	else
	{	if(head->data == data)
			{
				temp = head->next;
					//head->next = NULL;
					free(head);	
					*Head = temp;
					
			}
		else{
				while(current->next!=NULL)
				{ 
					if(current->next->data == data)
					{
					temp = current->next->next;
					current->next->next= NULL;
					free(current->next);
					current->next = temp;
					break;
					}
					current = current->next;
				}
			}
	}
		
}
