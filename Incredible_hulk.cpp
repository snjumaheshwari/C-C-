#include<bits/stdc++.h>
using namespace std;


int set_bits(int n)
{
    int count=0;
    while(n)
    {
        count+=n&1;
        n=n>>1;
    }
    return count;


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    int n;

    cin>>test;

    for(int i=0;i<test;i++)
    {
        cin>>n;
        cout<<set_bits(n)<<"\n";
    }
}
