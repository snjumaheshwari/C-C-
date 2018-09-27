#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;


ll convert(string s,int n)
{
	if(n==0)
		return 0 ;

	return convert(s,n-1)*10 + s[n-1]-'0';
}
int main()
{
	MeTime;
	string s;
	cin>>s;

	ll ans=convert(s,s.length());
	cout<<ans;
	return 0;
}