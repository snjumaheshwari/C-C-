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
    
   // READ;WRITE;

    int t; cin>>t;
    while(t--){
    	int n,x; cin>>n;
    	int N= 1LL<<n;
    	multiset<ll> s1,s2;

    	for(int i=1;i<=N;i++){
    		cin>>x;
    		s1.insert(x);
    	}
    	s1.erase(*s1.begin());

    	s2.insert(0);

    	vector<ll> ans;
   		int i=0;
    	while(i!=n){
    		ll value=*s1.begin();
    		
    		ans.push_back(value);
    		i++;

    		vector<int> temp;

    		for(auto j: s2){
    			ll remove= value+j;
    			s1.erase(s1.find(remove));
    			temp.push_back(remove);
    		}

    		for(auto j: temp){
    			s2.insert(j);
    		}

    	}

    	for(auto i: ans){
    		cout<<i<<" ";
    	}
    	cout<<"\n";

     }


return 0;
}
