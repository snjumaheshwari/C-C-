#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n+1];
    bool flag=true;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=2;i<=n;i++){
        if(arr[i/2] > arr[i] ){
            continue;
        }
        else{
            flag=false;
            break;
        }
    }
    if(!flag){
        cout<<" Not max heap\n";
    }
    else{
        cout<<"Max heap\n";
    }

}
