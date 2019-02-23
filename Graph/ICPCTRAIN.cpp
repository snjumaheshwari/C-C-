#include<bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2){

    if(p1.first.first < p2.first.first){
        return true;
    }
    else if( p1.first.first > p2.first.first){
       return false;
    }
    return p1.second > p2.second;

}

int main(){
    int t; cin>>t;
    int a,b,c;
    while(t--){
        int n,m; cin>>n>>m;
        vector<pair<pair<int,int> ,int >> v;

        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            pair<pair<int,int>,int> p;
            p.second= c;
            p.first.first=a;
            p.first.second=b;
            v.push_back(p);
        }
        sort(v.begin(), v.end(),comp);

        for(auto p: v){
            cout<<p.first.first <<" "<<p.first.second<<" "<<p.second<<"\n";
        }
    }


    int d=1;



return 0;
}
