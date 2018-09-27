#include<bits/stdc++.h>
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    MeTime

    //#ifndef ONLINE_JUDGE
      //  freopeb("in","r",stdin);
   // #endif

    string s; cin>>s;
    vector<char> ans;

    for(char i: s)
    {
        if(i=='y' || i=='Y' ||i=='a' || i== 'A' || i=='e' || i=='E' || i=='i' || i=='I' || i=='o' || i=='O' || i=='u' || i=='U')
            continue;
        if(int(i) <= 97)
            i=i+32;
        ans.push_back('.');
        ans.push_back(char(i));
    }
    for(auto i: ans)
        cout<<i;

    return 0;
}
