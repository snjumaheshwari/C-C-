#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;

void subsequence(char *arr, char* ans,int i, int j)
{
	// Base Case
	if(arr[i]=='\0')
	{
		ans[j]='\0';
		cout<<ans<<"\n";
		return ;
	}

	// Recursive Case
	// 1. Include the current character..
	ans[j]=arr[i];

	subsequence(arr,ans,i+1,j+1);
	subsequence(arr,ans,i+1,j);
}


void subseq(char *arr, char* ans,int i, int j)
{
	// Base Case
	if(arr[i]=='\0')
	{
		ans[j]='\0';
		cout<<ans<<"\n";
		return ;
	}

	subsequence(arr,ans,i+1,j);
	ans[j]=arr[i];
	subsequence(arr,ans,i+1,j+1);
}


int main()
{
	int n;
	cin>>n;

	c...................+
	char ans[3];

	subsequence(arr)

}