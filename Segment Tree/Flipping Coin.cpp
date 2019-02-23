#include<bits/stdc++.h>
#define ll long long

const int mod= int(1e9)+7;

using namespace std;

const int N= 1000005;
int tree[4*N];
int lazy[4*N];


void updateRange(int index,int s,int e, int l, int r){

	if(lazy[index]!=0){
		tree[index]=(e-s+1)- tree[index];

		if(s!=e){
			lazy[2*index]= 1-lazy[2*index];
			lazy[2*index+1]= 1- lazy[2*index+1];
		}
		lazy[index]=0;
	}

	if( s>r or l>e){
		return ;
	}

	if(s >=l and r >=e){
		tree[index]= ( e-s+1) - tree[index];
		if(s!=e){
			lazy[2*index]= 1-lazy[2*index];
			lazy[2*index+1]= 1-lazy[2*index+1];
		}

		return ;
	}

	int mid=(s+e)/2;
	updateRange(2*index,s,mid,l,r);
	updateRange(2*index+1,mid+1,e,l,r);
	tree[index]=tree[2*index]+ tree[2*index+1];
}
int query(int index,int s,int e,int qs,int qe){

	if(lazy[index]!=0){
		tree[index]=(e-s+1)- tree[index];

		if(s!=e){
			lazy[2*index]= 1-lazy[2*index];
			lazy[2*index+1]= 1- lazy[2*index+1];
		}
		lazy[index]=0;
	}

	if(s> qe or qs > e){
		return 0;
	}

	if( s>=qs and qe >=e){
		return tree[index];
	}

	int mid= (s+e)/2;

	int leftans=query(2*index,s, mid,qs,qe);
	int rightans= query(2*index+1,mid+1,e,qs,qe);

	return leftans+rightans;
}

int main(){


	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /*#ifndef ONLINE_JUDGE
    	freopen("in.txt","r",stdin);
    	freopen("out.txt","w",stdout);
    #endif // ONLINE_JUDGE


	*/
	int n,m; cin>>n>>m;


	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(tree));

	while(m--){

		int x,y,z; cin>>x>>y>>z;

		if(x==1){
			cout<<query(1,0,n-1,y,z)<<endl;
		}

		else{
			updateRange(1,0,n-1,y,z);
			/*cout<<"Segment Tree : ";
			for(int i=1;i<=10;i++){
				cout<<tree[i]<<" ";
			}
			cout<<"\nLazy Tree    : ";
			for(int i=1;i<=10;i++){
				cout<<lazy[i]<<" ";
			}
			*/
		}

	}




	return 0;

}
