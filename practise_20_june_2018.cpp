#include<bits/stdc++.h>
using namespace std;


void fun1()
{

    /*char ch='a';
    cout<<int(ch)<<"\n"; //97-122

    char ch3='Z';
    cout<<int(ch3)<<"\n"; // 65 -90

    */
    char ch;
    cin>>ch;

    int a= ch;
    if(a>=65 && a<=90)
        cout<<"U\n";
    else
        cout<<"L\n";

}

long int reverse_number(long int n)
{
    long int rev=0;
    int rem=0;
    while(n>0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }

    return rev;
}

long int decimal_to_octet(long int n)
{
    long int rev=0;
    int rem=0;

    int p=1;
    while(n>0)
    {
         rem=n%8;
        rev=rev+rem*p;
       // cout<<rev<<endl;
        n=n/8;
        p=p*10;
    }
    return rev;
}
void pattern(int n)
{
    int i,j;
    for( i=1;i<=n;i++)
    {
        for( j=1;j<=i;j++)
            cout<<j;

        int k=n-j;

        while(k>=0){
            cout<<"*";
            k--;
        }
        cout<<endl;

    }

}
void print_series(n1,n2)
{
    // n1=> number of terms to print
    // any term should not be multiple of n2

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<decimal_to_octet(63);
    pattern(7);
        return 0;
}
