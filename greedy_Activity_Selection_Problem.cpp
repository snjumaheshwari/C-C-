#include<bits/stdc++.h>
#define ll long long

using namespace std;
/*

void print(auto v)
{

	for(auto it: v)
	{
		cout<<it<<" ";
	}
	cout<<endl;
}
*/

bool comp(pair<int,int> p1 , pair<int,int> p2)
{
	return p1.second< p2.second;
}


int main()
{
	vector<pair<int,int> > activity;

	int n; cin>>n;

	pair<int , int> p;

	for(int i=0;i<n;i++){

		cin>> p.first>> p.second;
		activity.push_back(p);
	}
	

	sort(activity.begin(), activity.end(),comp);


}