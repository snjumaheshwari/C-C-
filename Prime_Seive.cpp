#include<bits/stdc++.h>

using namespace std;


void primeSeive(int* p ,int n)
{
	p[0]=0;
	p[1]=0;
	p[2]=1;

	// mark all odd number as primes..
	for(int i=3;i<=n;i+=2)
		p[i]=1;

	// Seive logic -> 

	for(int i=3;i*i<=n;i++)
	{
		if(p[i])
		{
			for(int j=i*i ; j<=n;j+= 2*i)
			{
				p[j]=0;
			}
		}
	}
}

int main()
{

 int N=10000;
int p[N+1]={0};

	int n;
	cin>>n;

	primeSeive(p,n);

	for(int i=0;i<=n;i++)
	{
		if(p[i])
			cout<<i<< " ";
	}

}