#include<bits/stdc++.h>
using namespace std;


bool Board[10][10];

int dx[]={-1,0,1,1,1,0,-1,-1};
int dy[]={1,1,1,0,-1,-1,-1,0};


void fun(int r,int c,int k){
	Board[r][c]=true;

	if(k==0 or r>8 or c>8 or r<=0 or c<=0 ){
		return;
	}
	bool flag=true;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(!Board[i][j]){
				flag=false;
			}
		}
	}
	if(flag)
		return;
	for(int i=0;i<8;i++){
		fun(r+dx[i],c+dy[i],k-1);
	}
}

void fun2(int r,int c,int k){

	Board[r][c]=true;

}

int main(){
	int t; cin>>t;
	while(t--){
		int r,c,k; cin>>r>>c>>k;
		memset(Board,false,sizeof(Board));
		fun(r,c,k);
		int ans=0;
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(Board[i][j])
					ans+=1;
			}
		}
		cout<<ans<<"\n";

	}


	return 0;
}