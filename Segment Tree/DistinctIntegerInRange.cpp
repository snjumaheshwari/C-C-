#include<bits/stdc++.h>
using namespace std;

const int N= 100001;
bitset<5001> Tree[400005];

int arr[100001];


void buildTree(int index,int s,int e){

    //cout<<index<<" "<<s<<" "<<e<<" "<<endl;
    if(s==e){
        int pos= arr[s];
        Tree[index][pos] =1;
        return ;
    }
    int left= 1<<index;
    int mid= (s+e)>>1;

    buildTree(left,s,mid);
    buildTree(left+1,mid+1,e);

    Tree[index]= (Tree[left] | Tree[left+1]);


}

bitset<5001> zero;

bitset<5001> Query( int index,int s,int e,int qs,int qe){

    if(s> qe or qs > e){
        return zero;
    }

    if(qs<=s and  qe>= e){
        return Tree[index];
    }

    int left= 1<<index;
    int mid= (s+e)>>1;

    return Query(left,s,mid,qs,qe) | Query(left+1,mid+1,e,qs,qe);

}

bitset<5001> Tree2[400005];

int arr2[100001];

bitset<5001> Query2( int index,int s,int e,int qs,int qe){

    if(s> qe or qs > e){
        return zero;
    }

    if(qs<=s and  qe>= e){
        return Tree2[index];
    }

    int left= 1<<index;
    int mid= (s+e)>>1;

    return Query2(left,s,mid,qs,qe) | Query2(left+1,mid+1,e,qs,qe);

}


void buildTree2(int index,int s,int e){

    //cout<<index<<" "<<s<<" "<<e<<" "<<endl;
    if(s==e){
        int pos= arr[s];
        Tree2[index][pos] =1;
        return ;
    }
    int left= 1<<index;
    int mid= (s+e)>>1;

    buildTree2(left,s,mid);
    buildTree2(left+1,mid+1,e);

    Tree2[index]= (Tree2[left] | Tree2[left+1]);


}




int main(){

    int n; cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(1,0,n-1);

    for(int j=0;j<n;j++){
        cin>>arr2[j];
    }
    buildTree2(1,0,n-1);


    int q; cin>>q;
    bitset<5001> ans1,ans2;

    int x,y,c,d;
    while(q--){

        cin>>x>>y>>c>>d;
        ans1= Query(1,0,n-1,x,y);
        ans2=Query2(1,0,n-1,c,d);
        ans1=ans1 | ans2;
        cout<<ans1.count()<<" ";

    }


    return 0;


}
