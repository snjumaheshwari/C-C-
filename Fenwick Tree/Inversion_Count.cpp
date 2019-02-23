#include<bits/stdc++.h>
using namespace std;

long a  [2000005];
long BIT[10000005];
void update(long i,long val,long n){

    while(i<=n){
        BIT[i]+= val;
        i+= (i &(-i));
    }

}
long query(long i){

    long ans=0;
    while(i>=1){
        ans+= BIT[i];
        i-=(i &(-i));
    }
    return ans;
}

int main(){

    int t; cin>>t;
    while(t--){
            memset(BIT,0,sizeof(BIT));
        long n; cin>>n;
        long m=0;
        for(long i=1;i<=n;i++){
            cin>>a[i];
            m=max(a[i],m);
        }

        long long ans=0;
        for(long i=n;i>=1;i--){
            ans+= query(a[i]-1);
            update(a[i],1,m);

        }
        cout<<ans<<endl;
    }
}
