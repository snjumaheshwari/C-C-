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
		int x;
		map<int,int>m;

		for(int i=0;i<n;i++){
			cin>>x;
			m[x]++;
		}

		for(int i=0;i<n;i++){
			cin>>x;
			m[x]--;
		}
		bool flag=true;
		for(auto i: m){
			int key=i.first;
			if(m[key]){
				cout<<0<<endl;
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<1<<endl;





	}
	return 0;
}
