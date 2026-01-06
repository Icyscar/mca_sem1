#include <stdio.h>
int a[20][20], b[20][20], c[20][20];
int sa[50][3], sb[50][3], sc[100][3];
int n, m;
// Function to convert normal matrix into sparse form
void convert(int mat[20][20], int s[50][3], int r, int c)
{
    int i,j,k=1,count=0;

    for (i=0;i<r;i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = mat[i][j];
                k++;
                count++;
            }
        }
    }

    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = count;
}

// Function to add two sparse matrices
void addSparse(int sa[50][3], int sb[50][3], int sc[100][3])
{
    int i = 1, j = 1, k = 1;

    // first row info
    sc[0][0] = sa[0][0];
    sc[0][1] = sa[0][1];

    while (i <= sa[0][2] && j <= sb[0][2])
    {
        if (sa[i][0] < sb[j][0] ||(sa[i][0] == sb[j][0] && sa[i][1] < sb[j][1]))
        {
            sc[k][0] = sa[i][0];
            sc[k][1] = sa[i][1];
            sc[k][2] = sa[i][2];
            i++; k++;
        }
        else if (sb[j][0] < sa[i][0] ||(sb[j][0] == sa[i][0] && sb[j][1] < sa[i][1]))
        {
            sc[k][0] = sb[j][0];
            sc[k][1] = sb[j][1];
            sc[k][2] = sb[j][2];
            j++; k++;
        }
        else // same position ? add values
        {
            sc[k][0] = sa[i][0];
            sc[k][1] = sa[i][1];
            sc[k][2] = sa[i][2] + sb[j][2];
            i++; j++; k++;
        }
    }

    // remaining elements of sa
    while (i <= sa[0][2])
    {
        sc[k][0] = sa[i][0];
        sc[k][1] = sa[i][1];
        sc[k][2] = sa[i][2];
        i++; k++;
    }

    // remaining elements of sb
    while (j <= sb[0][2])
    {
        sc[k][0] = sb[j][0];
        sc[k][1] = sb[j][1];
        sc[k][2] = sb[j][2];
        j++; k++;
    }

    sc[0][2] = k - 1; // total non-zero count
}

// Function to display sparse matrix
void display(int s[100][3])
{
    int i;
    printf("Row\tCol\tVal\n");
    for (i = 0; i <= s[0][2]; i++)
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
}

int main()
{
    int i, j;
    printf("Enter rows and cols of the matrix: ");
    scanf("%d%d", &n, &m);
    printf("\nEnter first matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    printf("\nEnter second matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    convert(a, sa, n, m);
    convert(b, sb, n, m);
    printf("\nSparse form of Matrix A:\n");
    display(sa);
    printf("\nSparse form of Matrix B:\n");
    display(sb);
    addSparse(sa, sb, sc);		//add function call
    printf("\nResultant Sparse Matrix (A + B):\n");
    display(sc);
    return 0;
}

