#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;



bool P[100000000]={true};

bool Prime(int n)
{
	P[0]=false;
	P[1]=false;
	for(int i=2;i*i<=n;i++)
	{
		for(int j=2*i; j<=n;j+=i)
		{
			P[j]=false;
		}

	}
	return P[n];

}
bool is_prime(int n)
{
	if(n<=1)
		return false;
	if(n<4)
		return true;
	if(n%2==0)
		return false;

	for(int i=3;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}



int main()
{

	memset(P,true,1000000);
	DONE
	int num,k;
	cin>>num;



	// every odd integer > 5 can be expressed as sum of odd prime integer + ( even semi prime number )

	// ( num ) = p1 + 2* p2  ( where p1 and p2 are prime numbers and num >5 and num is odd)

/*	if(Prime(num)==is_prime(num))
			cout<<" Correct"<<endl;
	else
		cout<<" Wrong "<<endl;

*/

	
	for (int p2=2; p2<=num && (num-2*p2)>0;p2++)
	{

		if(is_prime(p2) && is_prime(num-2*p2))
		{
			cout<< num << " = "<< (num- 2*p2)<<" + 2 * "<<p2<<endl;
		}

	}

}
