/*To find the determinant of given matrix.
@Abhinav B Prasad
25/07/2025*/

#include <stdio.h>
int a[10][10];
void read(int n,int m)			//function to read matrix
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
void disp(int a[10][10],int n,int m)	//function to display matrix
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
void det(int a[10][10],int n,int m)		//function to find determinant
{
	int i,j,det,det1;
	if(n==m)
	{
		if(n==2)
		{
			det=1;
			det1=1;
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i==j)
						det=det*a[i][j];
					else
						det1=det1*a[i][j];
				}
			}
			printf("Determinant : %d\n",det-det1);
		}
		else if(n==3)
		{
			det=0;
			det1=0;
			for(i=0;i<n;i++)
			{
				if(i%2==0)
					det=det+a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3]-a[1][(i+2)%3]*a[2][(i+1)%3]);
				else
					det1=det1-a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3]-a[1][(i+2)%3]*a[2][(i+1)%3]);
			}
			printf("Determinant : %d\n",det-det1);
		}
		else
			printf("\nDeterminant calculation is difficult");
	}
	else
		printf("\nDterminant cannot be calculated");
}
int main()
{
	int i,n,m;
	printf("Enter the no. of rows and columns for Matrix: ");
	scanf("%d%d",&n,&m);
	read(n,m);
	printf("Matrix :\n");
	disp(a,n,m);
	det(a,n,m);
	return 0;
}
