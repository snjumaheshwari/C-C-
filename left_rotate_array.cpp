#include<bits/stdc++.h>
using namespace std;

void reverseit(int *a,int start,int stop)
{
    while(start <stop)
     swap(a[start++],a[stop--]);
}
int main()
{
   int a[]={1,2,3,4,5};
   int n=5;
   int k=2;


    // arr=[ 1,2,3,4,5,6] k=2
    // output should be : [3,4,5,6,1,2]

    reverseit(a,0,k-1);
    reverseit(a,k,n-1);
    reverseit(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}
