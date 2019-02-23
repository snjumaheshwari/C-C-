#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


const int inf= int(1e9);
const int MOD =int(1e9)+7;

typedef long long ll;

int main(){

    int t; cin>>t;
    while(t--){
        int n,x; cin>>n;
        multiset<int> m;
        for(int i=0;i<n;i++){
            cin>>x;
            m.insert(x);
        }
        m.erase();
        multiset<int> values;
        auto it=m.begin();
        values.insert(*it);

        multiset<int> sum_set;
        sum_set.insert(*it);
        it++;

        while(it!=m.end()){



        }


    }

    return 0;
}
