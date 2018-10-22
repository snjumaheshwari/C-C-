#include<bits/stdc++.h>
#define ll long long
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL); 

using namespace std;

int p[100002]={0};

void Seive_Prime()
{
	for(ll i=3;i<=100001;i+=2)
	{
		p[i]=1;
		p[i+1]=0;
	}
	p[0]=p[1]=0;
	p[2]=1;

	for( ll i=3;i*i<=100001;i++)
	{
		if(p[i])
		{
			for(ll j=i*i;j<=100001;j+=(2*i))
				p[j]=0;
		}
	}

}

void Segmented_Seive(ll a, ll b)
{
	int pp[b-a+2]={0};

	for(ll i=a;i<=b;i++)
	{
		pp[i-a]=1;
	}
	if(a==1)
		pp[0]=0;

	for(ll i=2;i*i<=b;i++)
	{
		if(p[i])
		{
			ll  k= floor ( a/i -i);
			k=k< 0 ? 0:k;
			ll start=(i*i + i*k); 
			//cout<<" start a and i"<<start<< " "<<a <<" "<<i<<endl;

			for(ll j=start ;j<=b;j+=i ) 
			{
				if(j==i)
					continue;
				if(j%i==0)
					pp[j-a]=0;
			}

		}
	}

	for(ll i=a; i<=b;i++)
	{
		if(pp[i-a])
		{
			cout<<i<<endl;
		}

	}

}


int main()
{
	Done;
	int t; cin>>t;

	Seive_Prime();
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		Segmented_Seive(a,b);
		cout<<endl;
	}
	return 0;
}