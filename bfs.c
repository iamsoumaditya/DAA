#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define V 100
#define MAX 100
int queue[MAX];
int front =0, rear = 0;
int graph[100][100];
// int graph[100][100] = {
//     {0, 1, 1, 0, 0},
//     {1, 0, 0, 1, 0},
//     {1, 0, 0, 0, 1},
//     {0, 1, 0, 0, 0},
//     {0, 0, 1, 0, 0}
// };
int n=5;
int isEmpty(){
    if(front == rear)
        return 1;
    return 0;
}
int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow!!");
        return INT_MIN;
    }
    front = (front + 1) % MAX;
    return queue[front];
}
void enqueue(int val){
    if((front+1)%MAX == front){
        printf("Queue Overflow!!");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
}
void bfs(int s){
    int visited[n];
    for (int i = 0; i < n;i++)
        visited[i] = 0;
    visited[s] = 1;
    enqueue(s);
    while(!isEmpty()){
        int u = dequeue();
        printf("%d\t",u);
        for (int j = 0; j< n;j++){
            if (graph[u][j] == 1 && visited[j]==0){
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
int main(){
    // srand(time(0));
    // int n = rand() % 10 + 3;
    // printf("The size of the array is: %d\n",n);
    // int arr[n+1];
    // for (int i = 1; i <= n;i++)
    //     arr[i] = rand() % 100;
    // printf("The elements of the array: ");
    // for (int i = 1; i <= n;i++)
    //     printf("%d\t",arr[i]);
    // printf("\n");
    // heapSort(arr, n-1);
    // printf("The elements of the array after sorting: ");
    // for (int i = 1; i <= n; i++)
    //     printf("%d\t", arr[i]);
    // printf("\n");
    FILE *fp;
    fp = fopen("graph.txt", "r");
    if(fp == NULL){
        printf("Error while file is opening\n");
        exit(1);
    }
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
         fscanf(fp, "%d", &graph[i][j]);
         
        }
    }
    fclose(fp);
    bfs(1);
}