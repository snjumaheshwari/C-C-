#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


int main()
{

	ll test; cin>>test;
	while(test--)
	{
		ll num ; cin>>num;
		ll m=num;

		int count_bits=0;
		while(m!=0)
		{
			n=n>>1;
			count_bits++;
		}

		
		ll n=count_bits-1;
		ll ans= (n-1)*(pow(2,n)-1);

		num=num- (pow(2,count_bits-1));

		int count=0;

		ll y=1;
		int i=1;
		while(y<=num)
		{
			ans+=y;
			y=y*2;
			i++;
		}
		ans+= i* pow(2,n);

	}
	
	return 0;
}