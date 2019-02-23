#include<bits/stdc++.h>
using namespace std;


bool check_cycle_bfs(list<int>* adj,int n, int node){

    bool visited[n]={false};
    int par[n];
    queue<int> q;
    q.push(node);
    par[node]=node;


    while(!q.empty()){
        int node= q.front();
        q.pop();

        for(auto neib: adj[node]){
            if(!visited[neib]){
                visited[neib]=true;
                par[neib]=node;
                q.push(neib);

            }
            else if(visited[neib] and par[node] != neib){
                return true;
            }
        }
    }
    return false;
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
            adj[v].push_back(u);
        }

        if(check_cycle_bfs(adj,n, 0)){
            cout<<"cycle is present"<<endl;
        }
    }
    return 0;
}
