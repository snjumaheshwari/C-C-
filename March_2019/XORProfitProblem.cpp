#include<bits/stdc++.h>

using namespace std;

int main(){
    int l,r; cin>>l>>r;

    int x= l ^ r;

    int p=0;
    while(x){
        x=x>>1;
        p++;
    }
    cout<<(1<<p)-1;

    return 0;
}
