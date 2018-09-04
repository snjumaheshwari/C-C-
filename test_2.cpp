    #include<iostream>
    #define ll long long
    #include<bits/stdc++.h>
    using namespace std;


    ll nextPower(ll n)
    {
    	int count=0;
    	while(n!=0)
    	{
    		count++;
    		n=n/2;
    	}
    	return pow(2,count);
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

    		if(count_bits<=2)
    		{
    			cout<<2-count_bits<<"\n";
    			continue;
    		}


    	nextPow=pow(2,count_bits) ;

        first=count_bits-1 ;
        second=-1 ;
        m=n-(pow(2,first));
        while(m!=0){
            second++;
            m=m>>1 ;
        }

        z=n-(pow(2,first))- (pow(2,second));
        x=nextPow+1-n;
        y=nextPower(n-(pow(2,first)))  +(pow(2,first))-n ;

        if(first-second==1)
            cout<<(min(x,z))<<"\n";
        else
            cout<<(min(y,z))<<"\n";



    	}

    	return 0;
    }
