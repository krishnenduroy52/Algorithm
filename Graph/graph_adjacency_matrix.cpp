#include<bits/stdc++.h>
using namespace std;

#define V 5

void addEdge(int graph[][V], int u, int v){
    graph[u][v] = 1;
}

int main(){
    int graph[V][V] = {0};
    int n;
    cout<<"Enter total number of Edge: \n";
    cin>>n;
    for(int i = 0; i < n; i++){
        int a, b;
        cout<<"Enter v and u: \n";
        cin>>a>>b;
        addEdge(graph, a, b);
    }

    for(int i = 0; i< V; i++){
        for (int j = 0; j < V; j++)
        {
            cout<<graph[i][j]<<' ';
        }
        cout<<endl;        
    }
    return 0;
}


// 0, 1
// 0, 4
// 1, 1
// 1, 2
// 1, 3
// 1, 4
// 3, 2
// 3, 4