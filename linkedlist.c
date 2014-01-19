#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct nodes 
{
int data ;
struct nodes *link;  // typedef??
};
typedef struct nodes node; 
int main()
{
 /*node *head;
 node *current;
 int i; 
head= NULL;
 for(i=0;i<10;i++)
 {	
	current = (node *)malloc(sizeof(node));
	 current->data = i;
	current->link = head;
	head = current;

 }
//current = head; 
 while(head)
{
printf("%d\n",head->data);
head = head->link;
}*/
int i = 42;
int *j;
j= &i;
// i is now 43
// j is now 52 (NOT 53)
//j = (++i + 10);
// i is now 44
// j is now 54


printf("%d%u",i,j);
return 0;
}
