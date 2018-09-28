#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


void bubbleSort(int *a , int n ,int pass=0)
{

	if(pass==n-1)
		return;
	for(int i=0;i<n-1-pass;i++)
	{
		if(a[i] >a[i+1])
			swap(a[i],a[i+1]);
	}
	return  bubbleSort(a,n,pass+1);

}

void bubblesort(int*a , int n)
{
	if(n==1)
		return ;
	for(int j=0;j<n-1;j++)
	{
		if(a[j]>a[j+1])
			swap(a[j], a[j+1]);
	}
	return bubblesort(a,n-1);
}

void bubblesort2(int*a , int n,int j=0)
{
	if(n==1)
		return ;

	if(j==n-1)
		return bubblesort2(a, n-1, 0);

	if(a[j] > a[j+1])
		swap(a[j] ,a[j+1]);
	
	bubblesort2(a,n,j+1);
}
int main()
{
	DONE;
	int a[]={12,11,10,10,9,8,6};
	int n=sizeof(a)/sizeof(int);

	//bubbleSort(a,n);
	//bubblesort(a,n);
	bubblesort2(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	
	return 0;
}