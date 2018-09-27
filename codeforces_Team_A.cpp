#include<bits/stdc++.h>
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    MeTime

    //#ifndef ONLINE_JUDGE
      //  freopeb("in","r",stdin);
   // #endif

   int n; cin>>n;
   int ans=0;
    int sum;
   int a,b,c;
   while(n--)
   {
       int sum=0;
       cin>>a>>b>>c;
       sum=a+b +c;
       if(sum>=2)
        ans+=1;
       sum=0;
   }
   cout<<ans;

    return 0;
}

