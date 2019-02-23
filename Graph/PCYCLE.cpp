#include<bits/stdc++.h>
using namespace std;


int main(){

    int N,x; cin>>N;

    vector< vector<int> > adj(N+1);

    for(int i=1;i<=N;i++){
            cin>>x;
            //adj[x].push_back(i);
            adj[i].push_back(x);
    }

    vector<bool> visited(N+1,false);

    visited[0]=true;

    int cmp=0;
    vector<vector<int >> ans;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            cmp++;
            vector<int> temp;
            temp.push_back(i);
            visited[i]=true;
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int node= q.front();
                q.pop();
                for(auto v: adj[node]){
                    if(!visited[v]){
                        visited[v]=true;
                        temp.push_back(v);
                        q.push(v);
                    }
                }
            }
            temp.push_back(i);
            ans.push_back(temp);
        }

    }

      cout<<cmp<<endl;
        for(auto i: ans){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }

return 0;
}

