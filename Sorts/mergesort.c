#include<stdio.h>
void MergeSort(int A[],int p,int r);
void Merge(int A[],int p,int q,int r);
int main()
{	int n,i,j,value,temp;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	 //Merge(A,0,3,6);
	MergeSort(A,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\n",A[i]);
return 0;
}

void MergeSort(int A[],int p,int r)
{
	int q,i;
	if(p<r)
	{
	q = (p+r)/2;
	MergeSort(A,p,q);
	MergeSort(A,q+1,r);
	Merge(A,p,q,r);
	}
}
void Merge(int A[],int p,int q,int r)
{	int i,j,init,final;
	int a1[q-p+1];
	int a2[r-q];
init = p;
final = r;
//filling these two bacchas
	for(i=p,j=0;i<=q;i++,j++)
		a1[j] = A[i];
	for(i=q+1,j=0;i<=r;i++,j++)
		a2[j] = A[i];

		for(i=0;i<q-p+1;i++)
		printf("a1%d\n",a1[i]);
		for(i=0;i<r-q;i++)
		printf("a2%d\n",a2[i]);
// doing merging business
	i=0;
	j=0;
		printf("p%d\n",p);
		printf("q%d\n",q);
		printf("r%d\n",r);

	while(i<=(q-p) && j<(r-q))
	{
		if(a1[i]<= a2[j])	
		{ A[init] = a1[i];
			i++;
			init++;
		}
		else
		{	A[init] = a2[j]; 
			j++;
			init++;
		}
	

	}
	if(i == (q-p+1))
	{	while(j<(r-q))
		{
			A[init] = a2[j];
			init++;
			j++;
		}	
	}
	if(j== (r-q))
	{	while(i<=(q-p))
		{
			A[init] = a1[i];
			init++;
			i++;
		}

	}
}
