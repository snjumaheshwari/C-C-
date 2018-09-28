#include <bits/stdc++.h>
#define ll long long
#define MyTime ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main()
{
	MyTime;
	ll n; cin>>n;
	map<ll,ll> m;

	ll a[n];

	for(ll i=0;i<n;i++)
		cin>>a[i];

	ll g=__gcd(a[0],a[1]);

	for(ll i=2;i<n;i++)
		g=__gcd(a[i],g);

	for(ll i=0;i<n;i++)
		a[i]=a[i]/g;

	for(ll i=0;i<n;i++)
	{
		ll num=a[i];
		while(num!=1)
		{
			for(int i=2;i<sqrt(num);i++)
			{
				while(a[i]%i)
				{
					
				}
			}
		}
	}

	return 0;
}