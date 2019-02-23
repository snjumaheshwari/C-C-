#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front

const int MOD = int(1e9)+7;

using namespace std;


vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B, int r,int n,int c){

	vector<vector<ll>>C (r,vector<ll>(c));

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			for(int k=0;k<n;k++){
				C[i][j]= ( C[i][j]+ A[i][k]*B[k][j] )%MOD;
			}
		}
	}
	return C;
}

ll matrix_expo(int n){

	vector<vector<ll>> T(2,vector<ll>(2));
	T[0][0]=0;
	T[0][1]=T[1][1]=T[1][0]=1;


	n=n-1;
	// compute T^ n-1

	vector<vector<ll>> ans(2,vector<ll>(2));
	ans[0][0]= ans[1][1]=1;
	ans[0][1]=ans[1][0]=0;

	while(n){

		if(n&1){
			ans=mul(ans,T,2,2,2);
		}
		n=n/2;
		T=mul(T,T,2,2,2);
	}

	ll a=0;

	int dp[]={2,3};
	for(int i=0,j=0; j<2;j++){
		a += ( ans[i][j]*dp[j] )%MOD;
	}

	return a%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    /*
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
 	*/
 	int t; cin>>t;
 	while(t--){
 		ll a;
 		cin>>a;
 		ll ans1=matrix_expo(a);
 		cout<<ans1<<endl;
 	}
    

 return 0;   
 }