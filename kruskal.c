#include <stdio.h>
#define V 6
#define E 9
struct edge{
    int v1;
    int v2;
    int weight;
};
struct edge e[E]={{0,1,4},{1,2,5},{2,5,6},{4,5,3},{2,4,2},{3,4,1},{3,2,3},{0,3,3},{1,3,2}};
struct edge s[E];
int mstSize = 0;
int p[V];

void sort (int n){
    for (int i = 0; i < n -1;i++){
        for (int j = 0; j < n - i - 1;j++){
            if(e[j].weight > e[j + 1].weight){
                struct edge temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
} 

int find(int u){
    while (p[u] >= 0)
        u = p[u];
    return u;
}

void unionn(int u, int v){
    u = find(u);
    v = find(v);
    p[v] = u;
}
void printMST();
void kruskal(){
    for (int i = 0; i < V; i++)
        p[i] = -1;
    sort(E);
    /*printf("Edges in the MST:\n");
    for (int i = 0; i < E; i++)
        printf("%c -- %c (weight: %d)\n", 'A' + e[i].v1, 'A' + e[i].v2, e[i].weight);*/
    for (int i = 0; i < E; i++){
        int u = e[i].v1;
        int v = e[i].v2;
        //printf("Find(%c) = %d, Find(%c) = %d\n", 'A' + u, find(u), 'A' + v, find(v));
        if (find(u) != find(v)){
            unionn(u, v);
            /* for (int j = 0; j < V; j++)
                 printf("p[%c] = %d ", 'A' + j, p[j]);
             printf("\n");*/
            s[mstSize++] = e[i];
        }
    }
    printMST();
}

void printMST(){
    int totalWeight=0;
    printf("Edges in the MST: - \n");
    for (int i = 0; i < mstSize;i++){
        printf("%c - %c\n",'A'+s[i].v1,'A'+s[i].v2);
        totalWeight += s[i].weight;
    }
    printf("The total weight of MST is %d\n",totalWeight);
}

int main(){
    kruskal();
    return 0;
}