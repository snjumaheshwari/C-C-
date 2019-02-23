#include<bits/stdc++.h>
#define ll long long
using namespace  std;

void pair_of_roses(int *a,int n, int m){

	sort(a,a+n);

	int left_ans=-1;
	int right_ans=-1;
	for(int i=0,j=n-1;i<j;){
		if(a[i]+a[j]== m){

			left_ans=i;
			right_ans=j;
			i++;
			j++;
		}
		else if(a[i]+a[j]< m){
			i++;
		}
		else{
			j--;
		}
	}

	cout<<"Deepak should buy roses whose prices are "<<a[left_ans]<<" and "<<a[right_ans]<<".\n";
}

int main()
{

	int t; cin>>t;

	while(t--)
	{
		int n;cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>> a[i];
		}

		int m; cin>>m;
		pair_of_roses(a,n,m);

	}


}