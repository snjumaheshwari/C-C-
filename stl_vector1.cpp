#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> v(10);

    for(int i=0;i<10;i++)
        cin>>v[i];

    vector<char> v2(10);

    reverse_copy(v.begin(),v.end(),v2.begin());

    for(int i=0;i<v2.size();i++)
    {

        cout<<v2[i]<<" ";
    }

    next_permutation(v.begin(),v.end());

    cout<<endl<<endl;

    for(int i=0;i<v.size();i++)
    {

        cout<<v[i]<<" ";
    }


    return 0;
}
