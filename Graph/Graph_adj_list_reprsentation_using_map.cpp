#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> adj;

void printGraph(){
	for(auto p : adj){
		cout<<p.first<<" : ";
		for(auto j: adj[p.first]){
			cout<<j<<" ";
		}
		cout<<endl;
	}

}

int main(){
	int n; cin>>n; 
	int m; cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	printGraph();


}