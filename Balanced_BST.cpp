#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	TLE;
	int n; cin>>n;
	string s; cin>>s;

	
	int a[n],sum[n+1];
	sum[0]=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			a[i]=1;
		}
		else{
			a[i]=-1;
		}
		sum[i+1]=sum[i]+a[i];
	}

	bool flag=false;


	if(sum[n]==2){
		multiset<int> m;
		m.insert(10);
		flag=true;
		int count=0;
		for(int i=n;i>0;i--){
			if((*m.begin() >=2) and (a[i-1]==1) and (sum[i]-2 >=0)){
				count++;
			}
		
			if(sum[i]<0)
				flag=false;
			m.insert(sum[i]);
		}
	
		if(flag){
			cout<<count<<endl;
		}
		else{
			cout<<0<<endl;
		}

	}
	else if(sum[n]==-2){
		flag=true;
	
		int count=0;
		for(int i=n;i>0;i--){
			if((a[i-1]==-1) and (sum[i]+2 >=0)){
				count++;
			}
			if(sum[i]+2 <0){
				flag=false;
			}	
		}
		if(flag) cout<<count<<endl;
		else cout<<0<<endl;
	}
	else{
		if(!flag)
			cout<<0<<endl;
	}


}