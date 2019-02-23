#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;

using namespace std;

const int MAX= int(1e6)+5;
int par[MAX];
int cost[MAX];


// WA
int find_parent(int x){
	while(par[x] !=x){
		par[x]=par[par[x]];
		x=par[x];
	}
	return x;
}

void make_union(int x,int y){
	int px= find_parent(x);
	int py= find_parent(y);

	if(px==py){
		return;
	}
	if((cost[py] <0 )|| (cost[px]<=cost[py])){
		par[py]=px;
	}
	else{
		par[px]=py;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
/*	#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
   	#endif
   */	

    int n,m; cin>>n>>m;
  
    for(int i=1;i<=n;i++){
    	par[i]=i;
    }

    vector<pair<int,int>> vec;
    for(int i=1;i<=m;i++){
    	int x,y; cin>>x>>y;
    	vec.pb({x,y});    	
    }
    for(int i=1;i<=n;i++){
    	int x;cin>>x;
    	cost[i]=x;
    }

    for(auto p:vec){
    	make_union(p.first,p.second);
    }

  
  	long long ans=0;
  	int cnt=0;
  	int min_cost=1000000;
  	bool flag=true;

    for(int i=1;i<=n;i++){
    	if(par[i]==i){
    		if(cost[i]==-1){
    			flag=false;
    		}
    		else{
    			ans+=cost[i];
    			min_cost=min(min_cost,cost[i]); 
    		}
    		cnt++;
    	}
	}
    if(flag){
    	ans+= (cnt-2)*min_cost;
    	cout<<ans;
    }
    else{
    		if(cnt==1){
    			cout<<"0\n";
    		}
    		else{
    			cout<<"-1\n";
    		}
    	}
return 0;
}