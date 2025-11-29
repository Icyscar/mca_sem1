/*To sort the array elements in ascending order
@Abhinav B Prasad
23/07/2025*/

#include <stdio.h>
int a[20],n;
void read()
{
	int i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void disp()
{
	int i;
	printf("Elements are : ");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}
void sort()
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	read();
	disp();
	sort();
	disp();
	return 0;
}
