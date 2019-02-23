#include<bits/stdc++.h>
using namespace std;


void PostOrder(int *in, int *pre,int n){
	if(n==0)
		return;
	int root= pre[0];
	int i= find_index(in,root,n);
	PostOrder(in, pre+1,i);
	PostOrder(in+i+1,pre+i+1,n-i-1);
	cout<<root<<" ";
}

int main(){

	int in[]={4,2,5,1,3,6};
	int pre[]={1,2,4,5,3,6};

	int n= sizeof(in)/ sizeof(in[0]);


	cout<<"PostOrder Traversal :\n" ;
	PostOrder(in,pre,n);
	return 0;
} 