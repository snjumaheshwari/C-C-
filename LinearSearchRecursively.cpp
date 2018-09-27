#include <bits/stdc++.h>
#define ll long long
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int linearSearch(int arr[], int item,int i, int n)
{
	if(i==n)
		return -1;
	if(arr[i]==item)
		return i;
	else
		return linearSearch(arr,item,i+1,n);
}


int main()
{
	MeTime;
	
// given an array .. find index of particular element if not present -1
	int a[]={1,3,2,8,6,0,54,21,98,21};

	int n=sizeof(a)/sizeof(int);
	int item;
	cin>>item;
	int ans=linearSearch(a,item,0,n);
	cout<<ans;

	return 0;
}