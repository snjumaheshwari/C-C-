#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){

	int t; cin>>t;

	while(t--){
		int n,m; cin>>n>>m;
		int dp[n+1];
		dp[1]=2;
		dp[2]=2;

		for(int i=3;i<=n;i++){
			dp[i]=(dp[i-1]+dp[i-2])%m;
		}

		cout<<dp[n]%m<<endl;

	}

	return 0;
}