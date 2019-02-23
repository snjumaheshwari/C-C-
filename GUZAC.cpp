#include<bits/stdc++.h>
using namespace std;


#define ll long long
const int inf= int(1e9)+1;


ll sum_upto(ll n){
	return ((n)*(n+1))/2;
}
int main(){

	int t; cin>>t;
	while(t--){
		int n,m,x,y; cin>>n>>m>>x;

		set<int> arr;
		ll sum=0;
		al;

		int minimum=inf;
		for(int i=1;i<=m;i++){
			cin>>y;
			arr.insert(y);
			sum+=y;
			minimum=min(minimum,y);
		}
		ll ans=sum_upto(minimum+x)- sum_upto(minimum+x-n+m)  +sum  ;
		cout<<ans<<endl;

		



	}

	return 0;
}