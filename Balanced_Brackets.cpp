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
	FAST; 
    READ;WRITE;

    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    stack<int> s;
    s.push(0);

    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i] >0){
            s.push(arr[i]);
        }
        else if(s.top()+ arr[i]==0){
            cnt+=2;
            s.pop();
        }
        else{
            ans= max(ans,cnt);
            cnt=0;
            s.push(0);
        }
    }
    ans= max(ans,cnt);
    cout<<ans<<"\n";
return 0;
}
