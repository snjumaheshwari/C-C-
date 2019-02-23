#include<bits/stdc++.h>
#define MOD 1000000007
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);

#define pb push_back
#define mp make_pair
#define pf push_front
#define MAX 100005

typedef long long ll;
typedef long double ld;

const ll inf=1000000000000000000;

using namespace std;

ll dp[MAX];
ll fun(int n,int m){

	for(int i=0;i<m;i++){
		dp[i]=1;
	}

	for(int i=m;i<=n;i++){
		dp[i]=((dp[i-1])%MOD+ (dp[i-m])%MOD)%MOD;
		
	}
	/*for(int i=0;i<=n;i++){
		cout<<dp[i]<<" ";

	}*/
	return (dp[n]%MOD);


}

int main()
{
	int t; cin>>t;
	
	while(t--){
		int n,m; cin>>n>>m;

		cout<<fun(n,m)<<"\n";

	}

	return 0;
}