#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = (int) 1e9;

int main(){
	int t; cin>>t;

	while(t--){
		int n; cin>>n;
		ll a[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		ll m[n];
		ll M[n];
		ll ans=-inf;


		ll s=0;
		ll maximum=-inf;

		for(int i=0;i<n;i++){
			s+=a[i];
			maximum=max(maximum,s);
			if(s<0){
				s=0;
			}
			M[i]=maximum;
		}

		s=0;
		ll minimum= inf;
		for(int i=0;i<n;i++){
			s+=a[i];
			minimum=min(minimum,s);
			if(s>0){
				s=0;
			}
			m[i]=minimum;
		}


		maximum=-inf;
		s=0;
		for(int i=n-1;i>0;i--){
			s+=a[i];
			maximum=max(maximum,s);
			if(s<0){
				s=0;
			}
			ans=max(ans,abs(maximum-m[i-1]));
		}

		minimum=inf;
		s=0;
		for(int i=n-1;i>0;i--){
			s+=a[i];
			minimum=min(minimum,s);
			if(s>0)
				s=0;
			ans=max(ans,abs(minimum- M[i-1]));
		}

	cout<<ans<<endl;

	}




}