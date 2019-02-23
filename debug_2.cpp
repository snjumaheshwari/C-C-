#include<bits/stdc++.h>
#define ll long long
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
using namespace std;
/*

ll brutte_force(ll l, ll r,ll v){

	ll count=0;
	for(int i=l;i<=r;i++){
		if( (i&v) == v){
			cout<<i<<" ,";
			count++;
		}
	}

	return count;
}
*/
ll fun(ll num,ll v){

	if(num< v)
		return 0;

	int num1[100],v1[100];
	for(int i=0;i<100;i++){
		num1[i]=0;
		v1[i]=0;
	}
	int i=0;
	int j=0;
	while(num){

		if(num&1)
			num1[i]=1;
		else
			num1[i]=0;
		num=num>>1;
		i++;
	}
	while(v){
		if(v&1)
			v1[j]=1;
		else
			v1[j]=0;
		j++;
		v=v>>1;
	}

	bool flag=false;
	for(int k=0;k<100;k++){

		if(v1[k]==1 and num1[k]==0){
			num1[k]=1;
			flag=true;
		}
		else if(v1[k]==0 and flag){
			if(num1[k]==0)
				num1[k]=1;
			else{
				num1[k]=0;
				for(int i=0;i<k;i++)
					num1[i]=1;
				flag=false;
			}
		}

	}

	/*for(int i=0;i<64;i++)
		cout<<num1[i]<<" ";
		*/

	ll ans=0;
	
	for(int i=99;i>=0;i--){
		int count=0;
		if(v1[i]==0 and num1[i]==1){
			for(int j=i-1;j>=0;j--){
				if(v1[j]==0){
					count++;
				}
			}
			//if(count!=0)


			//ans+= pow(2,count);
			ans+=1LL<<count;
		}
		if(v1[i]==1 and num1[i]==0){
			cout<<"ERROR phle \n";
		}

	}


	return ans+1;
}

int main(){
	TLE;
	
	//fun(100,1);
	ll t; cin>>t;
	while(t--){
		ll l,r,v; cin>>l>>r>>v;
		ll ans= fun(r,v)-fun(l-1,v);
	//	ll ans2=brutte_force(l,r,v);
	//	cout<<ans<<" "<<ans2<<endl;
		cout<<ans<<endl;
	}
	

}