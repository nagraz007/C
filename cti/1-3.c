#include<stdio.h>
int main()
{
char str[50];
gets(str);
int i=0,len=0,temp,spacecnt=0,newlen;
	while(str[i] !=  '\0')
	{	 len++; 
		if(str[i] == ' ')
		spacecnt++;
		i++;
	}
	//len=len-1;
	//printf("%d",spacecnt);
	newlen = len + spacecnt*2;
	str[newlen] = '\0';
	for(i=len-1;i>=0;i--)
	{
		if(str[i] == ' ')
		{
			str[newlen-1]= '0';
			str[newlen-2]= '2';
			str[newlen-3]= '%';
			newlen = newlen-3;
		}
		else	
		{
			str[newlen-1]= str[i];
			newlen = newlen-1;
		}

	}
	printf("%s",str);
	
return 0;
}

