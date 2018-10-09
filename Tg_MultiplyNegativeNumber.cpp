#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;

int main()
{
	DONE;

	int n;
	cin>>n;

	int arr[n];
	int b[n];

	bool count=false;

	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	ll ans=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			count=true;
			ans*=arr[i];
		}
	}

	if(!count)
		ans=0;
	cout<<ans<<"\n";
	
	return 0;
}