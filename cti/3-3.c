#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next ;

};
typedef struct node Node;
void Push(Node** headRef, int data);
void PushforSet(Node** headRef, int data);
void popAt(Node** headRef, int index); 
int Pop(Node** headRef);
void PrintStack(Node** headRef);
void MoveNode(Node** destRef, Node** sourceRef); 
int cstack = 4;
int mstack = 0;
int cstackcount = 0;
int main()
{
	Node *head = NULL;
	PushforSet(&head, 1);
	PushforSet(&head, 2);
	PushforSet(&head, 3);
	PushforSet(&head, 4);
	printf("%d\t%d\t",cstack,mstack);
	PushforSet(&head, 5);
	PushforSet(&head, 6);
	PushforSet(&head, 7);
	printf("%d\t%d\t",cstack,mstack);
	popAt(&head,1);
	PrintStack(&head);
return 0;
}
void PrintStack(Node** headRef)
{
	Node *current = *headRef;
	printf("Current state of Stack is \n");
	while(current!=NULL)
	{	printf("%d\n",current->data);
		current = current->next;
	}

}
void popAt(Node** headRef, int index)
{	int i=0;
	int fcstack = cstack;
	int fmstack = mstack;
	int fcstackcount = cstackcount;
	Node *current = *headRef;
	Node *temp = *headRef;
	if(fmstack < index)
	printf("Wrong Access");
	else
	{	
		for(;;)
		{ if(index+1 == fmstack && fcstack == 1)
			break;
		else{	//if(current!=NULL)
				current = current->next;
				if(fcstack == 0)
					{ 	fcstackcount--;
				  		fmstack = fcstackcount;
						fcstack = 4;
					}
				else
					{	fcstack--;
					}
			}
		}

		temp = current->next->next;
		current->next->next = NULL;
		free(current->next);
		current->next = temp;
	}
} 
void PushforSet(Node** headRef, int data)
{	if(cstack == 0)
	{ cstackcount++;
	mstack = cstackcount;
	cstack = 4;
	}
	else
	{ cstack--;
	}
	Node * new = (Node*)malloc(sizeof(Node));
	new ->data = data;
	new ->next = *headRef;
	*headRef = new;

}

void Push(Node** headRef, int data)
{
	Node * new = (Node*)malloc(sizeof(Node));
	new ->data = data;
	new ->next = *headRef;
	*headRef = new;
}
int Pop(Node** headRef) 
{
	  int retData;
	  Node* head = *headRef;
		retData = head->data;
		*headRef = head->next;
		free(head);
return retData;
}
