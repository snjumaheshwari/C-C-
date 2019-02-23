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

void bfs(){

	int *indegree = new int[n];

	for(int i=0;i<n;i++)
		indegree[i]=0;

	for(int i=0;i<n;i++){
		for(auto neib: adj[i]){
			indegree[neib]++;
		}
	}
	cout<<" Indegree of Each node : ";
	for(int i=0;i<n ;i++){
		cout<<indegree[i]<<" ";
	}
	cout<<endl;

	queue<int> q;

	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	list<int> ans;
	while(!q.empty()){
		int node= q.front();
		q.pop();
		ans.push_front(node);
		for(auto neib: adj[node]){
			indegree[neib]--;

			if(indegree[neib]==0){
				q.push(neib);
			}
		}
	}

	for(auto i: ans){
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
    bfs();

return 0;
}
