#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int n;
   unsigned long int num;
    cin>>n;

     long int arr[n];

    for(long int i=0;i<n;i++)
    {
        cin>>num;
        if( n<130)
        {
            arr[i]=num;
        }

    }
    if(n>=130)
    {
       cout<<"Yes";
       return 0;
    }

    for(long int i=0;i<n-3;i++)
    {
        for(long int j=i+1;j<n-2;j++)
        {
            for(long int k=j+1;k<n-1;k++)
            {
                for(long int l=k+1;l<n;l++)
                {
                    long int x= a[i] ^ a[j] ^ a[k] ^ a[l];
                    if(x==0)
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
