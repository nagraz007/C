#include<stdio.h>
#include<stdlib.h>
struct node* BuildOneTwoThree();
void Push(struct node** headRef, int data);
void DeleteList(struct node** headRef);
int Pop(struct node** headRef); 
void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef);
int Length(struct node* head); 
void MoveNode(struct node** destRef, struct node** sourceRef); 
struct node* SortedMerge(struct node* a, struct node* b);
struct node {
	int data;
	struct node *next ;

};
int main()
{
	int data;
	struct node * head = NULL;
	struct node * first = NULL;
	struct node * second = NULL;
//	head = 	BuildOneTwoThree();
	Push(&first,2);
	Push(&first,1);
	Push(&first,0);
	//Push(&second,5);
//	Push(&second,4);
	//Push(&second,3);
	//data = Pop(&head);
	//FrontBackSplit(head,&first,&second);
	//MoveNode(&first,&second);
	//printf("\t%d\t\n",data);
	//head = SortedMerge(first,second);
	/*while(head)
	{
	printf("main%d\n",head->data);
	head = head->next;
	}*/
	while(first)
	{
	printf("first%d\n",first->data);
	first = first->next;
	}
	/*while(second)
	{
	printf("second%d\n",second->data);
	second = second->next;
	}*/
	DeleteList(&head);
	DeleteList(&first);
	DeleteList(&second);
return 0;
}


struct node* BuildOneTwoThree() 
{
	struct node *  head = NULL;
	struct node *  current = NULL;
	struct node *  new = NULL;
	int i;
	
/*	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	head->data = 1;
	second->data = 2;
	third->data = 3;
	head->next = second;
	second->next = third;
	third->next = NULL; */
	
	for(i=1;i<=3;i++)
	{
		new = (struct node*)malloc(sizeof(struct node));
		if(i==1)
		{	current = new;
			head = current;
		}
		else
			{
			current->next = new;
			current = new;
			}
		current->data=i;
	}
	
	return head;
}

void Push(struct node** headRef, int data)
{
	struct node * new = (struct node*)malloc(sizeof(struct node));
	new ->data = data;
	new ->next = *headRef;
	*headRef = new;
}

void DeleteList(struct node** headRef) 
{
    struct node* current = *headRef;
	
	while(*headRef)
	{
		current = (*headRef)->next;
		free(*headRef);
		*headRef = current;
		
	}    
        
}
int Pop(struct node** headRef) 
{
	  int retData;
	  struct node* head = *headRef;
		retData = head->data;
		*headRef = head->next;
		free(head);
return retData;
}

void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef) 
{
	int len = Length(source);
	int i;
	int hopCount;
	struct node* current = source;
	if (len < 2) 
	{
		*frontRef = source;
		*backRef = NULL;
	}
	else
	 {
	hopCount = (len-1)/2;
	for (i = 0; i<hopCount; i++) 
	{
	current = current->next;
	}

	*frontRef = source;
	*backRef = current->next;
current->next = NULL;
	}
}


int Length(struct node* head) 
{
	struct node* current = head;
	int count = 0;
	while (current != NULL) {
	count++;
	current = current->next;
	}
return count;
}

void MoveNode(struct node** destRef, struct node** sourceRef) 
{
	struct node * first;
	struct node * second;
	first = *destRef;
	second = *sourceRef;
	second=second->next;
	*destRef = *sourceRef;
	(*sourceRef)->next = first;
	*sourceRef = second;
}

struct node* SortedMerge(struct node* a, struct node* b) 
{
	struct node* head = NULL;
	struct node** current = &head;
	while(1)
	{
		if(a == NULL)
			{
				*current = b;
				break;
			}
		else if(b==NULL)
			{
				*current = a;
				break;
			}
		
		if(a->data >= b->data)
			{
				MoveNode(current,&b);
			}
		else
			{
				MoveNode(current,&a);
			}
		
		
	current = &((*current)->next); 
	}
return head;
}

