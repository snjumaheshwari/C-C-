#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;

using namespace std;

const int MAX= int(1e6)+5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
   	#endif
     int t; cin>>t;
     while(t--){

     	int n; cin>>n; 
     	int arr[n+1];
     	arr[0]=0;
     	for(int i=1;i<=n;i++){
     		cin>>arr[i];
     	}

     	map<int,bool> m;
     	m[0]=true;
     	for(int i=1;i<=n;i++){
     		vector<int> ans;
     		for(auto p : m){
     			ans.pb(p.first+ arr[i]);
     		}
     		for (auto j: ans){
     			m[j]=true;
     		}
      	}

      	int cnt=0;
     	 for(auto i: m){
      		if(m[i.first]){
      			cnt++;
      		}
      	}
      	cout<<cnt<<"\n";
     }
return 0;

}