#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


void shuffle(int *arr, int n)
{
	int start=0;
	int end=n-1;

	for(int i=end;i>0;i--)
	{
		int j=rand()%(i+1);
		swap(arr[i],arr[j]);

	}
}

int main()
{
	DONE;

	int n;cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	shuffle(a,n);
	
		for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}