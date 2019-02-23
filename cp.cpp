#include<bits/stdc++.h>
#define Done ios_base::sync_with_stdio(false)
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];
	int b[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	for(int i=0;i<n;i++)
		cin>>b[i];


	int pre=0,j=0;

	unordered_map<int,int> d;

	for(auto i: b)
	{
		//cout<<" for item "<<i<<endl;
		if(d[i]){
			//cout<<"already occured "<<endl;
			cout<<"0 ";
		}
		else
		{
			while(j<n)
			{
				if(a[j]==i){
					cout<<j+1-pre<<" ";
					pre=j+1;
					break;
				}
				else
					d[a[j]]=1;
				j+=1;
			}
		}

	}



return 0;


}