//wap that adds two matrices of the same dimenssions 
#include<stdio.h>
int main ()
{
	int row1,coloumn1;
	printf ("enter dimenssions of matrix 1");
	scanf("%d%d" ,&row1,&coloumn1);
    int a[row1][coloumn1];
    int row2,coloumn2;
	printf ("enter dimenssions for matrix 2");
    scanf ("%d%d" ,&row2,&coloumn2);
    int b[row2][coloumn2];
	int sum[row1][coloumn1];
	if (row1==row2&&coloumn1==coloumn2)
    {
    	for (int i=0;i<row1;i++)
    	{
    		for (int j=0;j<=coloumn1;j++)
    		{
    			scanf ("%d" ,&a[i][j]);
			}
			printf ("\n");
		}
			for (int i=0;i<row2;i++)
    	{
    		for (int j=0;j<=coloumn2;j++)
    		{
    			scanf ("%d" ,&b[i][j]);
			}
			printf ("\n");
		}
			for (int i=0;i<row1;i++)
    	{
    		for (int j=0;j<=coloumn1;j++)
    		{
    			sum[i][j]=a[i][j]+b[i][j];
			}
			printf ("\n");
		}
			for (int i=0;i<row1;i++)
    	{
    		for (int j=0;j<=coloumn1;j++)
    		{
    			printf ("%d" ,sum[i][j]);
			}
			printf ("\n");
		}
	}
	else
	{
		printf("sum cannot be done");
	}
    return 0;
}
