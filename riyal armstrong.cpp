#include<stdio.h>
#include<math.h>
int main ()
{
	int n;
	printf ("enter a number to check for armstrong");
	scanf ("%d" ,&n);
	int temp2,temp1;
	temp1=n;
	temp2=n;
	int c=0,x;
	int sum=0,t;
	while (temp1!=0)
	{
		x=temp1%10;
		c++;
		temp1=temp1/10;
	}
	while (temp2!=0)
	{
		t=temp2%10;
		sum=sum+pow(t,c);
		temp2=temp2/10;
	}
	if (sum==n)
	{
		printf("armstrong");	
	}
	else
	{
		printf ("not armstrong");
	}
	return 0;
}
