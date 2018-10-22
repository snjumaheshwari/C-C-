#include<bits/stdc++.h>
#define ll long long
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int N,M;
int Board[302][302];
int answer[610];

int distance(pair<int,int> x,pair<int,int> y)
{
	return abs(x.first-y.first) + abs( x.second-y.second);
}

int main()
{

	int t; cin>> t;

	while(t--)
	{
		cin>>N>>M;

		string temp;

		for(int i=1;i<=N+M-2;i++)
		{
			answer[i]= 0;
		}

		for(int i=0;i<N;i++)
		{
			cin>>temp;
			for(int j=0;j<M;j++)
			{

				Board[i][j]=temp[j]-'0';
			}
		}

		/*cout<<" Printing Board "<<endl;

		for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                cout<<Board[i][j]<<" ";
            cout<<endl;
		}
    */

	 	vector<pair<int,int> > arr;
	 	pair<int,int> p;
    	for(int i=0;i<N;i++){
        	for(int j=0;j<M;j++){
        		if(Board[i][j]==1)
                	{
                		p.first=i;
                		p.second=j;
                		arr.push_back(p);
                	}
            }
        }



    int l=arr.size();
   /* cout<<" Printing Houses " <<endl;
    for(int i=0;i<l;i++){
        cout<<arr[i].first << " "<<arr[i].second<<endl;
    }
    */
    for(int i=0;i<l;i++){
        for(int j=i+1; j<l;j++){
            int dis=distance(arr[i], arr[j] );
            answer[dis]++;
   		 }
	}

      for(int i=1;i<=N+M-2;i++)
      	cout<<answer[i]<<" ";

      cout<<"\n";

	}


	return 0;

}

