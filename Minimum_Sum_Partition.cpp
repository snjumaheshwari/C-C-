#include<bits/stdc++.h>
#define ll long long
using namespace std;


int min_sum_partition(int *arr,int i,int n, int s){

	if(i==n){
		return 0;
	}
	
	int sum1=min_sum_partition(arr,i+1,n,s);
	int sum2=arr[i]+min_sum_partition(arr,i+1,n,s-arr[i]);
	return min(abs(s-2*sum1),abs(s-2*sum2));
}

int main(){

	int t; cin>>t;
	
	while(t--){
		int n; cin>>n;
		int a[n];
		int s=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			s+=a[i];
		}
		cout<<min_sum_partition(a,0,n,s)<<endl;
	}
}