#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n; 
		string s; cin>>s;

		int moves[2]={0,0};
		string players[2]={"Dee","Dum"};


	
		for(int i=0;i<n;i++){
			string w; cin>>w;
			int len= w.length();
			int count=0;
			char first= w[0];
			char last= w[len-1];
			if(last==first)
				moves[first-'0']++;
		}
		if(s==players[0]){
			//cout<<"zero case\n";
			if(moves[0]>moves[1])
				cout<<players[1]<<"\n";
			else
				cout<<players[0]<<"\n";
		}
		else{
			//cout<<"one case\n";
			if(moves[1] > moves[0]){
				cout<<players[0]<<"\n";
			}
			else{
				cout<<players[1]<<"\n";
			}
		}
	}



	return 0;
}