#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


void merge2(int *a, int start, int end)
{
	int mid=(start+end)/2;

	int i=start;
	int j=mid+1;
	int k=start;

	int temp[1000];

	while(i<=mid && j<=end)
	{
		if(a[i]< a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=end)
	{
		temp[k++]=a[j++];
	}

	for(int i=start;i<=end;i++)
	{
		a[i]=temp[i];
	}


}

void merge(int* arr, int start, int mid , int end)
{
	int n1=mid-start+1;
	int n2=end-mid;

	int L[n1],R[n2];

	for(int i=0;i<n1;i++)
		L[i]=arr[start+i];

	for(int j=0;j<n2;j++)
		R[j]=arr[mid+1+j];

	int i=0,j=0;
	int k=start;

	while(i<n1 && j< n2)
	{
		if(L[i]<=R[j])
			arr[k++]=L[i++];
		else
			arr[k++]=R[j++];
	}

	while(i<n1)
		arr[k++]=L[i++];

	while(j<n2)
		arr[k++]=R[j++];
}

void mergeSort(int *arr,int start, int end)
{
	if(end<=start)
		return ;
	int mid=(end+start)/2;

	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);

	merge(arr,start,mid,end);

}

int main()
{
	DONE;

	int arr[]={ 1,4,2,6,12,54,21,7,8,3};
	int n=sizeof(arr)/sizeof(int);

	mergeSort(arr,0,n-1);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	
	return 0;
}
