#include<bits/stdc++.h>
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    MeTime;

    //#ifndef ONLINE_JUDGE
      //  freopeb("in","r",stdin);
   // #endif

    map< char, char> L,R;
    string s="?qwertyuiopasdfghjkl;zxcvbnm,./?";

    int n=s.length();
  //  cout<<n;

    for(int i=1;i<n-1;i++)
    {
        L[s[i]]= s[i+1];
        R[s[i]]=s[i-1];
    }
    char x; cin>>x;
    vector<char> ans;
    string q; cin>>q;

    if(x=='R')
    {
        for (auto i: q)
            ans.push_back(R[i]);

    }
    else{

        for(auto i: q)
            ans.push_back(L[i]);
    }

    for (auto i: ans)
    {
        cout<<i;
    }

    return 0;
}

