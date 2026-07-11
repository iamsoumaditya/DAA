#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void adjustHeap(int arr[],int i,int n){
    int key = arr[i];
    int j = 2 * i;
    while (j <= n){
        if (j < n &&arr[j] < arr[j + 1])
            j = j + 1;
        if (key > arr[j])
            break;
        arr[j / 2] = arr[j];
        j *= 2;
    }
    arr[j / 2] = key;
}
void makeHeap(int arr[],int n){
    for (int i = n / 2; i >= 1; i--)
        adjustHeap(arr, i, n);
}
void heapSort(int arr[],int n){
    makeHeap(arr,n);
    for (int i = n; i >= 2;i--){
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        adjustHeap(arr, 1, i - 1);
    }
}
int main(){
    srand(time(0));
    int n = rand() % 10 + 3;
    printf("The size of the array is: %d\n",n);
    int arr[n+1];
    for (int i = 1; i <= n;i++)
        arr[i] = rand() % 100;
    printf("The elements of the array: ");
    for (int i = 1; i <= n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    heapSort(arr, n-1);
    printf("The elements of the array after sorting: ");
    for (int i = 1; i <= n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}