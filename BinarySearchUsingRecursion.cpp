#include <bits/stdc++.h>
#define ll long long
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int binarySearch(int*arr, int start,int end,int item)
{
	if(start> end)
		return -1;
	int mid=(start+end)/2;
	if(arr[mid]== item)
		return mid;

	if(arr[mid]>item)
		return binarySearch(arr,start,mid-1,item);
	else
		return binarySearch(arr,mid+1,end,item);

}

int main()
{
	MeTime;
	

	return 0;
}