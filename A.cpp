/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

    ll s,x,y,n; cin>>s>>x>>n;

    map<ll,ll> m;


    while(n--){
        cin>>x>>y;
        m[x]=y;
    }

    int i=1;
    while(s>0){

        if(m[i]){
            ll dist= min(s,m[i]);
            s=s-dist;
        }
        else{
            ll dist= min(s,x);
            s=s-dist;
        }
        i++;
    }

    cout<<i<<endl;
}
