#include<stdio.h>
#include <limits.h>

int graph[100][100];

void addEdge(int u, int v, int wt){
    graph[u][v] = wt;
    graph[v][u] = wt;
}

int minDistance(int dist[], int sptset[], int n){
    int min = INT_MAX, min_index;

    for(int v = 0; v < n; v++){
        if(sptset[v] == 0 && dist[v] <= min){
            min = dist[v], min_index = v;
        } 
    }
    return min_index;
}

void dijkstra(int src, int n){
    int dist[n];
    int sptset[n];

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX, sptset[i] = 0;
    }
    dist[src]  = 0;

    for(int count = 0; count < n - 1; count++){
        int u = minDistance(dist, sptset, n);
        sptset[u] = 1;
        for(int v = 0; v < n; v++){
            if(!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        if(dist[i] != INT_MAX)
            printf("%d \t\t %d\n", i, dist[i]);
}

int main(){
    int n, a, b, wt;
    printf("Number of Edge? : ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &a, &b, &wt);
        addEdge(a, b, wt);
    }

    dijkstra(0, n);
    return 0;
}