#include<bits/stdc++.h>
using namespace std;


int main(){

	int t; cin>>t;
	while(t--){
		string s; cin>>s;

		int n=s.length();

		map<char,int> m;

		int start=1;
		int ans=1;
		for(int i=1;i<=n;i++){
			if(m[s[i-1]] >=start){
				start=(m[s[i-1]])+1;
			}
			ans=max(ans,i-start+1);
			m[s[i-1]]=i;
		}
		cout<<ans<<endl;

	}


	return 0;

}