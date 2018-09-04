#include<bits/stdc++.h>
using namespace std;

bool found(int a[], int value)
{

    for(int i=0;i<5;i++)
        if(a[i]==value)
            return true;
    return false;
}

int main()
{
    int a[]={1,2,5,6,0};
    int n=sizeof(a)/ sizeof(a[0]);
    // output :- [0,1,2-1,-1,5,6]

    // check whether 1 to max(n) in array

     int m=a[0];

    for(int i=0;i<n;i++)
    {
        if(a[i]>m)
            m=a[i];

    }

    int t[m+1];

    // first method


        for(int i=0;i<=m;i++)
            {
                if(found(a,i))
                    t[i]=i;
                else
                    t[i]=-1;
            }

    // second method

    memset(a,m+1,-1);
    for(int i=0;i<=m;i++)
    {
        t[a[i]]=a[i];

    }


    for(int i=0;i<m;i++)
    {
        cout<<t[i]<<" ";
    }

}
