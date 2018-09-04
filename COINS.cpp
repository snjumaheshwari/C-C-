#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    while(cin>>n)
    {
      long long int a=n/2;
       long long int b=n/3;
       long long int c=n/4;
        if(a+b+c >n)
            cout<<a+b+c;
        else
            cout<<n;
    }

    return 0;
}
