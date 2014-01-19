#include<stdio.h>
#include<stdlib.h>
struct bfsnode
{
char color;
int prev;
int dist;
};
typedef struct bfsnode Node;

struct dfsnode
{
char color;
int i;
int f;
int prev;
};
typedef struct dfsnode dnode;

dnode Vertex[100];
int time =0;
struct qnode {
	int data;
	struct qnode *next ;

};
typedef struct qnode Qnode;
int graph[11][11];
void PrintDFS(int vertices);
void DFS(int *G, int vertices);
void DFSVisit(int *G,int u,int vertices);
void BFS(int *G,int vertex, int vertices);
void AddtoQueue(Qnode **Head, int data);
void PrintQueue(Qnode **Head);
Qnode * Newnode(int data);
int RemovefromQueue(Qnode **Head);
void FreeQueue(Qnode **Head);
Qnode * InitializeQueue();
int main()
{
int m,n,i,j;
scanf("%d",&m);
//int graph[m][m];
	for(i=0 ; i< m ; i++)	
		for(j=0; j<m ; j++)
			{
				scanf("%d",&graph[i][j]);
				//filling the adjacency List
			}
			//BFS(&graph[0][0],2,m);
			DFS(&graph[0][0],m);
			PrintDFS(m);
			printf("time %d",time);
return 0;
}
void PrintDFS(int vertices)
{
int i;
	for(i=0;i<vertices;i++)
	{
		printf("vertex %d color %c\tinit --%d \tfinal-- %d\n",i+1,Vertex[i].color,Vertex[i].i,Vertex[i].f);
	}
}
void DFS(int *G, int vertices)
{
	int i,j,u,v;
	//int time =0;
		
	// initializing all vertices
	for(i=0 ; i<vertices ; i++)
		{		Vertex[i].color = 'W';
				Vertex[i].i = 0;
				Vertex[i].f = 1111;
				Vertex[i].prev = -1;
		}
		//adjaency
	for(i=0; i<vertices ; i++)
		{
			for(j=0 ; j<vertices; j++)
			{	
			printf("%d \t",graph[i][j]);
			}
			printf("\n");
		}

//
		
	for(i=0;i<vertices;i++)
		{
				if(Vertex[i].color == 'W')
					{	
						DFSVisit(G, i,vertices);
						}
			}
}

void DFSVisit(int *G,int u,int vertices)
{
int j,v,i;
time++;
Vertex[u].i = time;
Vertex[u].color = 'G';
//printf("u is %d", u);
for(j=0;j<vertices;j++)
		{	//v = vertices*u+j;
					//printf("graph %d", graph[u][j]);
			if(graph[u][j] == 1 && Vertex[j].color == 'W')
			{
					Vertex[j].prev = u;
					DFSVisit(G, j,vertices);
			}
		}
Vertex[u].color = 'B';
time++;
Vertex[u].f = time;
}

void BFS(int *G,int vertex, int vertices)
{
 int i,j,u,v;
		Node Vertex[vertices];
	// initializing all vertices
	for(i=0 ; i<vertices ; i++)
		{
			if( i== vertex-1)
				{
				Vertex[i].color = 'G';
				Vertex[i].prev = -1;
				Vertex[i].dist = 0;
			}
			else
				{
				Vertex[i].color = 'W';
				Vertex[i].prev = -1;
				Vertex[i].dist = 1111;
			}
		}
//printing adjacency list
 	for(i=0; i<vertices ; i++)
		{
			for(j=0 ; j<vertices; j++)
			{	
			printf("%d \t",G[(i*vertices)+j]);
			}
			printf("\n");
		}
	struct qnode* head = InitializeQueue();
	AddtoQueue(&head, vertex-1);
	while(head!=NULL)
	{	u = RemovefromQueue(&head);
		for(j=0;j<vertices;j++)
		{	v = vertices*u+j;
			if(G[v] == 1)
			{
				if(Vertex[j].color == 'W')
				{	Vertex[j].color = 'G';
					Vertex[j].dist = Vertex[u].dist + 1;
					Vertex[j].prev = u;
					AddtoQueue(&head, j);
				}
			}
		}
		Vertex[u].color = 'B';
	}

		printf("Printing distances");
		for(i=0 ; i<vertices ; i++)
		{
			printf("%d \n",Vertex[i].dist);		
		}

	
}


Qnode * InitializeQueue()
{
	Qnode *head = NULL;
return head;
}

Qnode* Newnode(int data)
{
struct qnode *newn = NULL;
	newn = (struct qnode *)malloc(sizeof(struct qnode));
	newn->data = data;
	newn->next = NULL;
return newn;
}

void AddtoQueue(Qnode **Head, int data)
{
	struct qnode* current = *Head;
	if((*Head) == NULL)
	{
	struct qnode*	hed = Newnode(data);
	*Head = hed;
		}
   	else{
   			while(current->next!= NULL)
   			{
   				current = current->next;
   			}
		struct qnode* newn = Newnode(data);
			current->next = newn;
	}

}

int RemovefromQueue(struct qnode **Head)
{	int data;
 	struct qnode* head = *Head;
	struct qnode* current = *Head;
	struct qnode* temp =*Head;
	current = current->next;
	data = head->data;
	head->next = NULL;
	free(head);
	head = current;
	*Head= head;
return data;	
}

void PrintQueue(struct qnode **Head)
{
	struct qnode *head = *Head ;
	while(head!=NULL)
	{
		printf("%d \n",head->data);
		head = head->next;
	}
}

void FreeQueue(Qnode **Head)
{	Qnode *current = *Head;

	while(*Head != NULL)
	{
	current = (*Head)->next;
	free(*Head);
	*Head = current;
	}
}

