#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void multiply(int* arr, int num, int &n)
{
	int rem=0;
	for(int i=0;i<=n;i++)
	{
		int product= num* arr[i] + rem;
		arr[i]= product%10;
		rem=product/10;
	}

	while(rem!=0)
	{
		arr[++n]= rem%10;
		rem=rem/10; 
	}

}


void factorial(int *arr,int num, int &n)
{

	arr[0]=1;

	for(int i=2;i<=num;i++)
	{
		multiply(arr,i,n);
	}

	for(int i=n;i>=0;i--)
	{
		cout<<arr[i];
	}
	cout<<endl;
}


int main()
{

	int t; cin>>t;
	while(t--)
	{

		int num; 
		cin>>num;
		int arr[100000]={0};
		int n=0;
		factorial(arr,num,n);

	}

}