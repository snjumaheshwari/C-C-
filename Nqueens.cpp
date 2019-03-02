#include<bits/stdc++.h>
using namespace std;

int n;
int Done;
int ans=0;

int Board[10][10];
void printBoard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void nQueen(int rowmask=0,int ld=0,int rd=0,int row=0){

    if(rowmask==Done){
        ans++;
        printBoard();
        return ;
    }

    int safe= Done & (~(rowmask| ld | rd));

    while(safe){
        int p= safe &(-safe);
        int c= log2(p);
        Board[row][c]=1;
        nQueen(rowmask |p , (ld|p)<<1, (rd|p)>>1,row+1);
        safe=safe-p;
        Board[row][c]=0;
    }

}



int main(){

    cin>>n;
    Done= (1<<n )-1;

    nQueen();
    cout<<ans<<" ";
}
