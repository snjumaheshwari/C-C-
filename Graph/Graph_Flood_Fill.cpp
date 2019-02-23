#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;
using namespace std;


int R, C;
char input[50][50];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void floodfil(int i,int j,char toFill,char toReplace){

    // Base Case

    if(i==0 or j==0 or i>R or j>C){
        return ;
    }

    if(input[i][j]!=toReplace){
        return;
    }
    input[i][j]= toFill;

    for(int d=0;d<4;d++){
        floodfil(i+dx[d], j+dy[d], toFill, toReplace);
    }
}

void print(){
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cout<<input[i][j];
        }
        cout<<"\n";
    }
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
        freopen("in1.txt","r",stdin);
        freopen("out.txt","w",stdout);
   	#endif

	cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>input[i][j];
        }
    }

    floodfil(10,10,'R','.');
    print();

    return 0;
}
