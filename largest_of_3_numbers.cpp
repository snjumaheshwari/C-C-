#include<bits/stdc++.h>
using namespace std;


int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int a=0,b=0,c=0;
    cin>>a>>b>>c;

    if(a>b && a>c)
        cout<<a;
    else if(b>a && b>c)
        cout<<b;
    else
        cout<<c;
}
