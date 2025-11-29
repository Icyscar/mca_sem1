/*To find the orccarance of an element in an Integer array
@Abhinav B Prasad
23/07/2025*/

#include <stdio.h>
int main()
{
	int n,i,e,a[20],count=0;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element you want to search : ");
	scanf("%d",&e);
	printf("%d is occured at positions : ",e);
	for(i=0;i<n;i++)
	{
		if(a[i]==e)
		{
			printf("%d  ",i);
			count++;
		}
	}
	if(count==0)
		printf("No occarances");
	return 0;
}
