#include <stdio.h>
#define V 6
#define E 5
int G[V][V] = {
    {0, 0, 0, 0, 0, 0},  
    {0, 0, 5, 0, 0, 0},
    {0, 0, 0, 1, 2, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, -1, 0}
};
int cost = 0;
struct edge{
    int u;
    int v;
};
struct edge e[E] = {{1,2},{2,4},{2,3},{3,5},{5,4}};
int dist[V];
int pred[V];
void shortestPath(int s, int curr){
    if (curr == s){
        printf("%3d", s);
        return;
    }
    shortestPath(s, pred[curr]);
    cost += G[pred[curr]][curr];
    //printf("%d %d %d", curr,pred[curr], cost);
    printf("->%3d", curr);
}
void printShotestPath(int s){
    printf("Shortest Paths from source is: \n");
    for (int i = 1; i < V; i++){
        cost = 0;
        shortestPath(s, i);
        printf("\tCost : %3d", cost);
        printf("\n");
    }
}
void bellmann_ford(int s){
    for (int i = 1; i < V; i++){
        dist[i] = 999;
        pred[i] = -1;
    }
    dist[s] = 0;
    for (int i = 1; i < V - 1;i++){
        for (int j = 0; j < (sizeof(e) / sizeof(e[0]));j++){
            if(dist[e[j].u]+G[e[j].u][e[j].v] < dist[e[j].v]){
                dist[e[j].v] = dist[e[j].u] + G[e[j].u][e[j].v];
                pred[e[j].v] = e[j].u;
            }

        }
    }
    for (int j = 0; j < (sizeof(e) / sizeof(e[0])); j++){
        if (dist[e[j].u] + G[e[j].u][e[j].v] < dist[e[j].v]){
            printf("Negative cycle exists !!");
            return;
        }
    }
    printShotestPath(s);
}
int main(){
    int s;
    printf("Enter the start Vertex: ");
    scanf("%d",&s);
    bellmann_ford(s);
    return 0;
}

/*
Enter the start Vertex: 1
Shortest Paths from source is:
  1     Cost :   0
  1->  2        Cost :   5
  1->  2->  3   Cost :   6
  1->  2->  3->  5->  4 Cost :   6
  1->  2->  3->  5      Cost :   7
*/