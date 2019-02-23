#include<bits/stdc++.h>
using namespace std;

#define ll long long
map<int,priority_queue<int,vector<int>> > M;
const int MOD= int(1e9)+7;


ll power(ll a, ll b){
	ll ans=1;

	while(b!=0){
		if(b&1){
			ans=(ans*a)%MOD;
		}
		b=b>>1;
		a=(a*a)%MOD;
	}
	return ans%MOD;

}

void find_pf(ll n){

	map<ll,ll> M1;
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			n=n/i;
			M1[i]++;
		}
	}
	if(n!=1){
		M1[n]++;
	}

	for(auto i:M1){
		ll key=i.first;
		M[key].push(M1[key]);
	}

}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		M.clear();

		long long arr[n+1];

		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}		
		for(int i=1;i<=n;i++){
			find_pf(arr[i]);
		}
		long long ans=1;
		for(auto i: M){
			ll key=i.first;
			ll current= M[key].top();
			M[key].pop();

			int sum=0;
			while(!M[key].empty()){
				ll c= M[key].top();
				sum+=c;
				M[key].pop();
			}

			if( (sum+ current)%2==0 && sum >= current){
				current=0;
			}
			else if( (sum+current)%2==0){
				current= current-sum;
			}
			else if(sum >=current){
				current=1;
			}
			else{
				current-=sum;
			}

			ans= (ans* power(key,current))%MOD;
		}
		cout<<ans<<endl;

	}


	return 0;

}