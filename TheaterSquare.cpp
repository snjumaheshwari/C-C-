#include<bits/stdc++.h>
#define ll double
using namespace std;

int main()
{
	ll n,m,a;
	cin>>n>>m>>a;
	
	ll x=ceil(n/a);
	ll y=ceil(m/a);
	
	cout<<x*y;
	return 0; 
	
}
