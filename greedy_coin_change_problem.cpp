#include<bits/stdc++.h>
using namespace std;



int main()
{

	int n;
	cin>>n;

	int coins[n];
	for(int i=0;i<n;i++)
		cin>>coins[i];

	sort(coins,coins+n,greater<int>());

	cout<<"array after sorting is :"<<endl;

	for(int i=0;i<n;i++)
		cout<<coins[i]<<" ";

	int cost;
	cout<<endl<<"enter cost :";
	cin>>cost;

	int i=0;
	int no_of_coins=0;

	while(coins>0 && i<n)
	{

		if(coins[i]> cost){
			i++;
			continue;
		}
		else{

			cost=cost-coins[i];
			no_of_coins++;
			cout<<coins[i]<< " ";
		}

	}
	cout<<endl<<" No of coins required "<<no_of_coins;




}