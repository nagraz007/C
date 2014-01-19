#include<stdio.h>
int main()
{	int n,i,j,value,temp;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
// Insertion Sort
	for(i=1 ;i < n ; i++)
	{	value = A[i];
		j=i-1;
		while(j>=0 && A[j]>value )
		{
			A[j+1] = A[j];
			j--;
			A[j+1] =value; 
		}
	}
	
for(i=0;i<n;i++)
		printf("%d\n",A[i]);	
return 0;
}
