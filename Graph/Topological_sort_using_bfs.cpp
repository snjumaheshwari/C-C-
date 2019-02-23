#include<bits/stdc++.h>
using namespace std;


void TS_bfs(list<int> *adj, int src,int n){


    queue<int> q;

    int indegree[n]={0};


    // compute in-degree

    for(int i=0;i<n;i++){
        for(auto v: adj[i]){
            indegree[v]++;
        }
    }

    // push all node with zero in-degree into queue
    for(int i=0;i<n;i++){

        if(indegree[i]==0){
            q.push(i);
        }
    }


    // remove one by one each node and reduce in-degree
    while(!q.empty()){

        int node= q.front();
        cout<<node<<" ";
        q.pop();

        for(auto neib: adj[node]){
            indegree[neib]--;
            if(indegree[neib]==0){
                q.push(neib);
            }

        }
    }

}



int main(){
 int t; cin>>t;
    int u,v;

    while(t--){
        int n; cin>>n;

        list<int> adj[n];

        int m; cin>>m;

        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
        }

        TS_bfs(adj,0,n);
    }
    return 0;

}
