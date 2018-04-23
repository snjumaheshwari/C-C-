#include<bits/stdc++.h>
ios_base::sync_with_stdio(false);

using namespace std;


int find_lcm(int a,int b)
{
    return (a *b)/__gcd(a,b);
}
int main()
{
    int n,m,lcm;
    cin>>n>>m;

    int a[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];


    int rows[n];
    int col[m];

    for(int i=0;i<n;i++)
    {
        lcm=a[i][0];
        for(int j=0;j<m;j++)
            lcm=find_lcm(lcm,a[i][j]);
        rows[i]=lcm;
    }
    for(int j=0;j<m;j++)
    {
        lcm=a[0][j];
        for(int i=0;i<n;i++)
        {
            lcm=find_lcm(lcm,a[i][j]);
        }
        col[j]=lcm;
    }
/*
    for(int i=0;i<n;i++)
        cout<<rows[i]<<" ";

    for(int i=0;i<m;i++)
        cout<<col[i]<<" ";
*/
    bool flag=true;
    for(int i=0;i<n && flag;i++)
    {
        for(int j=0;j<m &&flag;j++)
        {
            if(a[i][j]!=__gcd(rows[i],col[j]))
            {
            cout<<"IMPOSSIBLE";
                flag=false;
            }
        }
    }
    if(flag)
        cout<<"POSSIBLE";

return 0;
}
