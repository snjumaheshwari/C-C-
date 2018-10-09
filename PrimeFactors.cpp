#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


int egcd(int a,int b,int &x, int&y )
{


}

void primefactors(int num)
{

	for(int p=2;p*p<=num;p++)
	{
		while(num%p==0)
		{
			cout<<p<<" ";
			num=num/p;
		}
	}
	if(num>1)
		cout<<num ;
}


int main()
{
	DONE
	int n; cin>>n;
	primefactors(n);

	
	return 0;
}