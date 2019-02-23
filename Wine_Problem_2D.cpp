 #include<bits/stdc++.h>
#include<iostream>

using namespace std;


int cnt=0;
int flag=0;

int profit(int arr[], int start, int end, int yr=1)
{
	cnt++;

	if(start==end)
		return yr*arr[start];
	int q1= arr[start]*yr + profit(arr,start+1, end, yr+1);
	int q2= arr[end]*yr + profit(arr, start, end-1, yr+1);

	int ans= max(q1,q2);
	return ans;

}


int memo[100][100]={0};

int profit_memo(int arr[], int start, int end, int yr=1)
{
	flag++;

	if(start==end)
		return yr*arr[start];

	if(memo[start][end]!=-1)
		return memo[start][end];

	int q1= arr[start]* yr + profit_memo(arr, start+1,end,yr+1);
	int q2= arr[end] *yr + profit_memo(arr,start,end-1,yr+1);

	int ans= max(q1,q2);
	memo[start][end]=ans;
	return ans;

}


int profit_dp(int arr[],int n)
{
	int dp[n][n]={0};
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++)
		dp[i][i]=arr[i]*(n);


	for(int diff=1; diff <=n-1;diff++)
	{
		for(int i=0;i<=n-1-diff;i++)
		{
			dp[i][i+diff]=max( (dp[i][i+diff-1] + arr[i+diff]*(n-diff)), (dp[i+1][i+diff] + arr[i]* (n-diff)) );
		}

	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{

			cout<<setw(3)<<dp[i][j];
		}
		cout<<endl;
	}


	return dp[0][n-1];
}


int main()
{
	int n; cin>>n;
	int arr[n];

	memset(memo,-1,sizeof(memo));
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int ans1=profit(arr,0,n-1,1);
	int ans2=profit_memo(arr,0,n-1,1);

	cout<<ans1<<"  "<<cnt<<endl;  // cnt = pow(2,n)-1
	cout<<ans2<<"  "<<flag<<endl;  // flag =(n*(n-1))+1

	int ans3=profit_dp(arr,n);
	cout<<ans3;
	return 0;
}

