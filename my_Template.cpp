#include<bits/stdc++.h>
#define MOD 1000000007
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);

#define pb push_back
#define mp make_pair

#define MAX 100005

typedef long long ll;
typedef long double ld;

const ll inf=1000000000;

using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        int a[n];

        ll count_set_bits[64];
        for(int i=0;i<64;i++)
            count_set_bits[i]=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            int count=0;

            while(a[i]){
                a[i]=a[i] & (a[i]-1);
                count++;
            }
            count_set_bits[count]++;
        }

        ll ans=0;
        for(int i=64;i>0 and k>0;i--){

            int x= min(count_set_bits[i],k);
            k=k-x;
            //cout<<x<<" "<<k<<" "<<count_set_bits[i];
            ans+=x*i;
        }
        cout<<ans<<endl;
  }

  return 0;
}