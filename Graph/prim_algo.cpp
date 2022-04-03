// #include<iostream>
// #include <vector>
// using namespace std;

// int main(){
//     int n, m;
//     cin>>n>>m;
//     vector<pair<int, int>> adj[n]; //Adj List

//     int a, b, wt;

//     for(int i = 0; i < m; i++){
//         cin>>a>>b>>wt;
//         adj[a].push_back(make_pair(b, wt));
//         adj[b].push_back(make_pair(a, wt));
//     }

//     int key[n], parent[n];
//     bool mst[n];

//     for(int i = 0; i< n; i++){
//         key[i] = INT_MAX, mst[i] = false, parent[i] = -1;
//     }

//     key[0] = 0;

//     for(int e = 0; e < n -1; e++){
//         int mini = INT_MAX, u;

//         for(int v = 0; v < n; v++){
//             if(mst[v] == false && key[v] < mini){
//                 mini = key[v], u = v;
//             }
//         }
//         mst[u] = true;

//         for(auto it: adj[u]){
//             int v = it.first;
//             int weight = it.second;
//             if(mst[v] == false && weight < key[v]){
//                 parent[v] = u, key[v] = weight;
//             }
//         }
//     }

//     for(int i = 1; i < n; i++){
//         cout<<parent[i]<<"-"<<i<<endl;
//     }
//     return 0;
// }



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cout<<"Enter Total number of vertex Total number of Edge in the graph"<<endl;
    cin>>n>>m;

    vector<pair<int, int>> adj[n];
    for(int i = 0; i < m; i++){
        cout<<"Enter v u weight"<<endl;
        int a, b,wt;
        cin>>a>>b>>wt;

        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int key[n], parent[n];
    bool mst[n];

    for(int i = 0; i < n; i++){
        key[i] = INT_MAX, parent[i] = -1, mst[i] = false;
    }

    key[0] = 0;

    for(int e = 0; e < n - 1; e++){
        int mini = INT_MAX, u;
        for(int v = 0; v < n; v++){
            if(mst[v] == false && key[v] < mini){
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true;

        for(auto it: adj[u]){
            int v = it.first;
            int weight = it.second;
            if(mst[v] == false && weight < key[v]){
                parent[v] = u, key[v] = weight; 
            }
        }
    }

    for(int i = 1; i < n; i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }
    return 0;
}