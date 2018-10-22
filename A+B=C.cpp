#include<iostream>
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL); 
using namespace std;
#define ll long long

int set_bit(ll n)
{

	int count=0;
	while(n>0)
	{
		count++;
		n= n& (n-1);
	}
	return count;
}

int main()
{
	Done
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,c;
		cin>>a>>b>>c;

		int x=set_bit(a);
		int y=set_bit(b);
		ll ans=0;

		for(ll i=1;i<c;i++)
		{
			if(set_bit(i)==x)
			{
				if(set_bit(c-i)==y)
					ans++;
			}
		}
		cout<<ans<<"\n";

	}

}