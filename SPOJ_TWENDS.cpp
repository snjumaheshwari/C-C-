#include<iostream>
#define ll long long
using namespace std;


ll solve_dp(int arr[], int n)
{
	ll ans=0;


	return ans;
}

ll solve_greddy(int arr[],int n)
{
	ll ans=0;

	return ans;
}

int arr[1001];
int main()
{

	ll t=0;
	while(1){
		t++;
		int n;
		cin>>n;
		
		if(n==0)
			break;

		for(int i=0;i<n;i++)
			cin>>arr[i];

		ll ans1= solve_dp(arr,n);
		ll ans2= solve_greddy(arr,n);
		cout<<"In game "<<t<<", the greedy strategy might lose by as many as "<<ans1-ans2<<" points."<<endl;

	}
		return 0;

}