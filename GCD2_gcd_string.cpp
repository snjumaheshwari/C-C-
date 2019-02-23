#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin>>t;

	while(t--)
	{

	int a; cin>>a;

	string b; cin>>b;

	if(a==0){
		cout<<b<<endl;
		continue;
	}

	int num=0;

	for(auto i: b)
	{
		int n= i-'0';

		num= (num*10+ n)%a;
	}
	//cout<<num;
	cout<<__gcd(num,a)<<endl;
}
	return 0;

}