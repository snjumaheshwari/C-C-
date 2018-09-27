/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        m=s.length();

        if(m>10)
        {
            cout<<s[0]<<m-2<<s[m-1]<<"\n";
        }
        else
        cout<<s<<endl;
    }


    return 0;
}

