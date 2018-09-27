#include<bits/stdc++.h>
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int just_greater_or_equal(int sum[],int item, int start, int last)
{

    while(last> start)
    {
        int mid=(start+last)/2;
       // cout<<"\n "<< start<< " "<<mid<<" "<<last;
        if(item== sum[mid])
            return mid;
        if(item> sum[mid])
            start=mid+1;
        else
            last=mid;
    }
    return last;
}

int main()
{
    MeTime;

    //#ifndef ONLINE_JUDGE
      //  freopeb("in","r",stdin);
   // #endif

   int n; cin>>n;

   int *a=new int[n+1]{0};
   int *sum=new int[n+1]{0};

   for (int i=1;i<=n;i++)
   {
       cin>>a[i];
       sum[i]=sum[i-1]+a[i];
   }
   int m; cin>>m;

  // for(int i=0;i<=n;i++)
    //    cout<<sum[i]<<" ";
   cout<<endl;
   for (int i=0;i<m;i++)
   {
       int x; cin>>x;
    // search for element x or greater in sum
        int y=just_greater_or_equal(sum,x,0,n+1);
        cout<<y<<"\n";

   }

    return 0;
}


