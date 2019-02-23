#include <bits/stdc++.h>
#define ll long long
#define Thikache ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;

int Board[1000][1000]={0};
void PrintBoard(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<Board[i][j]<<" ";

		cout<<endl;
	}
}


int max(int *arr, int n)
{
	if(n==0)
		return -1;
	int ans=arr[0];

	for(auto i: arr)
	{
		if(arr[i]>ans)
			ans=arr[i];
	}
}

int maxknight(int n ,int r=0,int c=0)
{
	PrintBoard(n);
	if(Board[r][c]==0)
		return 0;

	if(r>n || c>n)
		return 0;

	return 1+ max([maxknight(n,r-2,c-1), maxknight(n,r-2,c+1),
				maxknight(n,r-1,c-2), maxknight(n,r-1,c+2),
				maxknight(n,r+1,c-2), maxknight(r+1,c+2),
				maxknight(n,r+2,c-1), maxknight(n,r+2,c+1)],8) ;
}

int main()
{
	Thikache;

	int n;
	cin>>n;

	//int Board[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>Board[i][j];

	cout<<maxknight(n,0,0);

	
	return 0;
}
