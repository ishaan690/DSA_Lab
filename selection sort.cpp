#include<stdio.h>
void printArray(int *a,int n){
	for(int i=0;i < n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int *a,int *b){
	int c=*a;
	*a=*b;
	*b=c;
}

void selectionSort(int *a,int n){
	for(int i=0;i<n-1;i++)
	{
		int indexMin=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[indexMin])
			{
				indexMin =j;
			}
			
		}
		swap(&a[i], &a[indexMin]);
	}
}

int main (){
	  int a[] = {7, 5, 2, 4, 6, 3, 1};
    int n = 7;

    printf("Original array: ");
    printArray(a, n);

    selectionSort(a, n);

    printf("Sorted array: ");
    printArray(a, n);
	return 0;
}
