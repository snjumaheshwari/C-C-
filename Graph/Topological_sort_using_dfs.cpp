#include<bits/stdc++.h>
using namespace std;


void dfsHelper(list<int> *adj,int node,int n, bool *visited,vector<int> ans){

    visited[node]=true;
    for(auto neib: adj[node]){
        if(!visited[neib]){
            dfsHelper(adj,neib,n,visited, ans);
        }
    }
    ans.push_back(node);

    for(auto i:ans){
        cout<<i<<" ";
    }
}

void TS_dfs(list<int> *adj, int src,int n ){

    bool visited[n]={false};

    vector<int> ans;
    dfsHelper(adj,src,n,visited,ans);


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

        TS_dfs(adj,0,n);
    }


    return 0;
}
