#include<stdio.h>
int main()
{
char str[10];
char revstr[50];
	char temp;
	int flag=0;
	int len=0;
	int i=0,j;
	scanf("%s",str);
	while(str[i] !=  '\0')
	{ len++;
	i++;
	}
	printf("%d",len);
	for(i=len-1,j=0; i>= 0 ; i--)
	{ revstr[j]= str[i];
	j=j+1;
	}
	revstr[len] = '\0';
	printf("%s",revstr);
return 0;}
