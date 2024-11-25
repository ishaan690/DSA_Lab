#include<stdio.h>
int main ()
{
	int row1,coloumn1,row2,coloumn2;
	printf ("enter rows and colouns of matrix1 :");
	scanf ("%d%d" ,&row1,&coloumn1);
	int a[row1][coloumn1];
	printf ("enter rows and colouns of matrix2 :");
	scanf ("%d%d" ,&row2,&coloumn2);
	int b[row2][coloumn2];
		if 	(row1==row2 && coloumn1==coloumn2)
	{
			for (int i=0;i<row1;i++)
      	{
    		for (int j=0;j<coloumn1;j++)
    		{
    			scanf ("%d" ,&a[i][j]);
			}
			printf ("\n");
		}
		for (int i=0;i<row2;i++)
    	{
    		for (int j=0;j<coloumn2;j++)
    		{
    			scanf ("%d" ,&b[i][j]);
			}
			printf ("\n");
		}
		//	for (int i=0;i<row1;i++)
    //	{
    //		for (int j=0;j<coloumn1;j++)
    //		{
    //			printf ("%d\t" ,a[i][j]);
	//		}
	//		printf ("\n");
	//	}
	//		for (int i=0;i<row2;i++)
    //	{
    //		for (int j=0;j<coloumn2;j++)
    //		{
    //			printf ("%d\t" ,b[i][j]);
	//		}
	//		printf ("\n");
	//	}
			for (int i=0;i<row1;i++)
    	{
    		for (int j=0;j<coloumn1;j++)
    		{
    			printf ("%d\t" ,(a[i][j]+b[i][j]));
			}
			printf ("\n");
		}
	}
		return 0;
}
