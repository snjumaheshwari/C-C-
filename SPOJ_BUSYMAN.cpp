#include<bits/stdc++.h>
#define ll long long
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;


bool comp(pair<ll,ll> p1, pair<ll,ll>p2){
	return (p1.second< p2.second) ;
}
int main()
{
	Done;
	int t; cin>>t;
	
	pair<ll,ll> p;
	while(t--)
	{
		
		ll n; cin>>n;
		ll x,y;
		vector<pair<ll,ll> >arr(n);
		
		for(ll i=0;i<n;i++)
		{
			cin>>p.second>>p.first;
			arr[i]=p;
		}

		sort(arr.begin(),arr.end());
		/*
		for(int i=0;i<n;i++){
			cout<<arr[i].first<< " "<<arr[i].second<<endl;
		}
		*/

		ll count=1;
		ll pre= arr[0].first;
		for(ll i=1;i<n;i++)
		{
			if(arr[i].second>=pre)
			{
				//cout<<"activity should be selevted ";
				count++;
				pre=arr[i].first;
			}
		}
		cout<<count<<endl;

	}

	return 0;
}