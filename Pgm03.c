#include<stdio.h>
int insert(int a[5],int pos)
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
			return pos;
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
				return pos;
			}
			else
				printf("Enter postion in specified range\n");
			return pos;
		}
	}
}
int del(int a[5],int pos)
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
			return pos;
		}
		else
			printf("Element not found\n");
		return pos;
		
	}
}
void search(int a[5],int pos,int e)
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
void array(int a[5],int pos)
{
	int ch,s;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:	pos=insert(a,pos);
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
