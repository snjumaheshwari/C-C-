#include<iostream>
#define ll long long
using namespace  std;


ll max_sub_sum(ll *a,int n,int i, ll ans, ll s){
	if(i==n){
		return ans ;
	}

	s+=a[i];
	ans=max(ans,s);

	if(s<0){
		return max_sub_sum(a,n,i+1,ans,0);
	}
	else{
		return max_sub_sum(a,n,i+1,ans,s);
	}
}

ll max_partion_sum(ll *a,int s,int e){
	ll left_sum=0;
	ll right_sum=0;

	int mid=(s+e)/2;

	ll sum=0;
	for(int i=mid;i>=0;i--){
		sum+=a[i];
		left_sum= max(left_sum,sum);
		if(sum<0){
			break;
		}
	}

	sum=0;
	for(int i=mid+1;i<=e;i++){
		sum+=a[i];
		right_sum= max(right_sum,sum);
		if(sum<0){
			break;
		}
	}
	return left_sum+right_sum;
}
ll max_sub_sum_divide_and_conq(ll *a,int s,int e){

	if(s>e)
		return 0;

	int mid=(s+e)/2;

	return max(max_sub_sum_divide_and_conq(a,s,mid-1),
	max(max_sub_sum_divide_and_conq(a,mid+1,e),
	max_partion_sum(a,s,e)));


}


int main()
{

	int t; cin>>t;

	while(t--)
	{
		int n;cin>>n;
		ll a[n];
		for(int i=0;i<n;i++){
			cin>> a[i];
		}

		//cout<<max_sub_sum(a , n, 0,0,0)<<endl;
		cout<<max_sub_sum_divide_and_conq(a,0,n-1)<<endl;


	}


}