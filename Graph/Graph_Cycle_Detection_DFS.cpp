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


bool dfsHelper(int node,int par,bool *visited){

	cout<<node<< " "<<par<<endl;
	visited[node]=true;

	for(auto neib: adj[node]){
		if(visited[neib] && neib !=par){
			return true;
		}
		if(!visited[neib]){
			bool flag= dfsHelper(neib, node,visited);
			if(flag==true){
				return true;
			}
		}
	}
	return false;
}
bool dfs(){

	bool *visited= new bool[n]{false};

	int root=0;

	return dfsHelper(root,root,visited);
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
    cout<<dfs()<<"\n";

return 0;
}
