#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<unsigned long long > arr;

    ll n;


    cin>>n;
    if(n>=130)
    {
       cout<<"Yes";
       return 0;
    }


    for(ll i=0;i<n;i++)
    {
        unsigned long long num;
        cin>>num;
        arr.push_back(num);

    }

            for(ll i=0;i<n;i++)
            {
                for(ll j=i+1;j<n;j++)
                {

                    for(ll k=j+1;k<n;k++)
                    {

                        for(ll l=k+1;l<n;l++)
                        {

                            if( (arr[i]^ arr[j] ^ arr[k]^ arr[l])==0)
                            {

                                cout<<"Yes";
                                return 0;
                            }
                        }
                    }
                }

            }
            cout<<"No";


    return 0;

}
