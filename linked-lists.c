#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;	
};
typedef struct node Node;
							void Enqueue(Node **Headref, int data);
						int Dequeue(Node **Headref);
						void PrintList(Node *Headref);
void Push(Node **Headref, int data);
int main()
{	struct node *head = NULL;
	Enqueue(&head,1);
	Enqueue(&head,2);
	printf("removed%d\n",Dequeue(&head));
	
	PrintList(head);
return 0;
}
			
				void Enqueue(Node **Headref, int data)
				{	
					Node *head = *Headref;
					Node *current = head;
					Node *newnode = NULL;
					if(head == NULL)
					{
						newnode = (Node*)malloc(sizeof(Node));
						newnode->data = data;
						newnode->next = NULL;
						*Headref = newnode;
					}
					else
					{	
						while(current->next != NULL){
							current = current->next;
						}
						newnode = (Node*)malloc(sizeof(Node));
						newnode->data = data;
						newnode->next = NULL;
						current->next = newnode;
					}

				}

				int Dequeue(Node **Headref)
				{	int data;
					Node *temp;
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

				void Push(Node **Headref, int data)
				{	Node *newnode = NULL;
						newnode = (Node*)malloc(sizeof(Node));
						newnode->data = data;
						newnode->next = *Headref;
						*Headref = newnode;

				}
				void PrintList(Node *Headref)
				{ Node *current = Headref;
					while(current!= NULL)
					{
						printf("%d\n", current->data);
						current = current->next;
					}
				}
				
