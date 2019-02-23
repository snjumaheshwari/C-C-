#include<bits/stdc++.h>
#define ll long long
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

map<int,int> m;

ll spf[1000002]={0};

int main()
{

	//memset(spf,-1,sizeof(spf));
	for(int i=1;i<=1000000;i++)
		spf[i]=i;


	for(int i=2;i<10001;i++)
	{
		for(int j=i*i;j<=1000000;j+=i)
		{
			if(spf[j]==j)
			{
				spf[j]=i;
			}
		}
	}

/*	for(int i=1;i<100000;i++)
		cout<<i<<" "<<spf[i]<<endl;
*/


	int t; cin>> t;
	while(t--)
	{
		m.clear();

		int n; cin>>n;

		int a[n];
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			int num= a[i];

			while(num!=1)
			{
				//cout<<" num is "<<num<< " "<<spf[num]<<" "<<endl;
				m[spf[num]]++;
				num= num/spf[num];
			}

		}

		ll ans=1;
		for(auto i : m)
		{
			ans= ans* (i.second+1);
		}
		cout<<ans<<endl;

	}
	return 0;

}