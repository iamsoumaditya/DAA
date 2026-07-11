#include<stdio.h>
int n,m;
float X[100];
int P[100];
int W[100];
void sort(){
    for (int i = 0; i < n-1;i++){
        for (int j = 0; j < n - i - 1;j++){
            if (((float)P[j] / (float)W[j]) < ((float)P[j+1] / (float)W[j+1])){
                int ptemp = P[j];
                int wtemp = W[j];
                P[j] = P[j + 1];
                W[j] = W[j + 1];
                P[j + 1] = ptemp;
                W[j + 1] = wtemp;
            }
        }
    }
}
void fractionalKnapsack(){
    sort();
    int w = m;
    float profit=0.0;
    for (int i = 0; i < n;i++){
        X[i] = 0.0;
    }
    for (int i = 0; i < n;i++){
        if(W[i] > w){
            X[i] = (float)w / (float)W[i];
            profit += P[i] * X[i];
            break;
        }
        X[i] = 1;
        profit += P[i];
        w -= W[i];
    }
    printf("Solution Vector is : ");
    for (int i = 0; i < n;i++){
        printf("%.2f\t ",X[i]);
    }
    printf("\n");
    printf("The maximum profit is: %.2f\n",profit);
}
int main(){
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    printf("Enter the knapsack capacity: ");
    scanf("%d",&m);
    for (int i = 0; i < n;i++){
        printf("Enter the profit & weight of %d elemnts: ",i+1);
        scanf("%d %d", &P[i],&W[i]);
    }
    fractionalKnapsack();
    return 0;
}