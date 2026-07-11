#include<stdio.h>
#define V 100
int p[] = {2,3,5,2,4};
int m[V][V];
int s[V][V];

void mcm(){
    int n = (sizeof(p)/sizeof(p[0])) -1;
    for (int i = 1; i <= n;i++){
        m[i][i] = 0;
    }
    for (int len = 2; len <= n; len++){
        for (int i = 1; i <= n - len + 1;i++){
            int j = i + len - 1;
            m[i][j] = 9999;
            for (int k = i; k < j;k++){
                int cost = m[i][k] + m[k + 1][j]+p[i-1]*p[k]*p[j];
                if(m[i][j]>cost){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}
void pop(int i,int j){
    if(i==j)
        printf("A%d ", i);
    else{
        printf("(");
        pop(i, s[i][j]);
        pop(s[i][j] + 1, j);
        printf(")");
    }
}
int main(){
    mcm();
    pop(1,4);
}