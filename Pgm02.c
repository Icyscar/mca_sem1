#include<stdio.h>
int a[5],pos=-1;
void insert()
{
	int e,k,i;
	if(pos+1==5)
	{
		printf("Error, Array is full\n");
		return;
	}
	else
	{
		if(pos==-1)
		{
			printf("Enter the value to position 0 : ");
			scanf("%d",&e);
			a[++pos]=e;
		}
		else
		{
			printf("Enter the position from 0 to %d where u want to insert : ",pos+1);
			scanf("%d",&k);
			if(k>=0 && k<=pos+1)
			{
				printf("Enter the value : ");
				scanf("%d",&e);
				for(i=pos+1;i>k;i--)
				{
					a[i]=a[i-1];
				}
				a[k]=e;
				pos++;
			}
			else
				printf("Enter postion in specified range\n");
		}
	}
}
void del()
{
	int i,e,j,flag=0;
	if(pos==-1)
		printf("Error, array is empty\n");
	else
	{
		printf("Enter element to delete : ");
		scanf("%d",&e);
		for(i=0;i<=pos;i++)
		{
			if(a[i]==e)
			{
				j=i;
				flag=1;
				printf("%d is deleted from the postion %d\n",a[j],j+1);
				break;
			}
		}
		if(flag!=0)
		{
			for(i=j;i<=pos;i++)
			{
				a[i]=a[i+1];
			}
			pos--;
		}
		else
			printf("Element not found\n");
	}
}
void search(int e)
{
	int i,flag=0;
	for(i=0;i<=pos;i++)
	{
		if(e==a[i])
		{
			printf("Element found at %d position\n",i+1);
			flag=1;
			break;
		}
	}
	if(flag!=1)
		printf("%d is not found\n",e);
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
	if(pos==-1)
	{
		printf("Error, empty array");
		return;
	}
	for(i=0;i<=pos;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
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
	int ch,s;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:	insert();
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
