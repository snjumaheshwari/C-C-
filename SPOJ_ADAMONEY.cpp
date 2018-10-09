#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007

using namespace std;

vector<ll> b,c;
int k=5;

// AC

vector<vector<ll> > multiply( vector<vector<ll> >A, vector<vector<ll> > B)
{

	vector<vector<ll> >C(k,vector<ll>(k));

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			for(int x=0;x<k;x++)
			{
				C[i][j]= (C[i][j] + (A[i][x] * B[x][j])%MOD)%MOD;

			}
		}
	}

	return C;
}


vector<vector<ll> > power( vector<vector<ll> > A, ll n)
{
	if(n==1)
		return A;

	if(n&1)
		return multiply(A,power(A,n-1));

	vector<vector<ll> > X= power(A,n/2);

	return multiply(X,X);


}

ll compute(ll n)
{

	if(n<k)
		return b[n];

	vector< vector <ll > > T(k,vector<ll>(k));

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(i<k-1)
			{
				if(i+1==j)
					T[i][j]=1;
				else
					T[i][j]=0;

			}
			else
			{
				T[i][j]=c[j];
			}
		}

	}

/*
	cout<< " Transformation Matrix "<<endl;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
			cout<<T[i][j]<<" ";

		cout<<endl;

	}

	*/

	T=power(T,n);
	/*cout<< " T to the power n "<<endl;

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
			cout<<T[i][j]<<" ";

		cout<<endl;

	}
	*/

	ll result=0;

	for(int i=0;i<k;i++)
	{
		result=(result+ (T[0][i]*b[i])%MOD)%MOD;
	}
	return result %MOD;

}


int main()
{
	DONE
	
	ll num,n;

	int t; cin>>t;

	c.push_back(1);
	c.push_back(5);
	c.push_back(0);
	c.push_back(2);
	c.push_back(1);


	while(t--)
	{

		for(int i=0;i<k;i++){
			cin>>num;
			b.push_back(num);
		}

	cin>>n;

	cout<<compute(n)<<endl;
	b.clear();

	}
	return 0;
}