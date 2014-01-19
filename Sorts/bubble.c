#include<stdio.h>
int main()
{	int n,i,j,temp;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

//Bubble Sort
	for(i=0;i<n-1;i++)
	{
	for(j=0;j<n-1;j++)
	{	if (A[j]>A[j+1])
			{ temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
	}
	
	}
	
	
for(i=0;i<n;i++)
		printf("%d\n",A[i]);	
return 0;
}
