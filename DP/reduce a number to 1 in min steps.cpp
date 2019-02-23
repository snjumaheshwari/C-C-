#include<bits/stdc++.h>
#define MOD 1000000007
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL);

#define pb push_back
#define mp make_pair

#define MAX 100005

typedef long long ll;
typedef long double ld;

const int inf=(int)1e9;

using namespace std;

int reduce_no(int n){
	if(n==1){
		return 0;
	}
	int q1=inf,q2=inf,q3=inf;

	if(n%3==0) q1= 1+reduce_no(n/3);
	if(n%2==0) q2= 1+reduce_no(n/2);
	q3=1+reduce_no(n-1);

	return min(q1,min(q2,q3));

}

int dp[10000];
int reduce_no_dp(int n){
	if(n)

}

int main(){

	int n; cin>>n;



	return 0;
}