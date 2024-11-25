#include<stdio.h>
int sum_cubes(int n)
{
	int x=0,sum=0;
	while(n!=0)
	{
		x=n%10;
		sum=sum+(x*x*x);
		n=n/10;
	}
    return sum;
}
int main()
{
	int n,a;
	printf("enter a number");
	scanf("%d",&n);
	a=sum_cubes(n);
	if (a==n)
		printf("equal");
	else
		printf("not equal");
	return 0;
}
