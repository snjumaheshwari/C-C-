#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll profit(int arr[], int n)
{
	ll dp[n][n];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++)
		dp[i][i]=arr[i]*n;

	

	for(int diff=1; diff<= n-1;diff++)
	{
		int yr= n-diff;
		for(int i=0;i<n-diff;i++)
		{

			dp[i][i+diff]= max(
				(dp[i][i+diff-1] + yr*arr[i+diff]),
				(dp[i+1][i+diff]+ yr*(arr[i]))

				);


		}

	}
	

return dp[0][n-1];
}


int main()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	ll ans= profit(arr,n);
	cout<<ans<<endl;
}
