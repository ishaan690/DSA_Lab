#include<stdio.h>
int main ()
{
	int rev=0,x;
	int n,t;
	printf ("enter any integer\n");
	scanf("%d" ,&n);
	t=n;
	while(n!=0)
	{
		x=n%10;
		rev=rev*10+x;
		n=n/10;
	}
	printf ("%d" ,rev);
	if(rev==t)
	{
		printf("number is palindrom");
	}
	else
	{
		printf("number is not palindrom");
	}
	return 0;
}

