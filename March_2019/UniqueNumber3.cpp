#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;

    int sum[65];
    int arr[n];
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        int num= arr[i];
        int p=0;
        while(num){
                sum[p]+= (num&1);
                num= num>>1;
                p++;
        }
    }

    int ans=0;

    int j=1;
    for(int i=0;i<65;i++){
        ans+= (sum[i]%3)*j;
        j=j*2;
    }
    cout<<ans<<endl;


}
