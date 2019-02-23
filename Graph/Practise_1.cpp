#include<bits/stdc++.h>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t; cin>>t;
    int u,v;
    while(t--){
        int n; cin>>n;
        list<int>adj[n];

        int e; cin>>e;
        for(int i=0;i<e;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool visited[n] ={false};
        int cmp=0;
        for(int i=0;i<n;i++){

            if(!visited[i]){
                visited[i]=true;
                queue<int> q;
                q.push(i);
                cmp++;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();

                    for(auto neib: adj[node]){
                        if(!visited[neib]){
                            visited[neib]=true;
                            q.push(neib);
                        }
                    }

                }
            }

        }
        cout<<cmp<<"\n";
    }



}
