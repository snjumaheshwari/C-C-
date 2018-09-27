#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;


ll factorial(ll n)
{
	ll ans=1;
	for(ll i=2;i<=n;i++)
		ans*=i;
	return ans;
}

ll nCr(ll n,ll r)
{
	return (factorial(n))/(factorial(r)* factorial(n-r));
}
int main()
{
	MeTime;
	ll n,r;
	cin>>n >>r;
	
	cout<<nCr(n,r);

	return 0;
}