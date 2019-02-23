
#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


const int inf= int(1e9);
const int MOD =int(1e9)+7;

typedef long long ll;

int main(){
    string s; cin>>s;
    int k; cin>>k;

    int n=s.length();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
    }

    if(n-k-cnt>=0)
        cout<<n-k-cnt<<endl;
    else
        cout<<"0\n"<<endl;
}


