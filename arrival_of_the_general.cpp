#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;   // 2<=n<=100
    cin>>n;
    int a[n];  // 1<=a[i]<=100

    for(int i=0;i<n; i++)
        cin>>a[i];

    int min_arr=a[0];
    int min_pos=0;
    int max_pos=0;
    int max_arr=a[0];

    for(int i=1;i<n;i++)
    {
        if(a[i]<=min_arr)
        {
            min_arr=a[i];
            min_pos=i;
        }
        if(a[i]>max_arr)
        {
            max_arr=a[i];
            max_pos=i;
        }
    }

    if(min_pos>max_pos)
    {

    }
    else{


    }
}
