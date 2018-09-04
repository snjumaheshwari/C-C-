#include<bits/stdc++.h>
#define ll long long
#define INF 10000000000
using namespace std;

/*
	test=int(input())
	for t in range(test):
		n=int(input())
		string=input().strip()
		if 'Y' in string:
			print("NOT INDIAN")
		elif 'I' in string:
			print("INDIAN")
		else:
			print("NOT SURE")

*/

int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        bool found=false;

        for( ll i=0 ; i<n;i++)
        {
            if(s[i]=='Y')
            {
                cout<<"NOT INDIAN\n";
                found=true;
                break;
            }
            if(s[i]=='I')
            {
                cout<<"INDIAN\n";
                found=true;
                break;
            }
        }
        if(! found)
            cout<<"NOT SURE\n";


    }

}
