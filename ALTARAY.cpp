#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		ll a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int dp[n];
		dp[n-1]=1;
		int sign=(a[n-1] >0);
		for(int i=n-2;i>=0;i--){
			if(sign){
					if(a[i]>0){
						dp[i]=1;
					}
					else{
						dp[i]=1+dp[i+1];
					}
			}
			else{
				if(a[i]>0) dp[i]=1+dp[i+1];
				else dp[i]=1;
			}
			sign= a[i]>0;
		}

		for(int i=0;i<n;i++)
			cout<<dp[i]<<" ";

		cout<<endl;
	}

}