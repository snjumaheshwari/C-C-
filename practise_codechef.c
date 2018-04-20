#include<iostream.h>
using namespace std;

int main()
{

long int N,Q,t;

cin>>N>>Q;
long int a[N];

long int min=a[0];
long int max=a[0];

for(long int i=0;i<n;i++)
{
    if(a[i]<min)
        min=a[i];
    if(a[i]>max)
        max=a[i];
}
while(Q--)
{
    cin>>t;
    if(t>=min && t<=max)
        cout<<"Yes";
    else
        cout<<"No";
}

return 0;
}
