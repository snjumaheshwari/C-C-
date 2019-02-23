#include<bits/stdc++.h>
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

void mul(int arr1[],int arr2[],int n1,int n2)
{
	

}

void multiply(string s1,string s2)
{

	int a[10001],b[10001], ans[10001];

	int i=0;
	for(auto ch : s1){
		a[i++]= ch-'0';
	}
	int n1=i;

	int j=0;
	for(auto ch: s2){
		b[j++]=ch-'0';
	}
	int n2=j;

	mul(arr1,arr2,n1,n2);

}

int main()
{
	int t; cin>>t;

	while(t--)
	{

		string s1; cin>>s1;
		string s2; cin>>s2;

		multiply(s1,s2);
	}

	return 0;
}