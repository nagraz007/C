#include<stdio.h>
void Quicksort(int A[],int p, int r);
int Partition(int A[],int p, int r);
int main()
{	int n,i,j;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<n;i++)
		printf("%d\n",A[i]);
return 0;
}
void Quicksort(int A[],int p, int r)
{	int q;
		if(p<r)
		{	
		q = Partition(A,p,r);
		Quicksort(A,p,q);
		Quicksort(A,q+1,r);						
		}
}
int Partition(int A[],int p, int r)
{	int i,j,x;
x = A[r];
i = p-1;
for(j=0;;j++)
	
}
