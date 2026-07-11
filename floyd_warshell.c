#include<stdio.h>
#define V 5
#define INF 99999

int w[V][V] = {
    {0, 4, 2, INF, INF},
    {INF, 0, 1, 5, INF},
    {INF, INF, 0, 8, 10},
    {INF, INF, INF, 0, 2},
    {INF, INF, INF, INF, 0}};
int p[V][V];
int d[V][V];

void floyd_warshell(){
    for (int i = 0; i < V;i++){
        for (int j = 0; j < V; j++){
            d[i][j] = w[i][j];
            if(w[i][j] == 0)
                p[i][j] = -1;
            else
                p[i][j] = i;
        }
    }
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if(d[i][k]+d[k][j] <d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}
void apsp(int i,int j){
    if(i==j)
        printf("%d", i);
    else if(p[i][j] == -1){
        printf("No path!!\n");
        return;
    }else{
        apsp(i, p[i][j]);
        printf(" -> %d", j);
    }

}
int main(){
    floyd_warshell();
    apsp(0, 1);
    printf("\n");
    apsp(0, 2);
    printf("\n");
    apsp(0, 3);
    printf("\n");
    apsp(0, 4);
    printf("\n");
    apsp(1, 4);
    printf("\n");
    apsp(2, 4);
    return 0;
}