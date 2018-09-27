#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;

// check whteher the arrayy is sorted or not in ascending order..
bool isSorted(int *arr, int n)
{
	if(n==1)
		return true;

	if(arr[0] < arr[1] && isSorted(arr+1,n-1))
		return true;

	return false;
}
bool mysorted(int arr[], int n)
{
	if(n==1)
		return true;
	if(arr[n-1]> arr[n-2] )
		return mysorted(arr,n-1);
	return false; 
}
int main()
{
	int a[]={1,2,3,5,7};
	int n=5;

	cout<<isSorted(a,n);
	cout<<mysorted(a,n);
	return 0;
}