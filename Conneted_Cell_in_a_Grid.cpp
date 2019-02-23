#include<bits/stdc++.h>
using namespace std;


list<int> *adj;

int Board[15][15];
int size[15][15];

pair<int,int> parent[15][15];

int dx[]={0,1,1, 1,0,-1 ,-1,-1};
int dy[]={1,1,0 ,-1,-1,-1 ,0,1};

bool visited[15][15];

int cnt=0;
void dfs(int i,int j){
    visited[i][j]=true;
    cnt++;

    for(int k=0;k<8;k++){
        if(!visited[i+dx[k]][j+dy[k]] && Board[i+dx[k]][j+dy[k]]){
            dfs(i+dx[k],j+dy[k]);
        }
    }
}

int main(){

    memset(Board,0,sizeof(Board));
    memset(visited,false,sizeof(visited));

    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x; cin>>x;
            Board[i][j]=x;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(Board[i][j]==1 && !visited[i][j]){
                dfs(i,j);
                ans=max(ans,cnt);
                cnt=0;
            }
        }
    }
    cout<<ans;
    return 0;
}