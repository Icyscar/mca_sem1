/*To multiply two matrices.
@Abhinav B Prasad
25/07/2025*/

#include <stdio.h>
int a[10][10],b[10][10];
int c[10][10];
void read(int n,int m,int p,int q)
{
	int i,j;
	printf("Enter the elements of 1st matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements of 2nd matrix : ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
}
void disp(int a[10][10],int n,int m)
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
void prod(int n,int m,int p,int q)
{
	int i,j,k;
	if(m==p)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<q;j++)
			{
				for(k=0;k<m;k++)
				{
					c[i][j]=c[i][j]+a[i][k]*b[k][j];
				}
			}
		}
		disp(c,n,q);
	}
	else
		printf("Multiplication not possible.\n");
}
int main()
{
	int i,ch,n,m,p,q;
	printf("Enter the no. of rows and columns for 1st Matrix: ");
	scanf("%d%d",&n,&m);
	printf("Enter the no. of rows and columns for 2nd Matrix: ");
	scanf("%d%d",&p,&q);
	read(n,m,p,q);
	printf("Matrix 1 :\n");
	disp(a,n,m);
	printf("Matrix 2 :\n");
	disp(b,p,q);
	printf("Product : \n");
	prod(n,m,p,q);
	return 0;
}
