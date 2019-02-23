#include<bits/stdc++.h>
#define MOD 1000000007
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);

#define pb push_back
#define mp make_pair

#define MAX 100005
using namespace std;
long long arr[MAX+5];
long long BIT[MAX+5];


void update(int index, int val,int n){

    while(index<=n){

        BIT[index]+=val;
        index+= (index &(-index));

    }

}
int query(int index){
    int ans=0;
    while(index>=1){
        ans+=BIT[index];
        index-=(index &(-index));

    }

    return ans;

}

int main(){
    TLE;
    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

    #endif

    int t; cin>>t;

    while(t--){

        int n,u; cin>>n>>u;

       
        memset(BIT,0,sizeof(BIT));

        while(u--){
            int l,r,x; cin>>l>>r>>x;
            l++;
            r++;
            update(l,x,n);
            update(r+1,-x,n);
        }
      
        int q; cin>>q;
        while(q--){
            int x; cin>>x;
            x++;
            cout<<query(x)<<"\n";
        }
        

    }
    return 0;


}
