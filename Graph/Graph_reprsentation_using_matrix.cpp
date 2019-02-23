#include<bits/stdc++.h>
using namespace std;


int main(){
	int n; cin>>n;

	int graph[n+1][n+1];
	memset(graph,0,sizeof(graph));5

	int m; cin>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[u][v]=graph[v][u]=1;
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}



}