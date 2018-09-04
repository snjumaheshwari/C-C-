#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int test;
        cin>>test;

        while(test--)
        {
            int n;
            cin>>n;

            int a[n],sum[n+1],freq[n];

            for(int i=0;i<n;i++)
                freq[i]=0;

           // for(int i=0;i<n+1;i++)
             //       sum[i]=0;

            freq[0]=1;

            ll s=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
                s+=a[i];
               // sum[i]=s;
               s=s%n;
               freq[s]++;

            }

            ll ans=0;
            for(int i=0;i<n;i++)
                ans+=((freq[i])*( freq[i]-1))/2;

            cout<<ans<<"\n";

        }
    return 0;
}
