#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
   	#endif

    string s;
    cin>>s;

    int n= s.length();

    int dp[n+1];
    memset(dp,0,sizeof(dp));

    for(int i=n-1;i>=0;i--){
        dp[i]=dp[i+1];
        if ( ( s[i] -'0') %2==0){
            dp[i]++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
return 0;
}
