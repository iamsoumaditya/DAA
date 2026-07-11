#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int Hpartition(int arr[],int low,int high){
    int pivot = arr[low];
    printf("Pivot %d\t", pivot);
    int i = low;
    int j = high+1;
    while(i<j){
        do
            i = i + 1;
        while (i <= high && arr[i] <= pivot);
        do
            j = j - 1;
        while (arr[j] > pivot);
        if(i<j)
            swap(arr, i, j);
    }
    swap(arr, j, low);
    return j;
}
void quick_sort(int arr[],int low,int high){
    if(low<high){
        if(high-low+1 >5){
            int r = rand() % (high - low + 1) + low;
            printf("Rand %d\n",r);
            swap(arr, low, r);
        }
        int j = Hpartition(arr, low, high);
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}
int main(){
    int n;
    int arr[100];
    srand(time(0));
    //printf("Enter the no of elements to be entered in the array: ");
    //scanf("%d", &n);
    n = rand() % 10 + 3;
    printf("The no of elemnts are: %d\n",n);
    // printf("Enter the elements of the array: ");
    for (int i = 0; i < n;i++)
        //scanf("%d",&arr[i]);
        arr[i] = rand() % 100;
    printf("The elements of the array: ");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    quick_sort(arr, 0, n - 1);
    printf("The elements of the array after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}