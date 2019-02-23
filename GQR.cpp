#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;

using namespace std;

const int MAX= int(1e6)+5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
   	#endif
   

    int n,m; cin>>n>>m;
  
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n-1;i++){
        int j=i+1;
        dp[i][j]=__gcd(arr[i],arr[j]);
    }
    int j;
    for(int d=2;d<n;d++){
        for(int i=0;i+d <n;i++){
             j=i+d;
            dp[i][j]= max(dp[i][j-1],dp[i+1][j]);
            if(arr[j] > dp[i][j])
                dp[i][j]= max(__gcd(arr[i],arr[j]),dp[i][j]);
        }
    }
  
    while(m--){
        int x,y;
        cin>>x>>y;
        x--;y--;
        cout<<dp[x][y]<<"\n";
    }
    
return 0;
}