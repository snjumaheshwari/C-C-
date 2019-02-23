#include<bits/stdc++.h>
using namespace std;


int dp[1000002];


int main(){

	dp[0]=0;
	for(int i=1;i<=1000000;i++){
		bool flag=false;
		int j=i;
		while(j){
			int x= j%10;
			j=j/10;
			if(x==4){
				flag=true;
				break;
			}
		}
		if(flag){
			dp[i]=dp[i-1]+1;
		}
		else
			dp[i]=dp[i-1];

	}

	/*for(int i=1;i<=100;i++){
		cout<<dp[i]<<" "<<endl;
	}*/
	int t; cin>>t;
	while(t--)
	{	int n; cin>>n;

		cout<<dp[n]<<endl;
	}
	return 0;
}