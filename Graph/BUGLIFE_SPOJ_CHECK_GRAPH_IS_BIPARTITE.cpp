
#include<bits/stdc++.h>
using namespace std;
const int M= int(1e9)+7;


bool bfs(list<int> *adj, int N){

    bool flag=true;

    //bool visited[N+1]={false};
    int color[N+1];
    for(int i=1;i<=N;i++)
        color[i]=-1;



    for(int i=1;i<=N;i++){

        if(color[i]==-1){
            color[i]=1;

            queue<int> q;
            q.push(i);

            while(!q.empty()){

                int node= q.front();
                q.pop();

                for(auto neib: adj[node]){
                    if(color[neib]==-1){
                        color[neib]= 1-color[node];
                        q.push(neib);
                    }
                    else if(color[neib]== color[node]){
                        return false;
                    }
                }
            }
        }

    }

    return true;
}

int main(){

    int u,v;

    int t; cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Scenario #"<<i<<":\n";
        int N,m; cin>>N>>m;

        list<int>adj[N+1];

        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(bfs(adj,N)){
            cout<<"No suspicious bugs found!\n";
        }
        else{
            cout<<"Suspicious bugs found!\n";
        }
    }

return 0;
}
