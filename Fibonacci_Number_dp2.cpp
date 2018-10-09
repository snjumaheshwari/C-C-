#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;



ll fib(int n)
{
	if(n==0 || n==1)
		return n;

	int dp[1000]={};

	dp[0]=0;
	dp[1]=1;

	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main()
{
	DONE;

	int n;
	cin>>n;

	ll ans=fib(n);
	cout<<ans;
	
	return 0;
}