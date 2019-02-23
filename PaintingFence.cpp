/*
	Pending

*/

#include<bits/stdc++.h>
using namespace std;

int arr[5005];


int dp[5005][5005];

int fun(int s,int e){
	if(s >e){
		return 0;
	}
	bool flag=true;

	for(int i=s;i<=e;i++){
		if(arr[i]!=0){
			flag=false;
			break;
		}
	}
	if(flag){
		dp[s][e]=0;
		return 0;
	}

	int min=s;

	for(int i=s;i<=e;i++){
		if(arr[i]<arr[min]){
			min=i;
		}
	}
	if(arr[min] >=e-s+1){
		return e-s+1;
	}

	// vertical cut

	int ans2= fun(s,min-1)+fun(min+1,e)+1;

	// horizontal cut
/*	int ans1= arr[min];
	for(int i=s;i<=e;i++){
		arr[i]-=ans1;
	}
	ans1= ans1+fun(s,min-1)+ fun(min+1,e);
	if(ans1<ans2)
		return ans1;
	else{
		return ans2;
	}
	*/
	return ans2;
}

int main(){
	int n; cin>>n;

	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			dp[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	cout<<fun(1,n);

	
}

//10 6 9 7 8 6 8 5 8 6 8 6 7 10