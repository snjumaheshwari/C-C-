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

int partition(int *arr, int start, int end)
{
	
	int j=start-1;
	int pos=end;

	int item=arr[pos];

	for(int i=start;i<end;i++)
	{

		if(arr[i]<item)
		{
			j++;
			swap(arr[i],arr[j]);
		}
	}
	j++;
	swap(arr[j], arr[pos]);
	return j;

}

void quicksort(int* arr,int start, int end)
{
	if(start>=end)
		return ;

	int pos=partition(arr, start, end);
	quicksort(arr, start, pos-1);
	quicksort(arr,pos+1,end);

}
int main()
{
	DONE;

	int n;cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];
	
	shuffle(a,n);

	quicksort(a,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}