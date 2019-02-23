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

bool comp(int a, int b){
    return a>b;
}

class Comp{
    public :
    bool operator()(int a, int b){
        return a > b;

    }
};

int main(){
	FAST; 
    READ;WRITE;

    int t; cin>>t;
    while(t--){
        int n,x,y,z;
        cin>>n>>x>>y>>z;

        int arr[n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        
        priority_queue<ll, vector<ll> , Comp> pq;
        int ans;
        int num=0;
        for(int i=1;i<=n;i++){
            ans=0;
            for(int j=i;j<=n;j++){
                ans+=arr[j];
                if(num< z){
                    pq.push(ans);
                    num++;
                }
                else if(pq.top() < ans){
                        pq.pop();
                        pq.push(ans);
                    }
                }
            }
        
        /*
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
        */
        ll ans3= pq.top();

        int k1=z-x+1;
        int k2= z-y+1;

        int cnt=1;
        ll ans1,ans2;
        while(!pq.empty()){    
            pq.pop();
            cnt++;

            //cout<<pq.top()<<" ";
            if(cnt==k1){
              ans1=pq.top();
              break;
            }
            else if(cnt==k2){
                ans2= pq.top();
            }
        }  
        cout<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
    
    }
return 0;
}
