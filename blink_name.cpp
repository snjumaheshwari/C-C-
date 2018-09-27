
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    bool flag=true;
    int count=0;
    for (int i=2;i*i<=n;i++)
    {
        flag=true;
        while(n%i==0)
        {
           if(flag)
                count++;
           flag=false;

        }

    }
    if(n>1)
        count++;


}
