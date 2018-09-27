#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;

string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

char sp[][10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

// use arr or sp( spelling)

void PrintNumber(ll n)
{
	if(n==0)
		return ;

	int rem=n%10;
	PrintNumber(n/10);
	cout<<arr[rem]<<" ";

}

int main()
{
	MeTime;
	ll n;
	cin>>n;
	PrintNumber(n);

	return 0;
}