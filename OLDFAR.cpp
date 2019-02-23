#include<bits/stdc++.h>
using namespace std;

int main()
{

int test; cin>>test;
while(test--)
{

	int N,M; cin>>N>>M;

	int sum_row[N];
	int Board[N][M]={0};
	for(int i=0;i<N;i++){
		int sum=0;
		for(int j=0;j<M;j++){
			cin>>Board[i][j];
			sum+= Board[i][j];
		}
		sum_row[i]=sum;
	}

	int maxi=0;
	
	for(int i=0;i<N;i++)
	{

		for(int j=i+1;j<N;j++)
		{
			int ans= sum_row[i]+sum_row[j];
			for(int k=i+1; k<j; k++)
			{
				ans+= Board[k][0];
			}
			maxi= max(ans,maxi);

		}
	}
	cout<<maxi<<endl;

}



}