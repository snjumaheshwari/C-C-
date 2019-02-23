
#include<bits/stdc++.h>
#define ll long long
#define MOD 
#define ASDFG ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


ll dec_to_binary(string s)
{
	ll num=0;

	int n=s.length();

	int p=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]-'0')
		{
			num+= pow(2,p);
		}
		p++;

	}

	return num;
}

int main()
{
	ASDFG;
	ll n, q; cin>>n>>q;
	string s;

	int arr[n];

	for(ll i=0;i<n;i++)
	{
		cin>>s;
		ll num= dec_to_binary(s);
		arr[i]=num;
	}	


	while(q--)
	{
		ll l ,r;
		string x;
		cin>> l>> r;
		l--;
		r--;


		cin>>x;
		ll num= dec_to_binary(x);

		ll max_=num ^ arr[l];
		ll ma= l;

		for(int i=l+1;i<=r;i++)
		{
			if((num ^ arr[i] ) >max_)
			{
				max_ = num ^ arr[i];
				ma= i;
			}

		}
		cout<<ma+1<<"\n";



	}

}

