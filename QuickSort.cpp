#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


/*
	Quicksort :-
		- Divide and conquer sorting algo.
		- divides about a element -- pivot element.
		- average case O(N logN ) time
		- In place sorting algorithm O(1) space

*/


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
	
	quicksort(a,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}