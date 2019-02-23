#include<bits/stdc++.h>
using namespace std;



bool dfsHelper(list<int> *adj, int node,int par, bool *visited){

    visited[node]=true;

    for(auto neib: adj[node]){

        if(visited[neib] and par!= neib ){
            return true;
        }
        if(!visited[neib]){
            bool ans=dfsHelper(adj,neib,node,visited);
            if(ans)
                return true;
        }
    }
    return false;

}

bool check_cycle_dfs(list<int> *adj,int src, int n){

    int par;
    bool visited[n]={false};

    return dfsHelper(adj,src,src,visited);

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

        if (check_cycle_dfs(adj,0,n)){
            cout<<" cycle is present"<<endl;
        }
        else{
            cout<<" No cycle"<<endl;
        }
    }


    return 0;
}
