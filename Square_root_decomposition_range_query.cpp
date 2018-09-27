#include<bits/stdc++.h>
#define ll long long
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int query(int *blocks, int * arr,int l,int r,int rn)
{
    while(l<=r && l%rn!=0 )
    {
        ans+=arr[l];
        l++;
    }
    while(l+rn<=r)
    {
        ans+=blocks[l/rn];
        l+=rn;
    }
    while(l<=r)
    {
        ans+=arr[l];
        l++;
    }

}
void update(int*blocks , int * arr, int i, int rn,int value)
{
    block[i/rn]+= ( value-arr[i]);
    arr[i]=value;
}
int main()
{
    int a[]={1,3,5,2,7,6,3,1,4,8};
    int n=sizeof(a)/ sizeof(int);

    int rn=sqrt(n);
    int *blocks=new int[rn+1]{0};

    int block_id=-1;
    for(int i=0;i<n;i++)
    {
        if(i%rn==0)
            block_id++;
        blocks[block_id]+=a[i];

    }
    for(int i: blocks)
        cout<<i<<" ";

    return 0;

}
