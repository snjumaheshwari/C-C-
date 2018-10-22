#include<iostream>
#define ll long long
using namespace std;

int N,M;
int Board[201][201];
int answer[201];

int dp[201][201][201][2];

int main()
{
	cin>>N>>M;

	string temp;
	
	for(int i=0;i<=min(N,M);i++)
	{
		answer[i]= N*M;

	}
	answer[0]=0;
	answer[1]=0;

	for(int i=0;i<N;i++)
	{
		cin>>temp;
		for(int j=0;j<M;j++)
		{

			Board[i][j]=temp[j]-'0';
		}
	}


	

	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			dp[i][j][0][0]=0;
			dp[i][j][0][1]=0;
			dp[i][j][1][0]= Board[i][j];
			dp[i][j][1][1]= 1-Board[i][j];

		}
	}




	//cout<< " printing dp table  "<<endl;	

	for(int x=2;x<min(N,M)+1 ;x++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				//cout<< " checking for i, j : " << i << " "<<j <<endl; 
				int maxsize= min(N-i,M-j)+1 ;
				if(maxsize >x){
					dp[i][j][x][0]= dp[i][j+1][x-1][1] + dp[i+1][j][x-1][1] - dp[i+1][j+1][x-2][0] + dp[i][j][1][0] + dp[i + x-1][j+ x-1][1][0];
					dp[i][j][x][1]= dp[ i][j+1][x-1][0] + dp[i+1][j][x-1][0] - dp[i+1][j+1][x-2][1] + dp[i][j][1][1] + dp [i+ x-1][j+x-1][1][1];
					//cout<< " x : "<<x  << " values : "<< dp[i][j][x][0] << " "<< dp[i][j][x][1] << " "<<endl;
					int m= min(dp[i][j][x][0], dp[i][j][x][1]);
					answer[x]= min(m,answer[x]);
					}
			}

		}

	}


	


ll q,Q; cin>>Q; //Q=int(input())

//Queries=list(map(int,input().split()))
for(ll i=0;i<Q;i++)
{
	cin>> q;
	for(int j=min(N,M); j>=0;j=j-1)
	{
		if(q>= answer[j]){
			cout<<j<<endl;
			break;
		}
	}
}


	return 0;

}

