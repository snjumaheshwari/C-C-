/*
why bitwise operator : -bitwise operator are very fast..

suppose bitwise operator take n time.. then
division multiplication takes n**2 time..
modulo takes n**3 time..

 & bitwise and
 | bitwise or
 ^ bitwise x-or
 >> right shift
 << left shift

 */
 #include<bits/stdc++.h>
 using namespace std;

 /*
 question . 1 you are given an array i which every number occur twice except one.
 find that number ?
 */

 // solution :- just x-or all the numbers..
 void find_unique()
 {

     int N; //N must be odd
     cin >>N;

     int a[N];

     for (int i=0;i<N;i++)
        cin>>a[i];

    int ans=0; // 0^n=n
                // n ^n =0

    for(int i=0;i<N;i++)
    {
        ans^=a[i];
    }
    cout<<ans<<endl;
 }


// question 2 check weather n is even or odd..

// if (n & 1) is 1 => odd
// else => even

void check_even()
{

     int num;
    cin>>num;

    if(num&1)
        cout<<"odd"<<endl;
    else
        cout<<"even"<<endl;

}


// how to get the last bit of number ?
// simply do & with 1.



// question 3.

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
    int a,b;
    cin>>a>>b;
    cout<<countBits(a^b);
    return 0;
}
