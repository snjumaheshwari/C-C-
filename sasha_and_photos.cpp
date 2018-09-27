#include<bits/stdc++.h>
#define ll long long
using namespace std;


void find(ll rows1,ll cols1,string str1,ll rows2,ll cols2,string str2)
{
    ll l1,l2,a1,b1,a2,b2,m;
    ll ans=0,answer=0,r1=0,r2=0,c1=0,c2=0,flag=0;
    ll count=0;

    l1=rows1* rows2 /__(gcd(rows1,rows2));
    l2=cols1*cols2 /__(gcd(cols1,cols2));

    a1=l1 / rows1;
    b1=l2 / cols1;
    a2=l1 / rows2;
    b2=l2 / cols2;


    ll x1=a1,x2=a2,y1=b1,y2=b2;
    while(r1<rows1){
        if(str1[r1*cols + c1]==str2[r2*cols+c2])
            ans+=min(y1,y2);
        if(y1==y2){
            y1=b1;
            y2=b2;
            c1+=1;
            c2+=1;
            if(c1==cols1 and c2==cols2){
                c1=0;
                c2=0;
                m=min(x1,x2);
                answer += (ans*m);
                ans=0
                x1=x1-m;
                x2=x2-m;
                count+=m;
                flag+=m;
                if(count==a1){
                    r1+=1;
                    x1=a1;
                    count=0;
                    }
                if(flag==a2)
                {
                    r2+=1;
                    x2=a2;
                    flag=0;
                }
            }
        }
        else if(y1<y2){
            y2=y2-y1;
            y1=b1;
            c1+=1;
        }
        else
            {
            y1=y1-y2;
            y2=b2;
            c2+=1;
        }
    }

    cout<<answer<<"\n";

}
int main()
{

    int test;
    ll r1,c1,r2,c2;
    string str1,str2;
    cin>>test;
    //test=int(input())
    while(test--)
    {
       cin>>r1>>c1;
       cin>>str1;
       cin>>r2>>c2;
       cin>>str2;
        find(r1,c1,str1,r2,c2,str2)
    }
    return 0;

}
