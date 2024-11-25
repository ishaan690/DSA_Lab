#include<stdio.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) { 
                swap(&arr[j], &arr[j + 1]); 
            }
        }
    }
}

int main() {
    int arr[] = {7, 5, 2, 4, 6, 3, 1};
    int n = 7;

    printf("Original array: ");
    printArray(arr, n);

    BubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

