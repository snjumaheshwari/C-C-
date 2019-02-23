#include<bits/stdc++.h>
using namespace std;

int N= int(1e6);
vector<bool> primes(N+5,true);


// Prime Seive
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

// Segmented Seive-- finding prime number between a given range
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
            if(j==i){
                j+=i;
            }

            for(; j<=r;j+=i){
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


// Extended Euclid's Algorithm

int G,X,Y;

void extended_euclid(int a,int b){
    // Given two numbers a and b
    // solve ax +by= g , where G= gcd(A,B)

    // compute (1/a)%m

    if(b==0){
        G=a;
        X=1;
        Y=0;
        return;
    }

    extended_euclid(b,a%b);

    int cx= Y;
    int cy= X-(a/b)*Y;
    X=cx;
    Y=cy;

}

int inverseModulo(int a,int m){

    extended_euclid(a,m);
    if(G!=1){
        return -1;
    }
    return (X+m)%m;
}


// Fast Modulo Exponentiation i.e. compute pow(a,b,m)

long long pow(long long a, long b, long long m){

    long long res=1;
    a=a%m;
    while(b){
            if(b&1){
                res=(res*a)%m;
            }

            a=(a*a)%m;
            b=b>>1;
    }
    return (res)%m;

}


long long stringtoint(string s, long long m){

    long long ans=0;
    int n=s.length();

    for(int i=0;i<n;i++){
        ans= (ans*10 )%m + (s[i]-'0');
    }

    return ans%m;
}

long long pow(string a, string b, long long m){


    // fermet little theorem a^(p-1) % p= 1;
    long long res=1;

    long long x=stringtoint(a,m);   // a%m
    long long y=stringtoint(b,m-1);        // b%(m-1);

    return pow(x,y,m);
}


// Linear Diphontine Equation
//General solution - x,y={x0 + (b/g)*t , y0-(a/g)* t}






// Chinese Remainder Theorem




int main(){
    seive();

   /* int t; cin>>t;
    while(t--){
        long long a,b; cin>>a>>b;
        segmented_seive(a,b);
        cout<<"\n";
    }*/


   /*
    extended_euclid(18,30);
    cout<<X<<" "<<Y<<" "<<G<<endl;
    */

    //cout<<pow(2,15,100);

    string a,b;
    cin>>a>>b;
    long long m; cin>>m;

    cout<<pow(a,b,m);




}
