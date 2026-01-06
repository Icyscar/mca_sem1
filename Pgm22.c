#include <stdio.h>
int a[20][20],b[20][3],m,n,count;
void display()
{
	int i,j,k=1;
    b[0][0] = n;      // rows
    b[0][1] = m;      // cols
    b[0][2] = count;  // number of non-zero elements
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
	}
	printf("\nSparse Matrix in 3-tuple form:\n");
    printf("Row\tCol\tVal\n");
    for (i=0;i<=count;i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}
void read()
{
	int i,j;
	count=0;
	printf("Enter the no. of rows and cols : ");
	scanf("%d%d",&n,&m);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
				count++;
		}
	}
	if(count<(m*n)/2)
		display();
	else
		printf("Its not a sparse matrix.\n");
}

int main()
{
	read();
	return 0;
}
