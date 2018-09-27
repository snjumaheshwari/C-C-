#include<bits/stdc++.h>
#define MOD 10000007
using namespace std;


double power(int a,int b)
{
    if(a==0)
        return 0;
    if(b==0)
        return 1;

    double small_power=power(a,b/2);
    small_power*=small_power;

    if(b&1)
    {
        small_power*=a;
    }
    return small_power;

}

double power2(int a,int b)
{
    if(a==0)
        return 0
    if(b==0)
        return 1;

    double d=1;
    while(b)
    {
        if(b&1) // b%2==1
        {
            d*=a;
        }
            a*=a;
            b=b>>1; // b=b/2

    }
    return d;

}

// calculate a^b in logarithmic time..
int main()
{


   int a,b;
   cin>>a>>b;

   cout<<power(a,b)<<endl;
   cout<<power2(a,b)<<endl;
}
