#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;

using namespace std;


int cnt=0;

bitset<100> a[10];

map<int,vector<int>> m; // T-shirt to person mapping
int n;

ll fun(int mask,int tid){
    if(mask== ((1<<n) -1)){
        return 1;
    }
    if(tid==101){
        return 0;
    }

    ll ans= fun(mask,tid+1);

    for(int p: m[tid]){
        if(mask &&( 1<<p) ==1){
            // mask already have p-th bit set
            // => p-th person already have t-shirt
            continue;
        }
        else{
             ans= ( ans+ fun(mask | (1<<p) , tid+1) ) %MOD;
        }
    }

        return ans;
}

int main(){

        int t; cin>>t;
        while(t--){
            string s;
            cin.get();
            for(int i=0;i<n;i++){
                getline(cin,s);
                stringstream snju (s);
                string temp;

                while(snju >> temp){
                    m[stoi(temp)].pb(i);
                }
            }
             cout<<fun(0,1);


        }



}
