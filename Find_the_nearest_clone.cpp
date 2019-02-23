#include<bits/stdc++.h>
using namespace std;


list<int> *adj;

int main(){

    int n,m; cin>>n>>m;
    adj= new list<int>[n+1];

    while(m--){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int,vector<int>> M;
    int colors[n+1];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        colors[i]=x;
        M[x].push_back(i);
    }
    int c; cin>>c;

    int len=M[c].size();
    if(len<2){
        cout<<"-1\n";
        return 0;
    }
    int distance[n+1];

    int ans=n+1;
    for(int i=0;i<len;i++){
        memset(distance,0,sizeof(distance));
        int root= M[c][i];
        distance[root]=0;

        queue<int> q;

        q.push(root);
        while(!q.empty()){
            int node= q.front();
            q.pop();

            for(auto neib: adj[node]){
                if(!distance[neib] && neib!=root){
                    distance[neib]=1+distance[node];
                    q.push(neib);
                }
                if(colors[neib]==c)
                    break ;
            }
        }
        for(auto item: M[c]){
            if(distance[item]!=0){
                ans=min(ans,distance[item]);
            }
        }
        if(ans==1)
            break;
    }
    if(ans!=n+1)
        cout<<ans;
    else
        cout<<"-1";



    return 0;
}