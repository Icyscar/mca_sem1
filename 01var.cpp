#include<stdio.h>
int a=10,b=10;	//global var
void display()
{
	int c=10;
	static int d=10; 	//static var
	printf("%d\t%d\n",c++,d++);
}
int main()
{
	register int e=11;	//register var
	int b=5;		//local var
	printf("%d %d\n",a,b);
	display();
	display();
	display();
	printf("%d",e);
	return 0;
}
