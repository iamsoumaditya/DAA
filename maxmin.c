#include<stdio.h>

void maxmin(int arr[],int i,int j,int *max,int *min){
    if(i==j){
        *max = *min = arr[i];
        return;
    }
    if(i == j-1){
        if(arr[i]<arr[j]){
            *max = arr[j];
            *min = arr[i];
            return;
        }
        *max = arr[i];
        *min = arr[j];
        return;
    }
    int mid = i + (j - i) / 2;
    int max1, min1;
    maxmin(arr, i, mid, max, min);
    maxmin(arr, mid+1, j, &max1, &min1);
    if(max1 > *max)
        *max = max1;
    if(*min > min1)
        *min = min1;
}

int main(){
    int n,max,min;
    int arr[100];
    printf("Enter the no of elements to be entered in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    maxmin(arr, 0, n - 1, &max, &min);
    printf("The minimum and maximum elements are %d & %d respectively.\n", min, max);
    return 0;
}