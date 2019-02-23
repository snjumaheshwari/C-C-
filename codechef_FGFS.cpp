#include<bits/stdc++.h>
#define ll long long
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


struct cust{
	int s;
	int f;
	int p;
};


bool comp(cust &first, cust &second)
{
	if(first.p==second.p)
		return first.f< second.f;
	return (first.p <second.p);

}
int main()
{
Done
	int t ; cin>>t ;
	while(t--)
	{
		int n,k; cin>>n>>k;

		vector<cust> V(n);

		for(auto i=0;i<n;i++)
		{

			cin>>V[i].s>> V[i].f>> V[i].p ;
		}

		sort(V.begin(),V.end(),comp);

		/*for(ll i=1;i<n;i++)
			cout<<V[i][0]<<" "<<V[i][1]<<" "<<V[i][2]<<endl;*/
		

		if(n==0)
		{
			cout<<"0\n";
			continue;
		}
		int count=1;
		int done=V[0].f;

		for(int i=1;i<n;i++)
		{
			if((V[i].p != V[i-1].p) || ( V[i].s >=done))
			{

					count++;
					done= V[i].f;
			}

		
		}
		cout<<count<<endl;

	}

	return 0;
}
