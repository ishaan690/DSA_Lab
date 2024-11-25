#include<stdio.h>
int main ()
{
	int n,sum=0,temp;
	printf("enter a number for perfect number:");
	scanf ("%d" ,&n);
	temp=n;
	for (int i=1;i<=n;i++)
	{
		if (n%i==0)
		{
			sum=sum+i;
		}
	}
	if (sum==temp)
	{
		printf ("number is perfect");
	}
	else
	{
		printf ("number is not perfect");
	}
	return 0;
}
