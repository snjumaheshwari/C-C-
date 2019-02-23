#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll lpf(ll n)
{
	ll ans= 1;
	for(ll i=2 ;i*i <= n;i++)
	{
		if(n%i==0)
		{
			 ans =i;
			 while(n%i==0)
			 	n=n/i;
		}
	}
	if(n>1 )
		ans= max(ans,n);

return ans;

}


int main()
{
	ll n,item;
	cin>>n;

	cin>>item;
	ll ans=item;
	n--;

	while(n--)
	{
		cin>>item;
		ans= __gcd( ans,item);

	}

	cout<<lpf(ans)<<endl;

	return 0;
}