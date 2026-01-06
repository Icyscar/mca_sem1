#include <stdio.h>

int a[20][20], b[20][20], c[20][20];
int sa[50][3], sb[50][3], sc[100][3];
int n1, m1, n2, m2;

// Convert normal matrix to sparse (triplet) form
void convert(int mat[20][20], int s[50][3], int r, int c)
{
    int i, j, k = 1, count = 0;

    for (i = 0; i < r; i++)
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

// Display sparse matrix
void display(int s[100][3])
{
    int i;
    printf("Row\tCol\tVal\n");
    for (i = 0; i <= s[0][2]; i++)
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
}

// Multiply two sparse matrices
void multiply(int sa[50][3], int sb[50][3], int sc[100][3])
{
    int i, j, k, t1, t2, r, c, val;
    int temp[20][20] = {0}; // result in normal form first

    if (sa[0][1] != sb[0][0])
    {
        printf("Matrix multiplication not possible!\n");
        sc[0][2] = 0;
        return;
    }

    // For each non-zero element of A
    for (t1 = 1; t1 <= sa[0][2]; t1++)
    {
        for (t2 = 1; t2 <= sb[0][2]; t2++)
        {
            if (sa[t1][1] == sb[t2][0]) // column of A = row of B
            {
                r = sa[t1][0];
                c = sb[t2][1];
                val = sa[t1][2] * sb[t2][2];
                temp[r][c] += val;
            }
        }
    }
    // Convert result into sparse form
    convert(temp, sc, sa[0][0], sb[0][1]);
}

int main()
{
    int i, j;
    printf("Enter rows and cols of Matrix A: ");
    scanf("%d%d", &n1, &m1);
    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < n1; i++)
        for (j = 0; j < m1; j++)
            scanf("%d", &a[i][j]);
    printf("Enter rows and cols of Matrix B: ");
    scanf("%d%d", &n2, &m2);
    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < n2; i++)
        for (j = 0; j < m2; j++)
            scanf("%d", &b[i][j]);
    convert(a, sa, n1, m1);
    convert(b, sb, n2, m2);
    printf("\nSparse Matrix A:\n");
    display(sa);
    printf("\nSparse Matrix B:\n");
    display(sb);
    multiply(sa, sb, sc);		//calling multiply func
    printf("\nResultant Sparse Matrix (A * B):\n");
    if (sc[0][2] == 0)
        printf("Empty (all zeros)\n");
    else
        display(sc);

    return 0;
}

