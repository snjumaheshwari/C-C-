#include<bits/stdc++.h>
#define ll long long
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    MeTime;
    int n,k; cin>>n>>k;

    int sum=0;
    map<int,int> tweets;
    string s;
    int t;
    while(k--)
    {
        cin>>s;
        if(s.length()<7)
        {
            cin>> t;
            if(tweets[t]==0)
            {
                tweets[t]=1;
                sum++;
            }
            else
            {
                tweets[t]=0;
                sum--;
            }
        }
        else
        {
            sum=0;
            for (auto i : tweets)
            {
                int key=i.first;
                tweets[key]=0;
            }
        }
        cout<<sum<<"\n";
    }

    return 0;
}
