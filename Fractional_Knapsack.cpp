#include<bits/stdc++.h>
#define MOD 1000000007
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);

#define pb push_back
#define mp make_pair

#define MAX 100005

typedef long long ll;
typedef long double ld;

const ll inf=1000000000;

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
   return a.first *b.second > a.second *b.first;
}


int main(){
    int t; cin>>t;
    cout<<fixed<<setprecision(2);
    while(t--){
        int n,W; cin>>n>>W;


        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i].first>>arr[i].second;

        sort(arr.begin(), arr.end(),comp);

        double ans=0;
        for(int i=0;i<n;i++){
            int x= min(W,arr[i].second);
            ans+= (arr[i].first *x)/arr[i].second;
            W=W-x;
            if(W==0)
                break;

        }
       cout<<ans<<"\n";
    }

  return 0;
}