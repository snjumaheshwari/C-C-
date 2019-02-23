
#include<bits/stdc++.h>
#define TLe ios_bas::sync_with_stdio(false); cin.tie():cout.tie(NULL);
using namespace std;


void bfs(queue<pair<int,int>> q, vector<vector<int,int>> a,vector<pair<int,int>> &visited){

    while(!q.empty()){

        int node=q.front().first;
        int s= q.front().second;
        q.pop();
        visited[node].first++;
        visited[node].second=node;

        if(s>0){
            for(auto neib: adj[node]){
                if()

            }

        }



    }


}

int main(){

    int t; cin>>t;
    while(t--){

        int n,r,m,u,v; cin>>n>>r>>m;

        vector< vector<int>> adj(n+1);

        while(r--){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int> > q;
        while(m--){
            cin>>u>>v;
            q.push({u,v});
        }

        int visited[n+1]={0};
        bfs(q,adj,visited);
    }

}
