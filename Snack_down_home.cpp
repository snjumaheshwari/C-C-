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


	 	vector<pair<int,int> > arr;
	 	pair<int,int> p;
    	for(int i=0;i<N;i++){
        	for(int j=0;j<M;j++){
        		if(Board[i][j]==1)
                	{
                		p.first=i;
                		p.second=i;
                		arr.push_back(p);
                	}
            }
        }
   


    int l=arr.size();

    for(int i=0;i<l;i++){
        for(int j=i+1; j<l;j++){
            int dis_x=abs(arr[i].first-arr[j].first);
            int dis_y= abs(arr[i].second-arr[j].second);
            answer[dis_y+dis_x]++;
   		 }
	}
 
      for(int i=1;i<=N+M-2;i++)
      	cout<<answer[i]<<" ";

      cout<<"\n";

	}
    
	
	return 0;

}

