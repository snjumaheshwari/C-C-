#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


ll steps(int n)
{
	ll dp[n+1];

	dp[1]=0;
	dp[2]=1;
	dp[3]=1;

	for(int i=4;i<=n;i++)
	{
			if(i%3==0 && i%2==0)
			{
				ll m=min(dp[i/3],dp[i/2]);
				dp[i]=1+min(dp[i-1],m);
			}
			else if(i%3==0)
			{
				dp[i]=1+min(dp[i-1],dp[i%3]);
			}
			else if(i%2==0)
			{
				dp[i]=1+ min(dp[i-1],dp[i/2]);
			}
			else
			{
				dp[i]=1+ dp[i-1];
			}

	}
	return dp[n];
			
}



int main()
{
	DONE;

	int n;
	cin>>n;

	ll ans=steps(n);
	cout<<ans;
	
	return 0;
}