#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;

int main()
{
	DONE
	int a1,a2,b1,b2;
	cin>>a1>>b1>>a2>>b2;

	if(b1!=b2)
	{
		int x=a1-a2;
		int y=b2-b1;
		if(x*y >=0 && x%y==0)
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}
	else
	{
		if(a1==a2)
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}

	
	return 0;
}