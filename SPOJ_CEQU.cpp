#include<iostream>
#define ll long long
#include<bits/stdc++.h>
#define Done ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);

}

int main()
{
	ll t;
	cin>>t;

	 t=1;
	for(ll i=1;i<=t;i++)
	{
		ll a,b,c; 
		cin>>a>>b>>c;

		ll g= gcd(a,b);
		//cout<< " gcd "<<g<<endl;
		if(c%g==0)
		{
		
			//cout<<"Case "<<i<<": "<<"Yes"<<endl;
			cout<<"Yes";
		}
		else
		{
			//cout<<"Case "<<i<<": "<<"No"<<endl;
			cout<<"No";
		}
	}

	return 0;
}