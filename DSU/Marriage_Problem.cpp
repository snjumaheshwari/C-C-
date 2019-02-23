#include<bits/stdc++.h>
using namespace std;

const int MAX=int(1e6)+1;

int parent[MAX+5];
int size[MAX+5];

int find_parent(int x){
	while(x!=parent[x]){
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
int cnt=0;

void make_union(int x,int y){
	int px=find_parent(x);
	int py=find_parent(y);

	if(px==py) return;

	if(size[px]>=size[py]){
		size[px]+=size[py];
		parent[py]=px;
		cnt++;
	}
	else{
		size[py]+=size[px];
		parent[px]=py;
		cnt++;
	}
}

int main(){
	int n,m,x,y; cin>>n>>m;
	cin>>x;

	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}

	while(m--){
			cin>>x>>y;
			make_union(x,y);	
	}
	int q; cin>>q;

	cin>>x;
	while(q--){
		cin>>x>>y;
		make_union(x,y);
		cout<<n-1-cnt<<" ";
	}
	return 0;
}