#include <stdio.h>
int main() 
{
    int n,i,p[10];
    printf("Enter degree of polynomial: ");
    scanf("%d", &n);
    for (i=n;i>=0;i--)     //read coefficients
	{
        printf("\nEnter coefficient of X^%d: ", i);
        scanf("%d", &p[i]);
    }
    printf("\nPolynomial: ");   //display polynomial
    for (i=n;i>=0;i--) 
	{
        printf("%dX^%d",p[i],i);
        if(i!=0)
		{ 
            printf(" + ");
        }
    }
    return 0;
}

