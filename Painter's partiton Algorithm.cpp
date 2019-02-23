#include<iostream>
using namespace std;

int main(){

	int t; cin>>t;

	while(t--){
		int k,n; cin>>k>>n;
		int a[n];
		int s=0,m=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			s+=a[i];
			m=max(m,a[i]);
		}

		int min_ans=m;
		int max_ans=s;
	//	cout<<min_ans<< " "<<max_ans<<" ";
		while(min_ans<max_ans){
	//		cout<<min_ans<< " "<<max_ans<<" ";
			int mid_ans=(min_ans+max_ans)/2;

			int count=0,s=0;
			for(int i=0;i<n;i++){
				s+=a[i];
				if(s==mid_ans){
					s=0;
					count++;
				}
				if(s>mid_ans){
					count++;
					s=a[i];
				}
			}
			if(s!=0){
				count++;
			}
			if(count <= k){
				max_ans=mid_ans;
			}
			else{
				min_ans= mid_ans+1;
			}

		}
		cout<<min_ans<<endl;

	}


}