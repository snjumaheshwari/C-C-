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


void Segmented_Seive(int *pp, int a, int b)
{
	int N=10000;
	int p[N+1]={0};

	int sqrt_b=sqrt(b);
	primeSeive(p,sqrt_b);

	for(int i=a;i<=b;i+=1)
		pp[i-a]=1;

	for(int i=a; i<=1;i++)  // use to handle case when a=0 or a=1
		pp[i-a]=0;

	for(int i=2;i*i <=b ;i++)
	{
		if(p[i])
		{
			for(int j=a;j<=b ;j++)
			{
				if(j==i)
					continue;
				else if (j%i==0)
					pp[j-a]=0;
			}

		}
	}




}

int main()
{

	int a,b;
	cin>>a>>b;

	
	int pp[b-a+1]={0};

	Segmented_Seive(pp,a,b);

	for(int i=a;i<=b;i++)
	{
		if(pp[i-a])
			cout<<i<< " ";
	}

}