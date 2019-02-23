#include<bits/stdc++.h>
using namespace std;


int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};

int Board[1005][1005];
int main(){
	int x,y;
	int t; cin>>t;
	while(t--){
		memset(Board,0,sizeof(Board));
		int n,m; cin>>n>>m;

		set<int> row;
		set<int> col;
		set<int> ld;
		set<int> rd;

		map<pair<int,int>,bool> Q;
		while(m--){
			cin>>x>>y;
			x++;
			y++; 
			Board[x][y]=-1;
			row.insert(x);
			col.insert(y);
			ld.insert(x+y);
			rd.insert(x-y);
		}

		for(int i=2;i<=n+1;i++){
			for(int j=2;j<=n+1;j++){
				
				if(row.count(i) or col.count(j) or ld.count(i+j) or rd.count(i-j)){
					continue;
				}
				else{
					int cnt=0;
					for(int k=0;k<8;k++){
						if(Board[i+dx[k]][j+dy[k]]==-1){
							cnt++;
						}
					}
					Board[i][j]=cnt;
				}
			}
		}

		int ans=0;
		for(int i=2;i<=n+1;i++){
			for(int j=2;j<=n+1;j++){
				if(Board[i][j]>1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}


}