#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	// let's do it..


	ll ans=0;
	ll j=0;

	while(true){
		int count=0;
		bool flag=true;
		for(int i=0;i<n;i++){

			if(a[i]!=0)
				flag=false;
			count+= (a[i]&1);

			a[i]=a[i]>>1;
		}
		if(count >=1)
			{
			//	cout<<" count is "<<count<<" factor is "<<(1<<j); 
				ans+= ( (count*(count-1))/2 ) * (1<<j);
			//	cout<<" ans is "<<ans<<endl;
			}
		j++;
		if(flag)
			break;
	}
	cout<<ans<<endl;
	return 0;
}