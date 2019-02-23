/*

	AC after 2 WA - ltime10 codechef
	1. local value of n=5
	2. not updating every thing in structure

*/

#include<bits/stdc++.h>
using namespace std;

const int MAX= int(1e5)+5;
int arr[MAX+1];

const int inf= int(1e6);
struct node{
	int maxLength;
	int leftMostValue;
	int rightMostValue;
	int maxLengthPrefix;
	int maxLengthSuffix;
	int totalLength;
};

struct node Tree[4*MAX+5];

void BuildTree(int index,int s,int e){
	if(s==e){
		Tree[index].maxLength=1;
		Tree[index].leftMostValue=arr[s];
		Tree[index].rightMostValue= arr[s];
		Tree[index].maxLengthSuffix=1;
		Tree[index].maxLengthPrefix=1;
		Tree[index].totalLength=1;
		return ;
	}

	int mid=(s+e)/2;
	int left= 2*index;
	BuildTree(left,s,mid);
	BuildTree(left+1,mid+1,e);


	// if after combining they are forming AP
	if(Tree[left+1].leftMostValue -Tree[left].rightMostValue==1){
		Tree[index].leftMostValue= Tree[left].leftMostValue;
		Tree[index].rightMostValue= Tree[left+1].rightMostValue;

		Tree[index].maxLength= max(Tree[left].maxLength,max(Tree[left+1].maxLength,
									Tree[left].maxLengthSuffix+ Tree[left+1].maxLengthPrefix
										));

		if(Tree[left].totalLength== Tree[left].maxLength){
			Tree[index].maxLengthPrefix= Tree[left].maxLength + Tree[left+1].maxLengthPrefix;
		}
		else{
			Tree[index].maxLengthPrefix= Tree[left].maxLengthPrefix;
		}

		if(Tree[left+1].totalLength== Tree[left+1].maxLength){
			Tree[index].maxLengthSuffix= Tree[left+1].maxLength + Tree[left].maxLengthSuffix;
		}
		else{
			Tree[index].maxLengthSuffix= Tree[left+1].maxLengthSuffix;
		}
		Tree[index].totalLength= Tree[left].totalLength+ Tree[left+1].totalLength;
	}
	// else
	else{
		Tree[index].leftMostValue= Tree[left].leftMostValue;
		Tree[index].rightMostValue= Tree[left+1].rightMostValue;
		Tree[index].maxLengthPrefix= Tree[left].maxLengthPrefix;
		Tree[index].maxLengthSuffix= Tree[left+1].maxLengthSuffix;
		Tree[index].totalLength= Tree[left].totalLength+ Tree[left+1].totalLength;
		Tree[index].maxLength= max(Tree[left].maxLength, Tree[left+1].maxLength);
	}
}

node query(int qs,int qe,int s,int e,int index){
		return  Tree[index];

}


void update(int index,int s,int e, int pos, int val){

	if(pos<s or pos > e){
		return ;
	}
	if(s==e){

		Tree[index].maxLength=1;
		Tree[index].leftMostValue=val;
		Tree[index].rightMostValue= val;
		Tree[index].maxLengthSuffix=1;
		Tree[index].maxLengthPrefix=1;
		Tree[index].totalLength=1;
		return;
	}

	int mid=(s+e)/2;
	int left= 2*index;
	update(left,s,mid,pos,val);
	update(left+1,mid+1,e,pos,val);


	// if after combining they are forming AP
	if(Tree[left+1].leftMostValue -Tree[left].rightMostValue==1){
		Tree[index].leftMostValue= Tree[left].leftMostValue;
		Tree[index].rightMostValue= Tree[left+1].rightMostValue;
		Tree[index].totalLength= Tree[left].totalLength+ Tree[left+1].totalLength;

		Tree[index].maxLength= max(Tree[left].maxLength,max(Tree[left+1].maxLength,
									Tree[left].maxLengthSuffix+ Tree[left+1].maxLengthPrefix
										));

		if(Tree[left].totalLength== Tree[left].maxLength){
			Tree[index].maxLengthPrefix= Tree[left].maxLength + Tree[left+1].maxLengthPrefix;
		}
		else{
			Tree[index].maxLengthPrefix= Tree[left].maxLengthPrefix;
		}

		if(Tree[left+1].totalLength== Tree[left+1].maxLength){
			Tree[index].maxLengthSuffix= Tree[left+1].maxLength + Tree[left].maxLengthSuffix;
		}
		else{
			Tree[index].maxLengthSuffix= Tree[left+1].maxLengthSuffix;
		}
	}
	else{
	Tree[index].leftMostValue= Tree[left].leftMostValue;
	Tree[index].rightMostValue= Tree[left+1].rightMostValue;
	Tree[index].maxLengthPrefix= Tree[left].maxLengthPrefix;
	Tree[index].maxLengthSuffix= Tree[left+1].maxLengthSuffix;
	Tree[index].totalLength= Tree[left].totalLength+ Tree[left+1].totalLength;
	Tree[index].maxLength= max(Tree[left].maxLength, Tree[left+1].maxLength);
}

}
int main(){

	int n,m; cin>>n>>m;

	

	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	BuildTree(1,1,n);


	cout<<query(1,n,1,n,1).maxLength<<endl;	

	while(m--){
		int x,y; cin>>x>>y;
		update(1,1,n,x,y);
		cout<<query(1,n,1,n,1).maxLength<<endl;

	}


	return 0;
}