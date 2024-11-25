#include <stdio.h>
#define SIZE 10
void multiplyMatrices(int (*matrixA)[SIZE], int (*matrixB)[SIZE], int (*result)[SIZE], int rowA, int colA, int rowB, int colB) 
{
    for (int i = 0; i < rowA; ++i) 
	{
        for (int j = 0; j < colB; ++j) 
		{
            result[i][j] = 0;
            for (int k = 0; k < colA; ++k) 
			{
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
void printMatrix(int (*matrix)[SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
	{
        for (int j = 0; j < cols; ++j) 
		{
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int rowA, colA, rowB, colB;
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowA, &colA);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowB, &colB);
    if (colA != rowB) 
	{
        printf("Matrices with entered orders can't be multiplied with each other.\n");
        return 0;
    }
    int matrixA[SIZE][SIZE], matrixB[SIZE][SIZE], result[SIZE][SIZE];
    printf("\nEnter elements of matrix 1:\n");
    for (int i = 0; i < rowA; ++i) 
	{
        for (int j = 0; j < colA; ++j) 
		{
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("\nEnter elements of matrix 2:\n");
    for (int i = 0; i < rowB; ++i) 
	{
        for (int j = 0; j < colB; ++j) 
		{
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }
    void (*multiply)(int (*)[SIZE], int (*)[SIZE], int (*)[SIZE], int, int, int, int);
    multiply = &multiplyMatrices;
    (*multiply)(matrixA, matrixB, result, rowA, colA, rowB, colB);
    printf("\nOutput Matrix:\n");
    printMatrix(result, rowA, colB);
    return 0;
}

