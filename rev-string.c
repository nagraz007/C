#include<stdio.h>
#include<string.h>
void rev(char *inStr, char *outStr);
int main()
{
char in[10],*inStr,out[10],*outStr;
int len,i;
gets(in);
inStr = in;
outStr = out;
				/*	//	*inStr = 'A';
					len = strlen(in);
					for(i=0;i<len-1;i++)
					inStr++;
					for(i=len-1;i>=0;i--)
					{
					*outStr = *inStr;
					inStr--;
					outStr++;
					}
					//outStr++;
					*outStr = '\0';*/
					rev(inStr,outStr);
printf("%s",out);
return 0;
}

void rev(char *inStr, char *outStr)
{
int len=0,i;
	for(i=0;*inStr!='\0';i++)
	{	inStr++;
		len++;
	}
printf("%d",len);
for(i=len-1;i>=0;i--)
{
*outStr = *inStr;
inStr--;
outStr++;
printf("%c",outStr);
}
//outStr++;
*outStr = '\0';

}
