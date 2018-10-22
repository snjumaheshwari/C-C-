#include<iostream>
#define ll long long
#include<bits/stdc++.h>
#define Done ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);

}

int main()
{
	ll a,b,c; 
		cin>>a>>b>>c;

		ll g= gcd(a,b);

		if(c%g==0)
		{
	
			int dp[a*b+1];
		
			dp[0]=1;
			dp[a]=1;
			dp[b]=1;
			if(a< b)
			{
				swap(a,b);
			}

			for(int i=1;i<a;i++)
			{
				if(i%b==0)
					dp[i]=1;
				else
					dp[i]=0;

			}

			for (int i=a+1; i<= a*b ;i++)
			{
				dp[i]= (dp[i-a] || dp[i-b]);
			}

			
			if( c> a*b || dp[c])
				cout<<"Yes";
			else
				cout<<"No";
			
		}
		else
		{
			cout<<"No";
		}
		
	

	return 0;
}