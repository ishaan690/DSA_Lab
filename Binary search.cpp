#include<stdio.h>
int BinarySearch(int *a, int i,int j, int n, int key){
	int i=0;
	int j=n-1;
	if(i<=j)
	{
		int mid=i+j/2
		if(a[mid]==key){
			return key;
		}
			if(a[mid]<key){
			return BinarySearch(a,i,mid+1,key);
		}
		else{
			return BinarySearch(a,i,mid+1,key);
		}
	}
	return -1;
}


int main(){
	int a[]={1,2,3,4,5,6,7}
	int key;
	scanf("%d",&key);
	int n = sizeof(a) / sizeof(a[0]);
	int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    }
    else {
        printf("Element not found\n");
    } 
	return 0;
}
