/*To display the array elements in reverse order using recursive function
@Abhinav B Prasad
24/07/2025*/

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
void disp(int a[],int n)		//display function
{
	if(n==0)
	{
		printf("%d  ",a[n]);
		return;
	}
	printf("%d  ",a[n]);		//print before calling the same function	
	disp(a,n-1);				//calling same function
}
int main()
{
	read();
	disp(a,n-1);
	return 0;
}
