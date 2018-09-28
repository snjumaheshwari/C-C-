#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


/*
	Rules :
	1. You can't place a bigger disk over a smaller disk..
	2. Pick One Disk at a time.

*/

void towerOfHonoi(int n, char src, char dest,char helper)
{
	if(n==0)
		return ;
	towerOfHonoi(n-1,src,helper,dest);
	cout<<"Move "<<n<<" th disk from "<< src<<" to "<<helper<<"\n";
	towerOfHonoi(n-1,helper,dest,src);
}
int main()
{
	int n;
	cin>>n;
	towerOfHonoi(n,'A','C','B');

}