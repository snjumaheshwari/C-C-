#include<bits/stdc++.h>
using namespace std;


list<int> *adj;
int n;
void printGraph(){
	for(int i=0;i<n;i++){
		cout<<i<<" : ";
		for(auto j : adj[i]){
			cout<<j<<" , ";
		}
		cout<<"\n";
	}
}

int main(){
	cin>>n;
	adj=new list<int>[n];

	int m; cin>>m; 
	while(m--){
		int x,y;
		cin>>x>>y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	printGraph();
	return 0;
}