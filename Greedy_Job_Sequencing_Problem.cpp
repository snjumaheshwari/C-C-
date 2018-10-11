#include<bits/stdc++.h>
using namespace std;


bool comp(pair<int,int> a, pair<int, int> b)
{

	double x1=b.first *a.second;
	double x2= a.first *b.second;

	return x2>x1;
}

int main()
{
	int n,num;
	cin>>n;

	vector<int> L,R;

	for(int i=0;i<n;i++){
		cin>>num;
		L.push_back(num);
	}

	for(int i=0;i<n;i++)
	{
		cin>>num;
		R.push_back(num);
	}


	vector<pair<int,int> > J;

	pair<int,int> temp;

	for(int i=0;i<n;i++)
	{
		temp.first= L[i];
		temp.second=R[i];
		J.push_back(temp);
	} 

	stable_sort(J.begin(),J.end(),comp); // based on merge sort 
										// sort => intro sort => a version of quick sort..

	for(int i=0;i<n;i++)
	{
		temp=J[i];
		cout<<temp.first<<" "<<temp.second<<endl;

	}


	return 0;
}