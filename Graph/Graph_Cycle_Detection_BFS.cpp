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

bool bfs(){

    bool *visited= new bool[n]{false};

    int *parent= new int[n];
    int root=0;
    parent[root]=root;

	visited[root]=true;

    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int node= q.front();
        q.pop();

        for(auto neib: adj[node]){
            if(!visited[neib]){
                visited[neib]=true;
                parent[neib]=node;
                q.push(neib);
            }
            else if(visited[neib] && parent[node]!= neib){
                return true;
            }
        }
    }
    return false;

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
        adj[v].push_back(u);
    }
    cout<<bfs();

return 0;
}
