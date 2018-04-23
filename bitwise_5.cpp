#include<bits/std+++.h>
using namespace std;

int get_bit_at_position_i(int n,int i)
{
    /*
    bit positions     3 2 1 0
    Example:- n=13 => 1 1 0 1
    and find 2 bit
    Take Mask =>      0 1 0 0
    _____________________________
     n&mask =>         0 1 0 0
     the result will be zero for zero and positive for 1.
    _____________________________
    */
    return (n & (1<<i))!=0 ? 1:0;

}

void set_bit_at_position_i(int &n,int i)
{
    /*
            Take or of n and above mask..
    */
    int mask= 1<<i;

    n=n | mask;
}


void clear_bit_at_position_i(int &n)
{
    int mask=~(1<<i);
    n =n& mask;
}

// Generate all subsets using bit-masking
void generateSubsets(char *a)
{
    // Generate a range of number from 0 to 2 ^n -1;
    int n= strlen(a); // include<cstring.h>
    int range= (1<<n)-1; // 2**n = 1<<n
    for (int i=0;i<range;i++)
        filterChars(a,i);

}
void filterChars(char *a ,int n)
{
    // a="abc" and n=5 -- output should be ac.
    int i=0;
    while(n>0)
    {
        (n&1) ? cout<<a[i]:cout<<"";
        i++;
        n=n>>i;
    }
    cout<<endl;
}


int main()
{
    int num;
    cin>>num;

    int i;
    cin>>i;

    char a[100];
    cin>>a;

}
