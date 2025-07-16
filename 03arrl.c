#include<stdio.h>
int insert(int a[5],int pos,int e)
{
	if(pos+1==5)
		printf("Error, Array is full");
	else
		a[++pos]=e;
	return pos;
}
int del(int a[5],int pos)
{
	if(pos==-1)
		printf("Error, Array is empty");
	else
		printf("%d is deleted",a[pos--]);
	return pos;
}
void search(int a[5],int pos,int e)
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
void sort(int a[5],int pos)
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
void disp(int a[5],int pos)
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
void array(int a[5],int pos)
{
	int ch,e,s;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:	printf("Enter the value : ");
					scanf("%d",&e);
					pos=insert(a,pos,e);
					break;
			case 2:	printf("Enter value to search : ");
					scanf("%d",&s);
					search(a,pos,s);
					break;
			case 3:	pos=del(a,pos);
					break;
			case 4:	sort(a,pos);
					break;
			case 5:	disp(a,pos);
					break;
			default:printf("Wrong choice.");
		}
	}
}
int main()
{
	int a[5],pos=-1;
	array(a,pos);
	return 0;
}
