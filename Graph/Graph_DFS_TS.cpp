#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;
using namespace std;

list<int> *adj;
int n;


void dfshelper(int node,bool *visited,vector<int> &ans){

    visited[node]=true;

    for(auto neib: adj[node]){
        if(!visited[neib]){
            dfshelper(neib,visited, ans);
        }
    }

    ans.push_back(node);
}

void dfs(){
    bool *visited= new bool[n];
    vector<int> ans;

    int root=0;
    dfshelper(root,visited,ans);

    for(auto i :ans){
        cout<<i<<" ";
    }
}




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
   	#endif

    cin>>n;
    adj= new list<int>[n];

    int m; cin>>m;
    while(m--){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    dfs();

return 0;
}
