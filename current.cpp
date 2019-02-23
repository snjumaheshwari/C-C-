#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main(){
	int n; cin>>n;

	int a[n],b[n],c[n],d[n];


	for(int i=0;i<n;i++){
		//cin>>a[i]>>b[i]>>c[i]>>d[i];
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}



	//unordered_map<int,int> m;
	//m.reserve(n*n);
	vector<int> sum;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//m[a[i]+b[j]]++;
			sum.push_back(a[i]+b[j]);
		}
	}



	vector<int> val;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//ans+= n[-(c[i]+d[j])];
			val.push_back(-c[i]-d[j]);
		}
	}
	

	
}