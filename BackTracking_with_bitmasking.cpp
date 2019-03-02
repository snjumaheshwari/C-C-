#include<bits/stdc++.h>
using namespace std;

// nQueen Problem
int Board[100][100]={0};
int cnt=0;int n; int Done;

void printBoard(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<Board[i][j]<<" ";
		}
		cout<<endl;
	}

}

void nQueen(int rowmask=0,int ld=0, int rd=0, int row=0){
	if(rowmask == Done){
		cnt++;
		printBoard();
		cout<<endl;
		return ;
	}
	int safe= Done & (~(rowmask |ld| rd));

	while(safe){
		int p= safe &(-safe);
		int col= int(log2(p));
		Board[row][col]=1;
		safe=safe-p;
		nQueen(rowmask |p ,(ld|p)<<1 , (rd|p)>>1,row+1);
		Board[row][col]=0;
	}
}


int main(){
	cin>>n;
	Done = (1<<n)-1;
	nQueen(0,0,0);
	cout<<cnt<<endl;

	return 0;
}