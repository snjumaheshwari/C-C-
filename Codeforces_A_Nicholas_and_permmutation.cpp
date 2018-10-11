#include<iostream>
#define ll long long
#define INF 1000000000
using namespace std;

int main()
{

	ll n;
	cin>>n;

	ll a[n];

	ll min=INF;
	ll max= -INF;

	for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
	ll pos1=-1;
	ll pos2=-1;


	for(ll i=0;i<n;i++)
	{

		if(a[i]==min || a[i]==max)
		{
			if(pos1==-1)
				pos1=i;
			else
				pos2=i;

		}
	}
	
	int d1=(pos1-0);
	int d2=(n-1-pos2);

	if(d1>d2){
		pos1=0;
	}
	else
		pos2=n-1;

	cout<<pos2-pos1;

}