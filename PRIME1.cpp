#include<bits/stdc++.h>
#define SIZE 100002
#define ll long long
using namespace std;

int p[SIZE+1]={0};
int a[10];	


void fun()
{

	
	memset(a,-1,sizeof(a));

	for(int i=0;i<=9;i++)
		cout<<a[i]<<" ";
}
/*
void segmented_prime(ll a,ll b )
{

	int pp[b-a+2];
	//memset(pp,1,sizeof(pp));

	for(ll i=a;i<=b;i++)
	{
		pp[i-a]=1;
		//cout<<pp[i]<<" ";
	}
	if(a==1)
		pp[0]=0;

	for(ll i=2;i*i<=b ;i++)
	{
		if(p[i])
		{
		 ll x= (a/i);
			ll start = x*i;

			if (start<a)
				start+= i;
			//cout<<start<<endl;
			for(ll j=start; j<=b; j+= i)
			{
				if(i==j)
					pp[j-a]=1;
				else
					pp[j-a]=0;

			}
		}
	}

	for(ll i=a;i<=b;i++)
	{
		if(pp[i-a])
			cout<<i<<endl;
	}
	

}
*/

int main()
{

	fun();
	/*memset(p,1,sizeof(p));

	p[0]=p[1]=0;

	for(int i=2;i*i<=SIZE;i++)
	{
		if(p[i])
		{
			for(int j=i*i ; j<=SIZE;j+=i)
			{
				p[j]=0;
			}
		}
	}
	*/

	/*for(int i=1;i<10000;i++)
	{
		if(p[i])
			cout<<i<<" ";
	}


	*/
	/*
	int t;// cin>>t;
	t=1;
	while(t--)
	{
		ll m,n; cin>>m>>n;
		//segmented_prime(m,n);
		fun();
		cout<<endl;
	}*/




}
