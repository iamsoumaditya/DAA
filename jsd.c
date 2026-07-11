#include<stdio.h>
int n,m;
int X[100];
float C[100];
int I[100];
int D[100];
int slot[100];
int min(int a,int b){
    if(a>b)
        return b;
    return a;
}
void sort(){
    for (int i = 0; i < n-1;i++){
        for (int j = 0; j < n - i - 1;j++){
            if (C[j] < C[j+1]){
                int ctemp = C[j];
                int dtemp = D[j];
                int itemp = I[j];
                C[j] = C[j + 1];
                D[j] = D[j + 1];
                I[j] = I[j + 1];
                C[j + 1] = ctemp;
                D[j + 1] = dtemp;
                I[j + 1] = itemp;
            }
        }
    }
}
void jsd(){
   sort();
    float credit=0.0;
    for (int i = 0; i < n;i++){
        X[i] = 0;
        slot[i] = 0;
    }
    for (int i = 0; i < n;i++){
        for (int j = min(n, D[i]); j > 0;j--){
            if(slot[j]==0){
                slot[j] = 1;
                X[j] = I[i];
                credit += C[i];
                break;
            }
        }
    }
    printf("Solution Vector is : ");
    for (int i = 1; i <= n;i++){
        printf("%d\t ",X[i]);
    }
    printf("\n");
    printf("The maximum credit earned: %.2f\n",credit);
}
int main(){
    printf("Enter the no of subjects: ");
    scanf("%d",&n);
    for (int i = 0; i < n;i++){
        printf("Enter the credit & deadline of %d elemnts: ",i+1);
        scanf("%f %d", &C[i],&D[i]);
        I[i] = i + 1;
    }
    jsd();
    return 0;
}