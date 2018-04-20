
/*
     Given 2 numbers A and B.
     How many bits are required to change to convert A int B?


     Approach :- count number of 1's in A^B.
*/


int countBits(int n)
{
     // O( no. of bits)
    int count=0;
    while(n>0)
    {
        count+=(n&1);
        n=n>>1;
    }
}

int countBitsFast(int n)
{
    int count=0;
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;

}
void hack(){
// n and n-1 hack..
//doing n&n-1 removes last set bit.


}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<countBits(a^b);
    return 0;
}
