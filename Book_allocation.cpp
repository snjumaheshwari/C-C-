#include<bits/stdc++.h>
#define MOD 1000000007
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);

#define pb push_back
#define mp make_pair
#define pf push_front
#define MAX 100005

typedef long long ll;
typedef long double ld;

const ll inf=1000000000;

using namespace std;

int main(){
	int t; cin>>t;

	while(t--){
		ll n; cin>>n;
		ll a[n];

		ll s=0;
		ll m=0;
		for(ll i=0;i<n;i++){
			cin>>a[i];
			s+=a[i];
			m=max(m,a[i]);
		}
		ll k; cin>>k;

		if(n<k){
			cout<<"-1\n";
			continue;
		}

		ll max_ans=s;
		ll min_ans=m;

		while(min_ans<max_ans){
			//cout<<min_ans<<" "<<max_ans<<" , ";
			ll mid_ans=(min_ans+max_ans)/2;
			s=0; 
			ll count=0;
			for(ll i=0;i<n;i++){

				s+=a[i];

				if(s==mid_ans){
					s=0;
					count++;
				}
				if(s >mid_ans){
					count++;
					s=a[i];
				}
				//cout<<i<<" "<<s<<" "<<count<<endl;
			}
			//cout<<"count : "<<count<<endl;
			if(s!=0){
				count++;
			}
			if(count > k){
				min_ans=mid_ans+1;
			}
			if(count<=k){
				max_ans=mid_ans;
			}
		}

	cout<<min_ans<<endl;		


	}
	return 0;
}
