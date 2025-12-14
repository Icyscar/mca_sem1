/*To reverse the string using stack.
@Abhinav B Prasad
26/07/2025*/

#include <stdio.h>
#include <string.h>
char a[30];
int top=-1;
void push(char s[])			//To push each char of string to the stack
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		a[++top]=s[i];
	}
}
void pop(char s[])			//pop each char and add it to the orginal string variable
{	
	int i;
	for(i=0;i<strlen(s);i++)
	{
		s[i]=a[top--];
	}
}
int main()
{
	char str[30];
	printf("Enter the string : ");
	gets(str);				
	push(str);				//calling push method
	pop(str);				//calling pop method
	printf("Reversed string : %s",str);	
	return 0;
}
