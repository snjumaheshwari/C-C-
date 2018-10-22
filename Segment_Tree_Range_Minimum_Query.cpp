#include<bits/stdc++.h>
#define ll long long
#define INF 1000000002
using namespace std;

/*
MIN QUERY-I

You are given an array A of n elements and Q queries. Each query can be of following types:

    1 L R: Print the minimum value in AL, AL+1, AL+2….,AR.
    2 X Y: Update the value of Ax with Y.

*/

void BuildTree(ll *arr, ll *Tree, int s, int e, int index)
{
	if(s==e)
	{
		Tree[index]=arr[s];
		return ;
	}

	int mid= (s+e)/2;
	BuildTree(arr,Tree,s, mid,2*index);
	BuildTree(arr,Tree,mid+1,e, 2*index+1);

	Tree[index]= min(Tree[2*index], Tree[2*index+1]);

}

ll Query(ll *Tree, int ss, int se, int qs, int qe, int index)
{

	// No overlap
	if(ss> qe || qs > se)
		return INF;

	// complete overlap
	if(ss>=qs && qe>= se)
		return Tree[index];

	int mid= (ss+se)/2;

	ll LeftAns= Query(Tree,ss,mid,qs,qe,2*index);
	ll RightAns=Query(Tree,mid+1,se,qs,qe,2*index+1);

	return min(LeftAns,RightAns);


}

void update(ll *Tree, int ss, int se, int i, ll val,int index)
{
	if(ss>i || i>se)
		return ;
	if(ss==se){
		Tree[index]=val;
		return;
	}

	int mid=(ss+se)/2;
	update(Tree,ss,mid,i,val,2*index);
	update(Tree,mid+1,se,i,val,2*index+1);

	Tree[index]= min( Tree[2*index],Tree[2*index+1]);

}
int main()
{

	int n,q; cin>>n>>q;

	ll arr[n+1];

	for(int i=1;i<=n;i++)
		cin>>arr[i];

	ll Tree[4*n+1]={0};
	BuildTree(arr, Tree, 1,n,1);

	/*for(int i=0;i<=9;i++)
		cout<<Tree[i]<< " ";
	*/
	ll a,b,c;
	while(q--)
	{
		cin>>a>>b>>c;
		if(a==1)
		{
			cout<<Query(Tree,1,n,b,c,1)<<endl;
		}
		else
		{
			update(Tree,1,n,b,c,1);
		}
	}

	return 0;
}