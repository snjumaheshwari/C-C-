#include<bits/stdc++.h>
#define ll long long
#define INF 10000000000
using namespace std;


/*
test=int(input())
	for t in range(test):
		n=int(input())
		arr=list(map(int,input().split()))
		m=min(arr)
		smallest=10000000
		second=100000000
		for i in arr:
			if(i <=smallest):
				second=smallest
				smallest=i
			elif(i<second):
				second=i
		print(smallest+second)

*/

int main()
{

    ll test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for (ll i=0 ; i<n;i++)
        {
            cin>>arr[i];
        }
            ll smallest=INF;
            ll second=INF;

            for( ll i =0;i<n;i++)
            {
                if(arr[i]<=smallest)
                {
                    second=smallest;
                    smallest=arr[i];
                }
                else if(arr[i]<second)
                    second=arr[i];
            }
        cout<<second+smallest<<"\n";
    }


}
