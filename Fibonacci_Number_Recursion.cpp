#include <bits/stdc++.h>
#define ll long long
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int fib(int n)
{
	if(n==0 || n==1)
		return n;
	else
		return fib(n-1)+fib(n-2);
}

int main()
{
	MeTime;
	// generate nth fibonacci number using recursion..
	// 0,1,1,2,3,5,8
	// 0,1,2,3,4,5,6

	int n;
	cin>>n;

	cout<<fib(n);

	return 0;
}