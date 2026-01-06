#include <stdio.h>
#include <string.h>
int a[40],top=-1;
void push(char e)
{
	if(top+1==40)
	{
		printf("Stack overflow\n");
		return;
	}
	a[++top]=e;
}
void pop()
{
	printf("%c",a[top--]);
}
void find(char s[40])
{
	int i,j;
	for(i=0;i<=strlen(s);i++)
	{
		if(s[i]=='*')
			pop();
		else
			push(s[i]);
		
	}
	while (s[top] != '\0'){
		pop();
	}	
}
int main()
{
	char s[40];
	printf("Enter a word with astrics : ");
	scanf("%s",s);
	find(s);
	return 0;
}
