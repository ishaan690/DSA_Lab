#include<stdio.h>
int main ()
{
	int row1,coloumn1,flag;
	printf ("enter rows and colouns of matrix1 :");
	scanf ("%d%d" ,&row1,&coloumn1);
	int a[row1][coloumn1];
	for (int i=0;i<row1;i++)
	{
		for (int j=0;j<coloumn1;j++)
    	{
    		scanf ("%d" ,&a[i][j]);
		}
		printf ("\n");
	}
    for (int i=0;i<row1;i++)
	{
		for (int j=0;j<coloumn1;j++)
    	{
    		printf ("%d" ,a[j][i]);
		}
		printf ("\n");
	}
	for (int i=0;i<row1;i++)
	{
		for (int j=0;j<coloumn1;j++)
    	{
    		if (a[i][j]!=a[j][i])
    		{
    			flag= 0;
    			break;
			}
		}
		printf ("\n");	
    }
    if (flag==1)
    {
    	printf ("symmetric");
	}
	else 
	{
		printf ("non symmetric");
	}
    return 0;
}
