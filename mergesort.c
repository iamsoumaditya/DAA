#include<stdio.h>

void merge(int arr[],int low,int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int arr1[high - low + 1];
    while (i <= mid && j <= high){
        if(arr[i]>arr[j])
            arr1[k++] = arr[j++];
        else
            arr1[k++] = arr[i++];
    }
    while (i <= mid){
        arr1[k++] = arr[i++];
    }
    while (j <= high){
        arr1[k++] = arr[j++];
    }
    for (int i = low; i <= high;i++)
        arr[i] = arr1[i];
}
void merge_sort(int arr[],int low,int high){
    if(low<high){
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main(){
    int n;
    int arr[100];
    printf("Enter the no of elements to be entered in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n;i++)
        scanf("%d",&arr[i]);
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}