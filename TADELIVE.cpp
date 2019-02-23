#include<bits/stdc++.h>
#define ll long long
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

const int inf=(int)1e9;

int fun(int k,int i,int j, int n,int x,int y, int *a, int *b){

	if(k==n)
		return 0;

	ll ans1=0;
	ll ans2=0;

	if(i<x) ans1= a[k]+ fun(k+1,i+1,j,n,x,y,a,b);
	if(j<y) ans2= b[k] + fun(k+1,i,j+1,n,x,y,a,b);

	return max(ans1,ans2);
}
int main(){
		int n,x,y; cin>>n>>x>>y;

		int a[n],b[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int j=0;j<n;j++){
			cin>>b[j];
		}

		/* vector<pair<int,int>> diff(n);
		for(int i=0;i<n;i++){
			diff[i].first= abs(a[i]-b[i]);
			diff[i].second=i;
		}

		sort(diff.begin(),diff.end());

		

		int i=0,j=0;
		ll ans=0;
		for(int k=n-1;k>=0;k--){
			if(diff[k].first==0){
				ans+= a[diff[k].second];
			}

			else if(diff[k].first >0){
				int index= diff[k].second;

				if(a[index] > b[index]){
				 	if(i<x){
						i++;
						ans+=a[index];
					}
					else{
						j++;
						ans+=b[index];
					}
				}
				else{
					if(j<y){
						j++;
						ans+=b[index];
					}
					else{
						i++;
						ans+=a[index];
					}
				}

			}
		}


			cout<<ans<<endl;
		*/
		cout<<fun(0,0,0,n,x,y,a,b)<<endl;

	return 0;
}