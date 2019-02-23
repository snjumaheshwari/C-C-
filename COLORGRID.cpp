#include<iostream>
using namespace std;


int main()
{

	int t; cin>>t;
	while(t--)
	{

		int n,m; cin>>n>>m;

		int a[n][m];

		char x;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{	

				cin>>x;
				if(x=='#')
					a[i][j]=1;
				else
					a[i][j]=0;
			}
		}

		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}*/

		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<m-1;j++)
			{
				//cout<<" executing for i,j"<<i<<" "<<j<<endl;
				if(a[i][j]== 1 || a[i+1][j]==1 || a[i][j+1]==1 || a[i+1][j+1])
					continue;
				else{
					a[i][j]=2;
					a[i+1][j]=2;
					a[i][j+1]=2;
					a[i+1][j+1]=2;
				}
			}
		}

		bool flag=true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]==0)
					{
						flag=false;
						break;
					}
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";


	}
	return 0;


}