#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;

// given n..
// output: 1,2,3,... n
		// n,n-1,n-2......2,1

void increasing(int n,int i=1)
{
	if(i>n)
		return ;
	cout<<i<<" ";
	increasing(n,i+1);
}

void inc(int n)
{
	if(n==0)
		return ;
	inc(n-1);
	cout<<n<<" ";
}

void decreasing(int n)
{
	if(n==0)
		return ;
	cout<<n<<" ";
	decreasing(n-1);
}

int main()
{
	MeTime;
	int n;
	cin>>n;
	increasing(n);
	cout<<"\n";
	decreasing(n);
	cout<<"\n";
	inc(n);

	return 0;
}