/*

Pending ..

*/

#include<bits/stdc++.h>
using namespace std;

int A[1026][1026];
int B[1026][1026];

bool fun(int n){

	map<int,int> m1;
	map<int,int> m2;
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			m1[A[i][j]]++;
			m2[B[i][j]]++;
			if(A[i][j]!=B[i][j]){
				flag=false;
			}
		}
	}
	if(flag)
		return true;

	for(auto i: m1){
		if(i.second !=0){
			return false;
		}
	}


}

int main(){
	int t; cin>>t;

	while(t--){
		int n; cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>A[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>B[i][j];
			}
		}
		if(fun(n)){
			cout<<"Yes\n";
		}
		else{
			cout<<"False\n";
		}
	}

}