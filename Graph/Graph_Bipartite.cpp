#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front
#define READ freopen("in.txt","r",stdin);
#define WRITE freopen("out.txt","w",stdout);
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MOD = int(1e9)+7;
const int MAX = int(1e5)+5;
const ll inf= int(1e18)+1;

using namespace std;

list<int> *adj;
int n;


void bfs(){
	bool *visited= new bool[n]{false};
	int *color= new int[n];
	//memset(color,0,sizeof(color));

	int root=0;
	color[root]=1;
	visited[root]=true;

	queue<int> q;
	q.push(root);
	bool flag=true;

	while(!q.empty() &&flag){
		int node= q.front();
		q.pop();

		for(auto neib: adj[node]){
			if(visited[neib]){
				if(color[neib]== color[node]){
					flag=false;
				}
			}
			else{
				color[neib]=1-color[node];
				q.push(neib);
				visited[neib]=true;
			}
		}
	}

	if(flag){
		for(int i=0;i<n;i++){
			cout<<color[i]<<" ";
		}
	}
	else{
		cout<<"Not bi-partite\n";
	}
}

void dfsHelper(int node,bool *visited, int *color, bool flag){
	if(!flag)
		return;

	visited[node]=true;

	for(auto neib: adj[node]){
		if(visited[neib]){
			if(color[neib]== color[node]){
				flag=false;
			}
		}
		else{
			color[neib]=1-color[node];
			dfsHelper(neib,visited,color,flag);
		}
	}

}
void dfs(){
	bool *visited= new bool[n]{false};
	int *color= new int[n];

	bool flag=true;
	int root=0;
	color[root]=0;
	dfsHelper(root,visited,color,flag);
	if(flag){
		for(int i=0;i<n;i++){
			cout<<color[i]<<" ";
		}
	}
	else{
		cout<<"Graph is bi-partite\n";
	}
}


int main(){
	//FAST; 	 
    READ;WRITE;
   	cin>>n;
    adj= new list<int>[n];

    int m; cin>>m;
    while(m--){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(); // check graph is bipartite using bfs
    cout<<endl;
    dfs(); // check graph is bipartite using dfs


    return 0;
}