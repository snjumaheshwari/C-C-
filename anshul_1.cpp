#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
void sum(int*p, int n, vector<int> &d)
{
	int i;
	*p = 0;
	for(i = 0; i < n; ++i)
		*p = *p + d[i];


}
int main()
{
	int i;
	int N=40;
	int vaccum = 0;
	vector<int> data;
	for(i = 0; i < N; ++i)
	{
		data.push_back(i);
	}
	sum(  &vaccum , N, data);
	cout<<"\n sum is"<<vaccum;
	return 0;
}
