// X-or Swapping..

#include<bits/stdc++.h>
using namespace std;

void xor_swapping(){
int a,b;
cin>>a>>b;
a=a^b;
b=a^b;
a=a^b;
cout<<a<<" "<<b;
}

void extract_i_th_bit_of_a_number()
{
    int n;
    int i; // i start from LSB with 0
    cin>>n>>i;
    int ans= n &( 1<<i) !=0 ? 1:0;
    cout<<ans;
}

void setIthBit(int &n,int i){
    int mask=1<<i;
    n=n | mask;
}

void clearBit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
}

int main()
{
//xor_swapping();
extract_i_th_bit_of_a_number();
}
