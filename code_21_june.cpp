#include<bits/stdc++.h>
using namespace std;

bool isbosten(long int n)
{
  // sum of digits ..
  long int m=n;
  int sum=0,rem;
  while(n>0)
  {
    rem=n%10;
    sum+=rem;
    n=n/10;
  }

  //cout<<"sum is :"<<sum<<endl;
  // sum of prime factor..

  int sum_prime=0;
  bool isprime=true;
  while(m>1)
  {
    long int limit=pow(m,0.5)+1;
    bool flag=true;
    for(int i=2;i<=limit;i++)
    {
      if(m%i==0)
      {
        m=m/i;
        sum_prime+=i;
        isprime=false;
        flag=false;
        break;
      }
    }
    if(flag and not isprime)
    {
      sum_prime+=m;
      break;
    }
    if(flag)

  }
  //cout<<sum_prime;
  //cout<<sum;
  if(sum==sum_prime)
    return true;
  else
    return false;
}
int main() {

  long int n;
  cin>>n;
  cout<<(int)isbosten(n);
	return 0;
}
