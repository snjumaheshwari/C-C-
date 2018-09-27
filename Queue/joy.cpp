#include<bits/stdc++.h>

using namespace std;
int main()
{

    int n;
    cin>>n;
    int jmini[n];
    for(int i=0;i<n;++i)
        jmini[i]=1;
    int p1[n+1];
    int p2[n+1];
    for(int i=1;i<=n;++i)
    {
        p1[i]=i;
        p2[i]=i;
    }
    if(n==1)
      p1[1]=1;
    else if(n==2)
    {
        p1[1]=2;
        p1[2]=1;
    }
    else if(n==3)
    {
        p1[1]=2;
        p1[2]=1;
        p1[3]=3;
    }
    else if(n>3)
    {
        if(n%2==0)
        {
            for(int i=1;i<=n;i=i+2)
            {
                swap(p1[i],p1[i+1]);
            }
        }
        else if(n%2!=0)
        {
            int te=n-1;
            te=n/2;
            int i;
            for(i=1;i<=te;++i)
            {
                swap(p1[i],p1[i+1]);

            }
            ++i;
            for(;i<n;++i)
            {
                 swap(p1[i],p1[i+1]);

            }

        }
    }

    for(int i=1;i<=n;++i)
    {
        cout<<p1[i]<<" ";
    }

    cout<<"\n";
    for(int i=1;i<=n;++i)
    {
        int j=jmini[i-1];
        swap(p2[i],p2[j]);
    }
    for(int k=1;k<=n;++k)
    {
      cout<<p2[k]<<" ";
    }



    return 0;
}
