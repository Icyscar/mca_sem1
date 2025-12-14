/*To read a String and Reverse the string in the same array itself.
@Abhinav B Prasad
26/07/2025*/

#include <stdio.h>
#include <string.h>
int main()
{
	char a[20],temp;
	int i,l;
	printf("Enter the string : ");
	gets(a);
	l=strlen(a);
	printf("String is %s",a);
	for(i=0;i<l/2;i++)
	{
		temp=a[i];
		a[i]=a[l-1-i];
		a[l-1-i]=temp;
	}
	printf("\nReversed string is %s",a);
	return 0;
}
