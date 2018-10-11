#include<iostream>
#define ll long long
using namespace std;

int main()
{

	ll n;
	cin>>n;

	ll a[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}

	ll temp=0;
	for(ll i=0;i<n;i++)
	{
		temp+=a[i];
		if(2* temp >= sum){
			cout<<i+1;
			break;
		}
	}

}