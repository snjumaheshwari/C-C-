#include<bits/stdc++.h>
using namespace std;

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input","r",stdin);
		freopen("output","w",stdout);
	#endif
	int n;
	cin>>n;

	int ans=0;
	int x;

	for(int i=0;i<n;i++)
	{
		cin>>x;
		ans+=x;

	}
	cout<<ans<<endl;

}


