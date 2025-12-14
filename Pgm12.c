/*To implement stack operation using arrays.
@Abhinav B Prasad
25/07/2025*/

#include <stdio.h>
int a[5],top=-1;
void push()			//function for push operation
{
	int e;
	if(top+1==5)
		printf("Error, Array is full\n");
	else
	{
		printf("Enter the element : ");
		scanf("%d",&e);
		a[++top]=e;
	}
}
void pop()		//function for pop operation
{
	if(top==-1)
		printf("Error, Array is empty\n");
	else
		printf("%d is popped\n",a[top--]);
}
void disp()		//function for displaying stack
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void peek()			//function for displaying top element
{
	if(top==-1)
		printf("Error, Array is empty\n");
	else
		printf("Top element is %d\n",a[top]);
}
int main()
{
	int ch;
	do
	{
		printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
					break;
					
			case 2: pop();
					break;
					
			case 3: peek();
					break;
					
			case 4: disp();
					break;
					
			case 5: printf("You are exited\n");
					break;		
					
			default:printf("Invalid choice");
					break;
		}
	}while(ch!=5);
	return 0;
}
