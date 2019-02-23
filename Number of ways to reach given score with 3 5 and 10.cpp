#include<bits/stdc++.h>
using namespace std;

int main(){

	int dp[4][1001];

	for(int i=0;i<4;i++){
		for(int j=0;j<=1000;j++){
			dp[i][j]=0;
		}
	}
	for(int j=1;j<=1000;j++){
		if(j%3==0)
			dp[1][j]=1;
	}


	dp[2][5]=1;
	for(int j=1;j<=1000;j++){
		if(j<5){
			dp[2][j]=dp[1][j];
		}
		else if(j>5)
			dp[2][j]=dp[1][j] + dp[2][j-5];
	}
	
	
	dp[3][10]=2;

	for(int j=1;j<=1000;j++){
		if(j<10){
			dp[3][j]=dp[2][j];
		}
		else if(j >10)
		dp[3][j]=dp[2][j]+ dp[3][j-10];
	}


	/*for(int i=1;i<=3;i++){
		for(int j=1;j<=25;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/

	int table[1001]={0};
	table[0]=1;
	int s[]={3,5,10};
	int m=3;
	for(int i=0;i<m;i++){
		for(int j=s[i];j<=1000;j++){
			table[j]+= table[j-s[i]];
		}
	}

	for(int i=1;i<=1000;i++){
		if(dp[3][i]!=table[i])
			cout<<i<<" ,"<<dp[3][i]<<table[i]<<endl;
	}


	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		cout<<dp[3][n]<<"\n";
	}





}