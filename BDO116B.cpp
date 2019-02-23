#include<bits/stdc++.h>
#define ll long long
#define MAX 9223372036854775807
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll fun( ll n , ll x)
{
	//cout<< " calling fun "<< n << " " << x<<endl;
	ll ans=0;
	while(n >1)
	{
		ans += n/x;
		n= n/x;
	}
	return ans;
}

int main()
{

	Done;

	ll t; cin>> t;
	for(ll j=1 ;j<=t;j++)
	{

		ll n,k ; cin>>n>>k;
		ll ans=MAX;


		// find all the prime factors of k with their powers 
		// k = p1 ^n1  * p2^ n2......
		for(ll i=2;i*i <= k ;i++)
		{

			ll ni=0;

			while( k%i==0)
			{
				ni++;
				k= k/i;
			}
			if( ni!=0)
				ans = min(ans, fun ( n,i) / ni);

		}
		if( k!=1 )
		{
			ans = min(ans,fun(n,k));
		}



		//ans is calculate min( fun(n,pi) / ni)


		cout<<ans<<"\n";
	}
	
	return 0;
}