
#include<bits/stdc++.h>
using namespace std;


const int N= 500005;
#define INT_MIN -100000

int arr[N];
struct node{
    int ts;
    int ps;
    int ss;
    int ms;
};
node Tree[4*N+1];
// 0- Total sum
// 1- PS
// 2- SS
// 3- MS


void BuildTree(int index,int s,int e){
    //cout<<index<<" "<<s<<" "<<e<<endl;
    if(s==e){
        Tree[index].ts= arr[s];
        Tree[index].ps=arr[s];
        Tree[index].ss= arr[s];
        Tree[index].ms= arr[s];

        return;
    }

    int left= 2*index;
    int mid= (s+e)/2;
    BuildTree(left,s,mid);
    BuildTree(left+1,mid+1,e);

    Tree[index].ts= Tree[left].ts+ Tree[left+1].ts;
    Tree[index].ps= max(Tree[left].ps , Tree[left].ts+ Tree[left+1].ps);
    Tree[index].ss= max(Tree[left+1].ss, Tree[left+1].ts+ Tree[left].ss);
    Tree[index].ms= max(max(Tree[left].ms,Tree[left+1].ms),Tree[left].ss+ Tree[left+1].ps);
}

node query(int index,int s,int e, int qs,int qe){
    //cout<<s<<" "<<e<<"\n";
    if( s>qe or e <qs){
        return ((node){INT_MIN,INT_MIN,INT_MIN,INT_MIN});
    }
    else if( qs<=s and qe>=e){
        return Tree[index];
    }

    int left= 2*index;
    int mid= (s+e)/2;

    node leftans= query(left,s,mid,qs,qe);
    node rightans= query(left+1,mid+1,e,qs,qe);

    node ans;
    ans.ts= leftans.ts+ rightans.ts;
    ans.ps= max(leftans.ps, leftans.ts+ rightans.ps);
    ans.ss= max(rightans.ss, rightans.ts+ leftans.ss);
    ans.ms= max(max(leftans.ms,rightans.ms), leftans.ss +rightans.ps);

    return ans;


}
int main(){

        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n; cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];

        }
        BuildTree(1,1,n);

        int q; cin>>q;

        while(q--){
            int qs,qe; cin>>qs>>qe;

            node ans1= query(1,1,n,qs,qe);
            cout<<ans1.ms<<endl;
        }

}
