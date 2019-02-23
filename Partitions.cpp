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
    
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        ll arr[n+1]={0};
        ll ps[n+1]={0};

        for(ll i=1;i<=n;i++){
            cin>>arr[i];
            ps[i]=ps[i-1]+arr[i];
          
        }

        int ans[n+1];
        for(int i=1;i<=n;i++){
            if(ps[n]%i==0)
                ans[i]=1;
            else
                ans[i]=0;
        }

        for(int i=1;i<=n;i++){
            if(ans [i]){
                ll x= ps[n]/i;
                ll y=x;
                for(int j=1;j<=n;j++){
                    if(ps[j] ==y){
                        y+=x;
                    }
                    if(ps[j]> y){
                        ans[i]=0;
                        for(ll k= 2*i; k<=n;k+=i){
                            ans[i]=0;
                        }
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i];
        }
        cout<<"\n";
    }

return 0;
}