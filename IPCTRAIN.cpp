#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front
#define READ freopen("in.txt","r",stdin);
#define WRITE freopen("out.txt","w",stdout);
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MOD = int(1e9)+7;
const int MAX = int(1e5)+5;
const ll inf= int(1e18)+1;

using namespace std;

int main(){
	//FAST; 
    
    //READ;WRITE;
    map<int,vector<pair<int,int>>> M;

    int t; cin>>t;
    int x,y,z;

    while(t--){
        int n,m; cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>x>>y>>z;
            M[x].push_back({z,y});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        
        for(int d=1;d<=m;d++){
            for(auto p: M[d]){
            pq.push(p);
            }   

            if(!pq.empty()){
                auto p= pq.top();
                pq.pop();

                 p.second--;
                if(p.second!=0){
                    pq.push(p);
                }
            }
        }
        ll ans=0;
        while(!pq.empty()){
            auto p= pq.top();
            pq.pop();
            ll x= p.first;
            ll y=p.second;

            ans+= (x*y);
        }
        cout<<ans<<"\n";

        M.clear();
    }



return 0;
}
