#include<bits/stdc++.h>
using namespace std;

long distance (long a,long b){
    long x;
    cout<<"Q "<<a<<" "<<b<<" ";
    cin>>x;
    return x;
}

int main(){

    const int M=pow(10,9);
//xl,yl,xr,yr= randint(0,M),randint(0,M),randint(0,M), randint(0,M)


/*if(xr <=xl):
    xl,xr= xr,xl
if(yr<= yl):
    yl,yr= yr,yl

print(xl,yl,xr,yr)
*/

int t; cin>>t;
while(t--){
    long a1= distance(0,0);

    long b1= distance(M,M);

    long t=a1,s=0;

    long u= M-b1,v=M;


    int cnt=0;
    while(1){
        cnt+=1;
        long a2= distance(t,s);
        if(a2==0)
            break;
        t-=a2;
        s+=a2;


        long a3= distance(t,s);
        if(a3==0)
            break;
        t+=a3;
        s-=a3;
    }

    while(1){
        long b2= distance(u,v);
        if(b2==0)
            break;
        u+=b2;
        v-=b2;
        cnt+=1;
        long b3= distance(u,v);
        if(b3==0)
            break;
        u-=b3;
        v+=b3;
    }
    cout<<"A "<<t<<" "<<s<<" " <<u<<" "<<v<<endl;
    int x; cin>>x;
}
return 0;
}
