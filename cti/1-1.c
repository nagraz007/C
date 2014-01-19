#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[50];
	char temp;
	int flag=0;
	int i=0,j;
	scanf("%s",str);
	printf("%s",str); 
	for(i=0;str[i]!='\0' && flag==0; i++)
		{
			temp = str[i];
			for(j=i+1;str[j]!='\0'; j++)	 
			{
				if(temp == str[j])
				flag=1;
				break; 
			}
		}
	if(flag==0)
	{printf("unique characters");
	}
	else
	{printf(" not unique characters");
	}
return 0;
	}
