#include <bits/stdc++.h>

using namespace std;

// Complete the theGreatXor function below.
long theGreatXor(long x) {

    int i=0;
    long ans=0;
    while(x)
    {
        int n=!(x&1);

        ans+=(1 << i)*n;
        x=x>>1;
        i++;
    }
    return ans;

}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long n;
        cin>>n;
        cout<<theGreatXor<<endl;

    }
}
