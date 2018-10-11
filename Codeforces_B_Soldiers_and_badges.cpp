#include<iostream>
#include<bits/stdc++.h>

#define ll long long
#define INF 1000000000
using namespace std;

int main()
{

	ll n;
	cin>>n;

	ll a[n];


	for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}

	sort(a,a+n);

	ll ans=0;
	ll prev=0;
	for(int i=0;i<n;i++)
	{

		ll x=max(a[i], prev+1);
		ans+= x-a[i];
		prev=x;

	}
		
	cout<<ans;

}