#include<stdio.h>
#define V 5
int m;
int n = V - 1;
int x[V];
int G[V][V] = {{0,0,0,0,0},{0,0,1,0,1},{0,1,0,1,0},{0,0,1,0,1},{0,1,0,1,0}};
void print(){
    for (int i = 1; i <= n; i++){
        printf("%3d\t", x[i]);
    }
    printf("\n");
}
void nextValue(int k)
{
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        int i;
        for (i = 1; i < k; i++)
        {
            if (G[i][k] != 0 && x[i] == x[k])
                break;
        }
        if (i == k)
            return;
    }
}
void mcolouring(int k){
    while(1){
        nextValue(k);
        if(x[k]==0)
            return;
        if(k==n){
            print();
        }else{
            mcolouring(k + 1);
        }
    }
}
int main(){
    printf("Enter the no of colour: ");
    scanf("%d",&m);
    mcolouring(1);
    return 0;
}

/*
OUTPUT: 
Enter the no of colour: 2
  1       2       1       2
  2       1       2       1
*/