#include<stdio.h>
#include<stdlib.h>

struct node
{	
int data;
struct node* left;
struct node* right;
};
typedef struct node Node;
Node * Newnode (int data);
Node * Insert(Node * root, int data);
void InorderTreeWalk(Node * root);
void PreorderTreeWalk(Node * root);
void PostorderTreeWalk(Node * root);
int size(Node* node);
int maxDepth(Node* node);
int minDepth(Node* node);
int minValue(Node* node);
int maxValue(Node* node);
void mirror(Node* node);
void doubleTree(Node* node);
int hasPathSum(Node* node, int sum);
void printPaths(Node* node);
void printArray(int ints[], int len);
void printPathsRecur(Node* node, int path[], int pathLen);
int main()
{
Node *root = NULL;

//root = Newnode(4);
int N,i,input;
	scanf("%d",&N);
	for(i = 0; i < N ; i++)
	{	scanf("%d",&input);
		root = Insert(root, input);
	}

	//mirror(root);
	//doubleTree(root);
	InorderTreeWalk(root);
	 printPaths(root);
	//printf("has Path sum %d",hasPathSum(root,14));
	//printf("size \n%d",size(root));
	printf("maxDepth \n%d",maxDepth(root));
	//printf("min value \n%d",minValue(root));
	//printf("max value \n%d",maxValue(root));
/*	printf("Pre order \n");
	PreorderTreeWalk(root);
	printf("Post Order \n");
	PostorderTreeWalk(root);*/
/*root->left = Newnode(5);
root->right = Newnode(6);
printf("%d \n",root->data);
printf("%d \n",root->left->data);
printf("%d \n",root->right->data);*/
return 0;
}

Node * Newnode (int data)
{	Node *current;
	current = (Node *)malloc(sizeof(Node));
	current->data = data;
	current->left = NULL;
	current->right = NULL;
	
	return current;
}

Node * Insert(Node * root, int data)
{    if(root == NULL)
	return (Newnode(data));
	else
		{
		 if (root->data >= data)
			root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
		
		return root;
		}
		
}

void InorderTreeWalk(Node * root)
{
if(root != NULL)
	{ InorderTreeWalk(root->left);
		printf("%d\n",root->data);
		InorderTreeWalk(root->right);
	}

}

void PreorderTreeWalk(Node * root)
{
if(root != NULL)
	{printf("%d\n",root->data);
		 InorderTreeWalk(root->left);
		InorderTreeWalk(root->right);
	}

}

void PostorderTreeWalk(Node * root)
{
if(root != NULL)
	{	 InorderTreeWalk(root->left);
		 InorderTreeWalk(root->right);
		 printf("%d\n",root->data);
	}

}

int size(Node* node)
{	int count = 0;
	if(node == NULL)
	return 0;
	else{
	count = 1 + size(node->left) + size(node->right);
	return count;
	}
	
	
}

int maxDepth(Node* node) 
{
	 int count =0;
	if(node == NULL)
		return 0;
	else 
	{
	/*	if(node->left == NULL && node->right == NULL )
		count = 1;
		else if (node->left == NULL)
		count = 1 + maxDepth(node->right); 
		else if (node->right == NULL)
		count = 1 + maxDepth(node->left); 
		else*/
		{
		count = 1 + (maxDepth(node->left)>= maxDepth(node->right)?maxDepth(node->left):maxDepth(node->right));
		}
		return count; 
	}
}

int minDepth(Node* node) 
{
	 int count =0;
	if(node == NULL)
		return 0;
	else 
	{
	/*	if(node->left == NULL && node->right == NULL )
		count = 1;
		else if (node->left == NULL)
		count = 1 + maxDepth(node->right); 
		else if (node->right == NULL)
		count = 1 + maxDepth(node->left); 
		else*/
		{
		count = 1 + (minDepth(node->left)>= minDepth(node->right)?minDepth(node->right):minDepth(node->left));
		}
		return count; 
	}
}



int minValue(Node* node) 
{

Node *current = node; 
while(current->left!= NULL)
current = current->left;
return current->data ;

}

int maxValue(Node* node) 
{

Node *current = node; 
while(current->right!= NULL)
current = current->right;
return current->data ;

}

void mirror(Node* node) 
{
	Node * temp;
	if(node != NULL)
	{ temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirror(node->left);
	mirror(node->right);
	}

}


void doubleTree(Node* node) 
{	Node * newn = NULL;
	Node * left = NULL;
	Node * right = NULL;
	if (node != NULL)
	{
		newn  =  Newnode (node->data);
		left = node->left;
		right = node->right;
		node->left = newn;
		newn->left = left;
		
		doubleTree(newn->left);
		doubleTree(node->right);
	}
}


int hasPathSum(Node* node, int sum)
{
	if(node!=NULL)
	{
		if(node->left == NULL && node->right == NULL && node->data == sum)
		return 1;
		else if (node->left == NULL && node->right == NULL && node->data != sum)
		return 0;
		else if (node->left == NULL && node->right != NULL)
			{	return hasPathSum(node->right,(sum-node->data));
			}
		else if (node->left != NULL && node->right == NULL)
			{	return hasPathSum(node->left,(sum-node->data));
			}
		else if (node->left != NULL && node->right != NULL)
			{	return (hasPathSum(node->left,(sum-node->data)) || hasPathSum(node->right,(sum-node->data)));
			}
	
	}
}

void printPaths(Node* node)
{ 
	int i;
	int path[1000];
	printPathsRecur(node, path, 0);
	printf("Actual array");	
	for(i=0 ; i<100;i++)
	printf("%d\n",path[i]);
}

void printPathsRecur(Node* node, int path[], int pathLen)
{
if (node==NULL) return;
// append this node to the path array
path[pathLen] = node->data;
pathLen++;
// it's a leaf, so print the path that led to here
if (node->left==NULL && node->right==NULL) {
printArray(path, pathLen);
}
else {
// otherwise try both subtrees
printPathsRecur(node->left, path, pathLen);
printPathsRecur(node->right, path, pathLen);
}
}
void printArray(int ints[], int len) {
int i;
for (i=0; i<len; i++) 
{
printf("%d",ints[i]);
}
printf("\n");

}
