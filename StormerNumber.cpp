#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


// stormer number is the number if the greatedt prime factor of n*n +1 is greater than greater than or equal to 2*i



int LargetsprimeFact(int n)
{

	int max=-1;

	for(int i=2;i*i<=n ;i++)
	{
		while(n%i==0)
		{
			n=n/i;
			if(i>max)
				max=i;
		}
	}

	if(n>1)
	{
		if(n>max)
			max=n;
	}
	return max;

}

int main()
{
	DONE;
	int a=60;
	int b=70;
	int i,j;
	i=j=10;
	if(a<100)
	{
		if(b>50){
			++i;
			else
				++j;
		}
	}
	
	cout<<i+j<<" ";

	
	return 0;
}