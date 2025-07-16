#include<stdio.h>
int a[5],pos=-1;
void insert(int e)
{
	if(pos+1==5)
		printf("Error, Array is full");
	else
		a[++pos]=e;
}
void del()
{
	if(pos==-1)
		printf("Erro, Array is empty");
	else
		printf("%d is deleted",a[pos--]);
}
void search(int e)
{
	int i,flag=0;
	for(i=0;i<=pos;i++)
	{
		if(e==a[i])
		{
			printf("Element found at %d position",i+1);
			flag=1;
			break;
		}
	}
	if(flag!=1)
		printf("%d is not found",e);
}
void sort()
{
	int i,j,temp;
	if(pos==-1)
		printf("Error, empty array");
	else
	{
		for(i=0;i<=pos;i++)
		{
			for(j=i+1;j<=pos;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
}
void disp()
{
	int i;
	for(i=0;i<=pos;i++)
	{
		printf("%d\t",a[i]);
	}
}
int menu()
{
	int ch;
	printf("\n1-Insert\n2-Search\n3-Delete\n4-Sort\n5-Display\n6-Exit\nEnter ur choice : ");
	scanf("%d",&ch);
	return ch;
}
void array()
{
	int ch,e,s;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:	printf("Enter the value : ");
					scanf("%d",&e);
					insert(e);
					break;
			case 2:	printf("Enter value to search : ");
					scanf("%d",&s);
					search(s);
					break;
			case 3:	del();
					break;
			case 4:	sort();
					break;
			case 5:	disp();
					break;
			default:printf("Wrong choice.");
		}
	}
}
int main()
{
	array();
	return 0;
}
