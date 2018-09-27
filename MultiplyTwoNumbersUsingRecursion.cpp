#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;

int multiply(int n,int m)
{
	if(m==0)
		return 0;
	if(m==1)
		return n;
	return n+multiply(n,m-1);

}

int main()
{
	MeTime;
	ll n,m;
	cin>>n >>m;

	ll ans=multiply(abs(n),abs(m));

	if((n<0 && m>0 ) || (n>0 || m<0))
		cout<<"-";
	
	cout<<ans;
	
	return 0;
}