#include<bits/stdc++.h>
using namespace std;

int main(){


    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    #endif // ONLINE_JUDGE



    while(1){

        int n; cin>>n;
        if(n==0){
            break;
        }
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans=1;
        stack<int> s;
        s.push(-1);
        int i=0;
        for(;i<n;){

            if(arr[i]==ans){
                ans++;
                i++;
            }
            else if(s.top()==ans){
                ans++;
                s.pop();
            }
            else{
                s.push(arr[i]);
                i++;
            }
        }

        while(s.top()==ans){
            s.pop();
            ans++;
        }
        if(ans==n+1){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }

}
