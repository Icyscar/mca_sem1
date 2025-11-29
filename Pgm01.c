/*To find the orccarance of an element in an Integer array
@Abhinav B Prasad
10/07/2025*/

#include<stdio.h>
int a=11,b=70;	        //global var
void display()
{
	int c=25;			//local var
	static int d=100;	//static var
	printf("Local var: %d\tStatic var: %d\n",c++,d++);
}
int main()
{
	register int e=11;	//register var
	printf("Global var: %d %d\n",a,b);
	display();
	display();
	display();
	printf("Register var: %d",e);
	return 0;
}
