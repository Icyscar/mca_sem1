/*To read n Strings and display them in the ascending order.
@Abhinav B Prasad
26/07/2025*/

#include <stdio.h>
#include <string.h>
int main()
{
	char a[20][20],temp[20];
	int n,i,j;
	printf("Enter the no. of strings : ");
	scanf("%d",&n);
	getchar();				//to remove newline character		
	printf("Enter strings : ");;
	for(i=0;i<n;i++)
	{
		gets(a[i]);			//to read n string
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(a[i],a[j])>0)			//check if string a[i] comes after string a[j]
			{
				strcpy(temp,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],temp);
			}
		}
	}
	printf("Sorted strings : \n");
	for(i=0;i<n;i++)
	{
		printf("%s  ",a[i]);
	}
	return 0;
}
