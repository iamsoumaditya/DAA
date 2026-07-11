#include<stdio.h>
#include<stdlib.h>
#define N 100
int n;
int x[N];
void print(){
    for (int i = 1; i <= n;i++){
        printf("%3d\t",x[i]);
    }
    printf("\n");
}
int isSafe(int k,int i){
    for (int j = 1; j < k;j++){
        if((x[j] == i) || (abs(j-k) == abs(x[j]-i)))
            return 0;
    }
    return 1;
}
void nqueen(int k){
    for (int i = 1; i <= n;i++){
        if(isSafe(k,i)){
            x[k] = i;
            if(k==n){
                print();
            }else{
                nqueen(k + 1);
            }
        }
    }
}
int main(){
    printf("Enter number of queens:");
    scanf("%d",&n);
    nqueen(1);
    return 0;
}

/*
Enter number of queens : 4
2 4 1 3
3 1 4 2
*/