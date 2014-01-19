#include<stdio.h>
struct node {
	int data;
	struct node *next ;

};
typedef struct node Node;
void towers(int,char,char,char);
void Push(Node** headRef, int data);
int Pop(Node** headRef);
void PrintStack(Node** headRef);
int main()
	{ int n;
	  printf("Enter the number of disks : ");
	  scanf("%d",&n);
	  printf("The Tower of Hanoi involves the moves :\n\n");
	  towers(n,'A','C','B');
	  return 0;
	}
void towers(int n,char frompeg,char topeg,char auxpeg)
	{ /* If only 1 disk, make the move and return */
	  if(n==1)
	    { printf("\nMove disk 1 from peg %c to peg %c",frompeg,topeg);
	      return;
	    }
	  /* Move top n-1 disks from A to B, using C as auxiliary */
	  towers(n-1,frompeg,auxpeg,topeg);
	  /* Move remaining disks from A to C */
	  printf("\nMove disk %d from peg %c to peg %c",n,frompeg,topeg);
	  /* Move n-1 disks from B to C using A as auxiliary */
	  towers(n-1,auxpeg,topeg,frompeg);
	}
/*void stacktowers(int n, char frompeg, char topeg, char auxpeg, Node** href)
	{
	Node *head = *href;
	if(n==1)
		{ 
			printf("Move disk 1 from peg %c to peg %c",frompeg,topeg);
		}
		else 
		{
		
		}

		
	}*/
void PrintStack(Node** headRef)
{
	Node *current = *headRef;
	printf("Current state of Stack is \n");
	while(current!=NULL)
	{	printf("%d\n",current->data);
		current = current->next;
	}

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
