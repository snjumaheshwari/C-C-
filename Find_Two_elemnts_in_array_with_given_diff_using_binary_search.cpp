#include<bits/stdc++.h>
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int  binary_search(int a[],int low, int high,int n, int val )
{
	while(low<=high)
	{
		int mid= (low+high)/2;

		if(val== a[mid])
			return mid;
		if(val >a[mid])
			low= mid+1;
		else
			high=mid-1;

	}


	return -1;
}
int main()
{

	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int s; cin>>s;
	sort(a,a+n);
	
	for(int i=0;i<n;i++)
	{
		int index= binary_search(a,0,n-1,n,a[i]-s);
		if(index !=i and index !=-1)
		{
			cout<<a[i]<< " "<<a[index]<<endl;
		}
	}



	return 0;
}