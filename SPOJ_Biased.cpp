#include<bits/stdc++.h>
#define ll long long
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;


int main()
{
	Done;
	int t; cin>>t;
	while(t--)
	{
		
		ll n; cin>>n;
		vector<ll> arr(n+1);
		vector<ll> freq(n+1);

		string s;
		for(ll i=1;i<=n;i++)
		{
			cin>>s>>arr[i];
			freq[arr[i]]++;
		}
		
		
		

		ll ans=0;

		ll pos=1;
		for(ll j=1;j<=n;j++)
		{
			while(freq[j])
			{
				freq[j]--;
				ans+=abs(pos-j);
				pos++;
			}

		}


		cout<<ans<<endl;

	}

	return 0;
}