#include<bits/stdc++.h>
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()
{

	int t; cin>>t;
	while(t--)
	{

		int n,m;
		cin>>n>>m;
		//int freq[401];
		map<int,int> freq;

		//memset(freq,0,sizeof(freq));

		int x;
		int b[m];
		for(int i=0;i<m;i++)
		{
			cin>>b[i];
			freq[b[i]]++;
		}


        set<int> tables;
        for(int i=0;i<m;i++){

            if(len(tables) < m){
                tables.add(b[i]);
                freq[b[i]]--;

            }
            else{

            }

        }


	}


    return 0;

}
