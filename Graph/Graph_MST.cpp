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


int n; 
list<int> *adj;


int *parent;
int *size;

int find_parent(int u){
	while(parent[u]!=u){
		parent[u]=parent[parent[u]];
		u=parent[u];
	}
	return u;
}

void make_union(int x,int y){
	int px= find_parent(x);
	int py=find_parent(y);

	if(px==py) return ;

	if(size[px] >=size[py]){
		size[px]+=size[py];
		parent[py]=px;
	}
	else{
		size[py]+=size[px];
		parent[px]=py;
	}
}

bool comp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2 ){
	return p1.first < p2.first;

}
vector<pair<int,pair<int,int>> > edges;

int main(){

	//FAST; 
    
    READ;WRITE;

   	cin>>n;
    adj= new list<int>[n];

    int m; cin>>m;
    while(m--){
        int u,v,cost; cin>>u>>v>>cost;

        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({cost,{u,v}});
    }
    sort(edges.begin(),edges.end(),comp);

    int mst_weight=0;

    parent= new int[n];
    size=new int[n];
    for(int i=0;i<n;i++){
    	parent[i]=i;
    	size[i]=0;
    }
    for(auto pp: edges){
    	pair<int,int> p= pp.second;
    	int u= p.first;
    	int v=p.second;
    	if(find_parent(u)!=find_parent(v)){
    		cout<<u<<" "<<v<<endl;
    		mst_weight+= pp.first;
    		make_union(u,v);
    	}
    }

    cout<<"\n weight is:"<<mst_weight;
	return 0;

}