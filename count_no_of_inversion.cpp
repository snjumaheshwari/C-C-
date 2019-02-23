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


bool comp(pair<int,int> a,pair<int,int> b){

	if(a.second <b.second)
		return true;
	if(a.second ==b.second){
		return a.first < a.second;
	}
	else
		return false;

}

int main(){
	int t; cin>>t;

	while(t--){
		int n; cin>>n;
		
		vector<pair<int,int>> a(n);

		for(int i=0;i<n;i++){
			cin>>a[i].first;
		}
		for(int i=0;i<n;i++){
			cin>>a[i].second;
		}
		sort(a.begin(),a.end(),comp);
		

		int count=1;
		int end= a[0].second;

		for(int i=1;i<n;i++){
			if(a[i].first >= end){
				count++;
				end=a[i].second;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
