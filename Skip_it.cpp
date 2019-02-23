#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int a0 = 0; a0 < T; ++a0)
	{
		int N, Q;
		cin>>N>>Q;
		long A[N], K[N]={0};
		for (int i = 0; i < N; ++i)
		{
			cin>>A[i];
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; j=j+i+1)
			{
				K[i] += A[j];
			}
		}

		for (int i = 0; i < Q; ++i)
		{
			int k;
			cin>>k;
			if(k >= N){
				cout<<A[0]<<endl;
			}
			else{
				cout<<K[k]<<endl;
			}
		}
	}
}