/*To find the transpose of given matrix.
@Abhinav B Prasad
25/07/2025*/

#include <stdio.h>
int a[10][10];
void read(int n,int m)				//function to read matrix
{
	int i,j;
	printf("Enter the elements of matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void disp(int a[10][10],int n,int m)		//function to display matrix
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}
void trans(int a[10][10],int n,int m)		//function to find transpose
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",a[j][i]);
		}
		printf("\n");
	}
}
int main()
{
	int i,ch,n,m,p,q;
	printf("Enter the no. of rows and columns for Matrix: ");
	scanf("%d%d",&n,&m);
	read(n,m);
	printf("Matrix :\n");
	disp(a,n,m);
	printf("\nTranspose of Matrix is : \n");
	trans(a,n,m);
	return 0;
}
