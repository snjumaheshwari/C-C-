#include<bits/stdc++.h>
#define ll long long
using namespace std;


/* def fnext_power(n):
    i=0
    while(n!=0):
        n=n>>1
        i+=1
    return 1<< i */

ll nextPower(ll n)
{
	int count=0;
	while(n!=0)
	{
		count++;
		n=n>>1;
	}
	return 1<<count;
}


int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;
		if(n==1)
			{
			cout<<"2\n";
			continue;
			}
		ll m=n;
		int count_bits=0;
		int count_ones=0;
		int first=0;
		int second=0;
		ll nextPow=0;
		ll x,y,z;
		while(m!=0)
		{
			if(m&1)
			{
				count_ones++;
			}
			count_bits++;
			m=m>>1;
		}

		if(count_ones<=2)
		{
			cout<<2-count_ones<<"\n";
			continue;
		}


	//nextPow=1<<count_bits ;
    nextPow=pow(2,count_bits);
    //cout<<"next power is "<<nextPow<<endl;

    first=count_bits-1 ;
    second=-1 ;
    //m=n-(1<<first);
    m=n-pow(2,first);
    while(m!=0){
        second++;
        m=m>>1 ;
    }

    //z=n-(1<<first)- (1<<second);
    z=n-pow(2,first)-pow(2,second);

    x=nextPow+1-n;
    //y=nextPower(n-(1<<first))  +(1<<first)-n ;
    y=nextPower(n- pow(2,first)) + pow(2,first) -n;
    if(first-second==1)
        cout<<(min(x,z))<<"\n";
    else
        cout<<(min(y,z))<<"\n";



	}

	return 0;
}

