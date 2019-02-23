#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;

using namespace std;

long find_parent(long x ,long *par){
	while(par[x] !=x){
		par[x]=par[par[x]];
		x=par[x];
	}
	return x;
}

void make_union(long x,long y,long *par,int *cost){
	long p1= find_parent(x,par);
	long p2=find_parent(y,par);

	if(p1==p2){
		return;
	}
	if(cost[p1] >=0 ){
        if((cost[p1]<= cost[p2]) || (cost[p2]<0))
            par[y]=p1;
	}
	else{
		par[x]=p2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
   	#endif

    long n,m; cin>>n>>m;
    long par[n+1];
    for(long i=1;i<=n;i++){
    	par[i]=i;
    }

    vector<pair<long,long>> vec;
    for(long i=1;i<=m;i++){
    	long x,y; cin>>x>>y;
    	vec.pb({x,y});
    }
    int cost[n+1];
    for(int i=1;i<=n;i++){
    	int x;cin>>x;
    	cost[i]=x;
    }

    for(auto p:vec){
    	make_union(p.first,p.second,par,cost);
    }

    set<long> s;
    ll ans=0;
    ll minimum_cost= 1000000;
    ll min_cost_par=-1;

    for(long i=1;i<=n;i++){
        long x= find_parent(i,par);

        if(cost[x] >=0 && cost[x]< minimum_cost){
            minimum_cost=cost[x];
            min_cost_par=x;
        }
    }

    for(long i=1;i<=n;i++){
    	long x=find_parent(i,par);
    	//cout<<x<<" ";

    	if(!s.count(x)){
    		if(cost[x] >=0 && x!=min_cost_par)
    			ans+= (cost[x]+min_cost_par);
    		else if(cost[x] <0){
    			ans=-1;
    			break;
    		}
    		s.insert(x);
    	}
    }

    cout<<ans<<endl;

return 0;
}
