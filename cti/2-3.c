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
void Sum(Node **First, Node **Second, Node **Result);
int main()
{
	Node *first = NULL;
	Node *second = NULL;
	Node *result = NULL;
	AddtoList(&first, 1);
	AddtoList(&first, 2);
	AddtoList(&first, 3);
	AddtoList(&second, 1);
	AddtoList(&second, 3);
	Sum(&first,&second,&result);
	//PrintList(&first);
	//PrintList(&second);
	PrintList(&result);
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

void Sum(Node **First, Node **Second, Node **Result)
{
Node *first = *First;
Node *second = *Second;
Node *hresult = *Result;
int one,two,carry=0,sum;
Node *hfirst = *First;
Node *hsecond = *Second;
while(1)
	{	//hresult = *Result;
	if(first == NULL && second == NULL)
	{break;}
	if(first == NULL)
		one = 0;
	else
		one = first->data;		
	if(second == NULL)
		two = 0;
	else
		two = second->data;

	sum = one +two + carry;
		if(sum >= 10)
		{
		carry = sum%10;
		sum = sum/10;
		}
		else
		carry = 0;
				AddtoList(&hresult, sum);
				*Result = hresult;

		if(first != NULL)
			first = first->next;

		if(second != NULL)
			second = second->next;
	}
}
