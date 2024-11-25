//wap that ask a user to enter 10 intergers and then via user defined function add two arbitary choosen numbers by the user
#include<stdio.h>
int main ()
{
	int a,b,c,m,n;
	int arr[10];
	printf ("enter 10 numbers in array \n");
	for (int i=0;i<10;i++)
	{
		scanf ("%d" ,&arr[i]);
	}
		for (int i=0;i<10;i++)
	{
		printf ("%d\t" ,arr[i]);
	}
	printf ("\n");
	printf ("enter indices for addition");
	scanf ("%d%d" ,&m,&n);
	x=add1(arr[m],arr[n]);
	y=add2(&arr[m],&arr[n]);
    printf ("\n sum of %d and %d is %d using call by value" ,a[m],a[n],x]);
    printf ("\n sum of %d and %d is %d using call by refrence" ,a[m],a[n],y]);
	return 0;
}
int add1(int a,int b)
{
	int c;
	c= a+b;
	return c;
}
int add2(int *a,int *b)
{
	int c;
	c=*a=*b;
	return c;
}


