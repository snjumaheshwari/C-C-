#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define mp make_pair
#define pb push_back
#define p(k) printf("%d ",k)
#define pl(k) printf("%lld ",k)
#define pn(k) printf("%d\n",k)
#define pln(k) printf("%lld\n",k)
#define ps(str) printf("%s",str)
#define s(k) scanf("%d",&k)
#define sl(k) scanf("%lld",&k)
#define ss(str) scanf("%s",str)
#define ft first
#define sd second

using namespace std;

int main(){
	ll t,n,i,k,count,sum,x,k1,ind,ans;
	sl(t);
	while(t--){
		sl(n);sl(k);sl(x);
		set<ll>s;
		set<ll>:: iterator it;
		for(i=0;i<k;i++){
			sl(k1);
			s.insert(k1);
		}
		count=(*s.begin())+x;
		k1=count-n+1;
		ind=0;
		sum=0;
		for(it=s.begin();it!=s.end();it++){
			if(*it<k1) {ind++;k1++;}
			else break;
			sum+=*it;
		}
		// k1+=ind;
		k1--;
		ans=(count*(count+1))/2-(k1*(k1+1))/2+sum;
		pln(ans);
	}
	return 0;
}


