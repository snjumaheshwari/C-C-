#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair

typedef long double ld;
typedef long long ll;

const ll N = 100005;
const ll mod  = 1000000007;

ll pow2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};

void solve(){
    int t,n,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        multiset<int> v;
        for(int i=0;i<pow2[n];i++){
            cin>>x;
            v.insert(x);
        }

        vector<int> sub;
        vector<int> ans;

        sub.push_back(0);
        v.erase(v.begin());



        for(int i=0;i<n;i++){
            x = *v.begin();
            ans.push_back(x);

            ll len = sub.size();

            for(int j=0;j<len;j++){
                y = sub[j]+x;
                auto it = v.lower_bound(y);
                // cout<<*it<<" ";
                sub.push_back(*it);
                v.erase(it);
            }
            // cout<<endl;
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    FAST

    solve();
}
