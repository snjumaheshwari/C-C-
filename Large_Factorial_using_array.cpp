#include<bits/stdc++.h>
using namespace std;

void multiply(int *a , int &n, int number)
{
    int carry=0;

  for(int i=0;i<n;i++)
  {
    int product=a[i]*number+carry;
    int rem=product%10;

    a[i]=rem;

    carry=product/10;

  }

  while(carry>0)
  {
      a[n]=carry%10;
      n+=1;
      carry/=10;

  }
}

int main()
{
  int n=1;

  int a[1000]={0};

  a[0]=1;
    int num;
 cin>>num;

  for(int i=2;i<=num;i++)
  {
        multiply(a,n,i);

    for(int i=n-1;i>=0;i--)
  {
    cout<<a[i];
  }
  cout<<"\n";
  }


}
