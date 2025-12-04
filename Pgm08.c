/*To add two matrices and also subtraction of 1 matrix from the other
@Abhinav B Prasad
25/07/2025*/

#include <stdio.h>
int a[10][10],b[10][10],m,n;
int c[10][10];
void read()				//function for reading 2 matrices
{
	int i,j;
	printf("Enter the no. of rows and columns : ");
	scanf("%d%d",&n,&m);
	printf("Enter the elements of 1st matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements of 2nd matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
}
void disp(int a[10][10])			//function for displaying matrix
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
void add()					//function of adding 2 matrices
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
void sub()					//function of subtracting 2 matrices
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
}
int main()
{
	int i,ch;
	read();
	printf("Matrix 1 :\n");
	disp(a);
	printf("Matrix 2 :\n");
	disp(b);
	do
	{
		printf("\n1. Add\n2. Subtract\n3. Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add();
					disp(c);
					break;
					
			case 2: sub();
					disp(c);
					break;
			
			case 3: printf("\nYou are exited");
					break;
					
			default:printf("\nInvalid choice");
					break;
		}
	}while(ch!=3);
	return 0;
}
