
// check weather n is even or odd..

// if (n & 1) is 1 => odd
// else => even

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;

    if(num&1)
        cout<<"odd"<<endl;
    else
        cout<<"even"<<endl;

    return 0;

}

// how to get the last bit of number ?
// simply do & with 1.
