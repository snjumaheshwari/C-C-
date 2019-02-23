
// pending

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> m;


int main()
{
	int n; cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	for(auto i:a)
		m[i]+=1;


	return 0;
}