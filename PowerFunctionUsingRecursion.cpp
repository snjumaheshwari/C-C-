#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;

ll p(ll n , ll p)
{
	if(b==0)
		return 1;
	else
		return a*p(a,b-1);
}

ll power(ll n,ll p)
{
	if(n==0)
		return 0;
	if(p==1)
		return n;
	ll smallPower= power(n,p/2);
	ll ans=smallPower*smallPower;
	if(p&1)
		ans=ans*n;
	return ans;

}

int main()
{
	MeTime;
	ll n,p;
	cin>>n >>p;
	
	cout<<power(n,p);

	return 0;
}