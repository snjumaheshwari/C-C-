#include <bits/stdc++.h>
typedef long long ll;
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


using namespace std;

int main()
{
	DONE

	ll t; cin>>t;
	
	while(t--)
	{
		ll n; cin>>n;

		ll ans=0;

		while(n!=0)
		{
			n=n/5;
			ans+=n;
		}
		cout<<ans<<endl;
	}
	return 0;
}