#include <stdio.h>
#include <limits.h>
#define V 9

int dist[V];
int pred[V];
int sptSet[V];

int graph[V][V] = {
    //   A   B   C   D   E   F   G   H   I
    //   0   1   2   3   4   5   6   7   8
    {0, 5, 0, 0, 0, 0, 9, 18, 1},  // A (0)
    {5, 0, 7, 0, 0, 0, 0, 0, 0},   // B (1)
    {0, 7, 0, 8, 11, 0, 0, 0, 6},  // C (2)
    {0, 0, 8, 0, 20, 0, 0, 0, 0},  // D (3)
    {0, 0, 11, 20, 0, 4, 0, 0, 2}, // E (4)
    {0, 0, 0, 0, 4, 0, 1, 0, 0},   // F (5)
    {9, 0, 0, 0, 0, 1, 0, 2, 3},   // G (6)
    {18, 0, 0, 0, 0, 0, 2, 0, 0},  // H (7)
    {1, 0, 6, 0, 2, 0, 3, 0, 0}    // I (8)
};
int cost = 0;
int getMin(){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++){
        if (sptSet[i] == 0 && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void shortestPath(int s,int curr){
    if(curr == s){
        printf("%3d", s);
        return;
    }
    shortestPath(s, pred[curr]);
    cost += graph[curr][pred[curr]];
    printf("->%3d", curr);
}
void printShotestPath(int s){
    printf("Shortest Paths from source is: \n");
    for (int i = 0; i < V; i++){
        cost = 0;
        shortestPath(s,i);
        printf("\tCost : %3d", cost);
        printf("\n");
    }
}
void dijkstra(int s){
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        pred[i] = -1;
        sptSet[i] = 0;
    }
    dist[s] = 0;
    for (int i = 0; i < V; i++){
        int u = getMin();
        sptSet[u] = 1;
        for (int v = 0; v < V; v++){
            if (graph[u][v] && sptSet[v] == 0){
                if (dist[u]+graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                    pred[v] = u;
                }
            }
        }
    }
    printShotestPath(s);
}

int main()
{
    dijkstra(2);
    return 0;
}