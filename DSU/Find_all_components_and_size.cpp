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


int main(){
	int n,m,u,v; cin>>n>>m;

	parent= new int[n];
	size= new int [n];

	for(int i=0;i<n;i++){
		parent[i]=i;
		size[i]=1;
	}

	for(int i=0;i<m;i++){
		cin>>u>>v;
		make_union(u,v);
	}

	ll ans=0;
	for(int i=0;i<n;i++){
		//cout<<i<<" "<<parent[i]<<" "<<size[i];
		if(i==parent[i]){
			ans+=(size[i]-1)*size[i]/2;
		}
	}
	cout<<n*(n-1)/2 -ans;
	return 0;

}