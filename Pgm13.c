/*To read a string and just print it in the reverse order.
@Abhinav B Prasad
26/07/2025*/

#include <stdio.h>
#include <string.h>
int main()
{
	char a[20];
	int i;
	printf("Enter the string : ");
	gets(a);
	printf("Reversed string : ");
	for(i=strlen(a)-1;i>=0;i--)
	{
		printf("%c",a[i]);
	}
	return 0;
}
