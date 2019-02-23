#include<bits/stdc++.h>
#define ll long long
using namespace std;


int fun(string s,int i,int j){
		if(i>j)
			return 0;

	if(s[i]==s[j]){
		return fun(s,i+1,j-1);
	}
	else{
		return min(fun(s,i+1,j),fun(s,i,j-1))+1;
	}
}

int main(){

	int t; cin>>t;
	string s;
	while(t--){
		cin>>s;
		int n=s.length();
		int ans=fun(s,0,n-1);
		cout<<ans<<endl;
	}
}