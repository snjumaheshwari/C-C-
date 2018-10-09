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

	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int largest=arr[0]; 
	int frst=0;
	int second=0;
	int sec=-1;


	for(int i=1;i<n;i++)
	{
		if(arr[i]>=largest)
		{
			second=largest;
			sec=frst;

			largest=arr[i];
			frst=i;
		}
		else if(arr[i]>second)
		{
			second=arr[i];
			sec=i;
		}
	}

	int b[n];
	b[0]=largest;
	b[1]=second;

	int j=2;

	for(int i=0;i<n;i++)
	{
		if(i ==frst || i==sec )
			continue;
		b[j]=arr[i];
		j++;
	}


	for(int i=0;i<n;i++)
		cout<<b[i]<<" ";

	return 0;
}