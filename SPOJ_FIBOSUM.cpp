#include <bits/stdc++.h>
#define ll long long
#define CCDSAP ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007

using namespace std;

ll k=2;
vector<ll> b,c;
vector<vector<ll> > T(k,vector<ll> (k));


vector<vector<ll> > multiply(vector<vector<ll> >A, vector<vector<ll> >B)
{
	vector<vector<ll> > C(k,vector<ll> (k));

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			for(int x=0;x<k;x++)
			{
				C[i][j]=( C[i][j] + ( A[i][x]* B[x][j] )%MOD ) % MOD;
			}
		}
	}
	return C;
}

vector<vector<ll> > power (vector<vector<ll> >A, ll p)
{
	if(p==1)
		return A;
	
	vector<vector<ll> > X = power(A,p/2);

	X=multiply(X,X);
	if(p&1)
		X=multiply(X,A);
	return X;
}

ll fib(ll n)
{
	if(n==0 || n==1)
		return n;

	// Transformation Matrix
	T[0][0]=0;
	T[0][1]=1;
	T[1][1]=1;
	T[1][0]=1;

	T=power(T,n);

	ll result=0;
	for(int i=0;i<k;i++)
	{
		result= (result+ (T[0][i]* b[i])%MOD)%MOD;
	}
	return result%MOD ;
}

int main()
{
	CCDSAP

	int t; cin>>t;
	ll n,m;

	b.push_back(0);
	b.push_back(1);

	c.push_back(1);
	c.push_back(1);



	while(t--)
	{
		cin>>n>>m;

		ll ans= fib(m+2)- fib(n+1);

		cout<< (ans+MOD)%MOD <<endl;

	}
	return 0;
}