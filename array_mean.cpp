//wap to compute mean of the user created integer array of size 5 throughh user defined function by passing entire array as arrgument in function
#include<stdio.h>
float mean (int arr[]);
float  mean (int arr[])
{
	int mean,sum=0;
	for (int i=0;i<5;i++)
	{
		sum=sum+arr[i];
	}
	mean=sum/5;
	return mean;
}
int main ()
{
	int arr[5];
	float s;
	printf("input array of size 5");
	for (int i=0;i<5;i++)
	{
		scanf ("%d" ,&arr[i]);
	}
	s=mean(arr);
	printf ("%d mean of the array" ,s);
	return 0;
}
