#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f     first
#define s     second
#define eb     emplace_back
#define mp     make_pair
#define pii    pair<int, int>
#define vi     vector<int>
#define vs     vector<string>
#define vpii   vector<pii>
#define sti    stack<int>
#define qui    queue<int>
#define pqi    priority_queue<int>
#define minheap  priority_queue < int , vector<int> , greater<int> >
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define SZ(x)  ((int)(x.size()))
#define FOR(i,n)    for(auto (i)=0; i<n; i++)
#define FORI(i,n)   for(auto (i)=1; (i)<=(n); (i)++)
#define in(x,y)     ((y).find((x))!=(y).end())
#define all(t)      t.begin(), t.end()
#define loop(i,a,b) for( auto (i)=(a); (i)<=(b); i++)
#define loopr(i,a,b) for( int (i)=a; (i)>=(b); i-- )
#define rmax(a,b)   (a)=max((a),(b));
#define rmin(a,b)   (a)=min((a),(b));
#define nl "\n"
#define print(x) cout<<x
#define prints(x) cout<<x<<" "
#define printn(x) cout<<x<<nl
#define newl cout<<nl
#define ull unsigned long long
#define ll  long long
#define MAX INT_MAX
ll const M = 1000000007;
using namespace std;
ll dp[1<<11 +1][101];
int all;
vector<int> v[101];
void initialise()
{
	for(int i=0; i<=100; i++)
	  v[i].clear();

    for(int i=0; i<= 1<<11; i++)
    {
      for(int j=0; j<101; j++)
        dp[i][j]=-1;
    }
}

ll calc(ll mask, int tid, int n)
{
	int a = __builtin_popcount(mask);
	if(a==n)
	return 1;

	if(tid>100)
	return 0;

	if(dp[mask][tid]!=-1)
	  return dp[mask][tid];

    ll ans =0;
    int len = v[tid].size();

    for(int i=0; i<len; i++)
    {
     a = v[tid][i];  // a is a person
      if( (mask & (1<<a)) == 0)
        {
          ans+=calc( (mask|(1<<a)), tid+1, n);
          ans%=M;
        }
    }
    ans+=calc(mask, tid+1, n);
    ans%=M;
    dp[mask][tid]=ans;

    return ans;
}
int main()
{
  // Happy Coding :)
  _
     int t;
     cin>>t;

     while(t--)
     {
        int n;
        cin>>n;

        initialise();
        string s;

          cin.get();
        for(int i=1; i<=n; i++)
        {
          getline(cin, s);
          stringstream nidhi (s);
          string temp;
          while(nidhi>>temp)
          v[stoi(temp)].push_back(i);

        }

       for(int i=1; i<=100; i++)
       {
         if(v[i].size()!=0)
          {
             sort(v[i].begin(), v[i].end());
          /* cout<<i<<" -> ";

            for(auto p: v[i])
             cout<<p<<" ";
              newl;*/
          }
       }
       cout<<calc(0, 1, n);
       newl;

     }
}




