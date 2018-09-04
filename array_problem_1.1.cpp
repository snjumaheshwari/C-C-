#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={1,2,5,6,0};
    int n=sizeof(a)/ sizeof(a[0]);
    int *max_array=max_element(a,a+n);

   // cout<<*max_array<<" ";

    int temp[*max_array +1];
    memset(temp,-1,sizeof(temp));

    for(int i=0;i<n;i++)
    {
        temp[a[i]]=a[i];
    }

    for(int i=0;i<=*max_array;i++)
    {
        cout<<temp[i]<<" ";
    }
    return 0;
}
