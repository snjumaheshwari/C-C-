
#include<bits/stdc++.h>
using namespace std;

int N= int(1e5);
vector<bool> primes(N+5,true);

void seive(int n=N){
    primes[0]=false;
    primes[1]=false;

    for( int i=2;i*i<=n;i++){

        if(primes[i]){
            for(int j= i*i; j<=n; j+=i){
                primes[j]=false;
            }
        }
    }
}


void segmented_seive(long long l,long long r){
    vector<bool> pp(r-l+5,true);

    int x= int(sqrt(r)) +2;
    seive(x);

    for(int i=2;i<x;i++){

        if(primes[i]){
            long long j= (l/i)*i;

            if(j<l ){
                j+=i;
            }
            for(; j<=r;j+=i){
                if(i== j)
                    continue;
                pp[j-l]=false;
            }
        }
    }

    if(l==0){
        pp[0]=false;
        pp[1]=false;
    }
    else if(l==1){
        pp[0]=false;
    }

    for(long long i=l;i<=r;i++){
        if(pp[i-l]){
                cout<<i<<"\n";
        }
    }

}

int main(){
    seive();

    int t; cin>>t;
    while(t--){
        long long a,b; cin>>a>>b;
        segmented_seive(a,b);
        cout<<"\n";
    }
}
