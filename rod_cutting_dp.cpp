#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;

	while(t--){

		int n; cin>>n;

		int arr[n+1];
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}

		int dp[n+1];
		for(int i=0;i<=n;i++)
			dp[i]=0;

		dp[1]=arr[1];

		for(int i=2;i<=n;i++){

			for(int j=1;j<=i;j++){
				dp[i]=max(dp[i],arr[j]+dp[i-j]);
			}

		}
		/*for(int i=1;i<=n;i++){
			cout<<dp[i]<<" , ";
		}*/
		cout<<dp[n]<<endl;


	}




	return 0;
}