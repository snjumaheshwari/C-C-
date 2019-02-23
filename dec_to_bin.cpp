
#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll dec_to_binary(string s)
{
	ll num=0;

	int n=s.length();

	int p=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]-'0')
		{
			num+= pow(2,p);
		}
		p++;

	}

	return num;
}

int main()
{

string s;
	while(1)
	{

		cin>>s;
		cout<<dec_to_binary(s)<<endl;;
	}
}