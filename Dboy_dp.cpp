#include<bits/stdc++.h>
#define ll long long
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

const int inf=(int)1e9;
int main(){
	int t; cin>>t;
	
	while(t--){
		ll n,v; cin>>v>>n;
//		ll v; cin>>v;

		ll A[n];

		
		for(ll i=0;i<n;i++){
			cin>>A[i];
		}
		ll dp[v+1];
		for(ll i=0;i<=v;i++){
			dp[i]=inf;
		}
		
		dp[0]=0;

		for(int i=0;i<n;i++){
			if(A[i]<=v){
				dp[A[i]]=1;
			}
		}
		

		for(int i=1;i<=v;i++){
			ll ans=inf;
			for(int j=0;j<n;j++){

				if(A[j]<=i){
					ans=min(ans,1+dp[i-A[j]]);
				}
			}
			dp[i]=min(dp[i],ans);
		}

		if(dp[v]==inf){
			cout<<"-1\n";
		}
		else{
			cout<<dp[v]<<"\n";
		}
		

	}


	return 0;
}