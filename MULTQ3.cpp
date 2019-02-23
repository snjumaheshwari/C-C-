#include<iostream>
#define MAX 100002
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int arr[MAX]={0};
int Tree[4*MAX+1]={0};

void BuildTree(int ss, int se, int index)
{
	if(ss== se)
	{
		if(arr[se]%3==0){
			Tree[index]=1;
			arr[se]=0;
		}
		else
			Tree[index]=0;
		return;
	}

	int mid= (ss+se)>>1;
	int left =index<<1;
	BuildTree(ss,mid,left);
	BuildTree(mid+1,se,left+1);
	Tree[index]=Tree[left]+ Tree[left+1];

}


int query(int ss, int se,int qs, int qe, int index)
{

	// No overlap--
	if(ss> qe || qs > se )
		return 0;

	if(qe>= se && ss>= qs)
		return Tree[index];

	// partial overlap..
	int mid= (ss+se)>>1;
	int left = index<<1;
	int leftans=query(ss,mid,qs,qe,left);
	int rightans=query(mid+1,se,qs,qe, left+1);
	return leftans+rightans;
}


void update(int ss, int se, int l, int r, int index)
{
	// no overlap..

	// No overlap--
	if(ss> r|| l > se )
		return ;

	if(ss==se)
	{
		arr[se]++;
		if(arr[se]%3==0){
			arr[se]=0;
			Tree[index]=1;
		}
		else
			Tree[index]=0;
		return ;
	}
	int mid= (ss+se)>>1;
	int left=index<<1;
	update(ss,mid,l,r,left);
	update(mid+1,se,l,r,left+1);

	Tree[index]= Tree[left]+ Tree[left+1];

}


int main()
{
	Done;

	ll n,q; cin>>n>>q;

	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}
	BuildTree(0,n-1,1);
	int a,b,c;

	while(q--)
	{
		cin>>a>>b>>c;
		if(a==0)
			update(0,n-1,b,c,1);
		else
			cout<<query(0,n-1,b,c,1)<<endl;


	}

	return 0;
}


