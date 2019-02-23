#include<bits/stdc++.h>
using namespace std;

int main()
{

	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
	/*	int ans=k;
		while(ans>=0)
		{
			if(__gcd(ans,n)==1)
				{
					break;
				}
				ans--;
		}
		int x=n % ans;*/
		//cout<<" n should be "<<ans<<endl;

		int y=0;
		for(int i=1;i<=k;i++)
		{
			int rem= n%i;
			if(rem>y){
				y=rem;
				//cout<<"i is "<<i;
			}
		}
		//cout<<x<<" "<<y<<endl;
		cout<<y<<endl;

	}
}