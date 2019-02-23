#include<bits/stdc++.h>
using namespace std;

int n;
list<int> *adj;


void BFS(int n){
	int root=0;

	queue<int> q;
	bool *visited = new bool[n];
	int *dist= new int[n]{0};

	q.push(root);
	visited[root]=true;
	dist[root]=0;

	while(!q.empty()){
		int node= q.front();
		cout<<node<<" ";
		q.pop();
		for(auto neib: adj[node]){
			if(!visited[neib]){
				q.push(neib);
				visited[neib]=true;
				dist[neib]=dist[node]+1;
			}
		}
	}
}

int main(){
	cin >> n;
	adj= new list<int>[n];

	int m; cin>>m;

	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	BFS(n);

	return 0;
}