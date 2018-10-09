#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000000

using namespace std;

ll k;
vector<ll> a,b,c;


vector<vector<ll> > multiply_matrix(vector<vector<ll> > A, vector<vector<ll> > B)
{
    // multiply two matrix of size k*k and return the matrix of same size..

    vector<vector<ll> > C(k,vector<ll> (k));

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int x=0;x<k;x++)
            {
                C[i][j]= (C[i][j]+(A[i][x]*B[x][j])%MOD)%MOD;

            }
        }
    }
    return C;

}

vector<vector<ll> > power(vector<vector<ll> > A,ll n)
{
    // given a matrix of size k*k .. find its nth power..

        if(n==1)
            return A;
        if(n&1)
            return multiply_matrix(A,power(A,n-1));
        
        vector<vector<ll> > X= power(A,n/2);

         return multiply_matrix(X,X);
}


ll compute(ll n)
{
    vector<vector<ll> > T(k,vector<ll>(k));

    if(n==0)
        return 0;

    if(n<=k)
    {
        return b[n-1];
    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(i<k-1)
            {
                if(j==i+1)
                    T[i][j]=1;
                else
                    T[i][j]=0;

            }
            else
            {
                T[i][j]=c[k-j-1];

            }
        }
    }


    T=power(T,n-1);

    ll result=0;
    for(int i=0;i<k;i++)
        result= (result +((T[0][i])*b[i])%MOD)%MOD;

    return result%MOD;
}


int main()
{
    ll n,num;
    ll test; cin>>test;

    while(test--)
    {

        cin>>k;

        for(int i=0;i<k;i++)
        {
            cin>>num;
            b.push_back(num);
        }
        for(int i=0;i<k;i++)
        {
            cin>>num;
            c.push_back(num);
        }

        cin>>n;
        cout<<compute(n)<<endl;
        b.clear();
        c.clear();
    }
    return 0;




}


