#include<stdio.h>
void ArrayPrint(int *A,int n){
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}
void InsertionsortSort(int *A,int n){
	for(int i=1;i<n;i++){
		int j=i-1;
		int x=A[i];
		while(j>-1&&A[j]>x){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}
int main(){
	int A[]={5,6,7,12,14,17,10};
	int n=7;
	ArrayPrint(A,n);
	InsertionsortSort(A,n);
	ArrayPrint(A,n);
	return 0;
}
