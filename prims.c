#include <stdio.h>
#include <limits.h>
#define V 9

int key[V];
int parent[V];
int mstSet[V];
#define V 9

int graph[V][V] = {
    //   0   1   2   3   4   5   6   7   8
    {0, 4, 0, 0, 0, 0, 0, 8, 0},   // Node 0
    {4, 0, 8, 0, 0, 0, 0, 11, 0},  // Node 1
    {0, 8, 0, 7, 0, 4, 0, 0, 2},   // Node 2
    {0, 0, 7, 0, 9, 14, 0, 0, 0},  // Node 3
    {0, 0, 0, 9, 0, 10, 0, 0, 0},  // Node 4
    {0, 0, 4, 14, 10, 0, 2, 0, 0}, // Node 5
    {0, 0, 0, 0, 0, 2, 0, 1, 6},   // Node 6
    {8, 11, 0, 0, 0, 0, 1, 0, 7},  // Node 7
    {0, 0, 2, 0, 0, 0, 6, 7, 0}    // Node 8
};

int getMin(){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++){
        if (mstSet[i] == 0 && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void printMst(int s){
    int totalCost = 0;
    printf("The MST of the graph is:\n");
    for (int i = 0; i < V; i++){
        if (i != s){
            printf("%d - %d => %d\n", i, parent[i], graph[i][parent[i]]);
            totalCost += graph[i][parent[i]];
        }
    }
    printf("\nTotalcost of the MST: %3d",totalCost);
}
void prims(int s){
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mstSet[i] = 0;
    }
    key[s] = 0;
    for (int i = 0; i < V; i++){
        int u = getMin();
        mstSet[u] = 1;
        for (int v = 0; v < V; v++){
            if (graph[u][v] && mstSet[v] == 0){
                if (graph[u][v] < key[v]){
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    printMst(s);
}

int main(){
    prims(2);
    return 0;
}

/*
Output:-

The MST of the graph is:
0 - 7 => 8
1 - 0 => 4
3 - 2 => 7
4 - 3 => 9
5 - 2 => 4
6 - 5 => 2
7 - 6 => 1
8 - 2 => 2

Totalcost of the MST:  37
*/