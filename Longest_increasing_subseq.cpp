#include<bits/stdc++.h>
using namespace std;

int main(){

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n],lis[n];

		for(int i=0;i<n;i++){
			cin>>arr[i];
			lis[i]=1;
		}

		int ans=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(arr[j]<arr[i]){
					lis[i]=max(lis[i],lis[j]+1);
				}
			}
			ans=max(ans,lis[i]);
		}


		cout<<ans<<endl;

	}




}