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
  int t; cin>>t;
  while(t--){
      int R,G;
      cin>>R>>G;
      double dp[1000];
      dp[0]= (double)R/ (R+G);

      double ans=dp[0];

      for(int i=1;i<=G/2;i++){
        double num= (G-2*i+ 2) *(G-2*i+ 1) ;
        double deno= ( (R+G-2*i+1) *  (R+G-2*i));
        if(num!=0 and deno!=0){
          dp[i]= dp[i-1] *num/ deno;
          //cout<<dp[i]<<" ";

          ans+= dp[i];
        }
        else{
          break;
        }

      }
      cout<<ans<<endl;



  }
return 0;

}