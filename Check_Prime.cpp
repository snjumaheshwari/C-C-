#include<iostream>
#include<bits/stdc++.h>

#define ll long long
#define INF 1000000000
using namespace std;

bool isprime(ll n)
{
	if(n==1)
		return false;

	if(n==2)
		return true;

	if(n%2==0)
		return false;

	for(ll i=3;i*i<=n;i++)
	{
		if(n%i==0)
			return false;

	}
	return true;

}

int main()
{

	ll n;
	cin>>n;

	cout<<isprime(n);
}