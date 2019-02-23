
#include<bits/stdc++.h>
using namespace std;

const long N=100005;

vector<long> Tree[4*N+1];

long arr[N];
void buildTree(long index,long s,long e){

    if(s==e){
        Tree[index].push_back(arr[s]);
        return ;
    }
    long mid= (s+e)/2;
    buildTree(2*index,s,mid);
    buildTree(2*index+1,mid+1,e);

    Tree[index].resize( Tree[2*index].size() + Tree[2*index+1].size());
    merge(Tree[2*index].begin(), Tree[2*index].end()  , Tree[2*index+1].begin(), Tree[2*index+1].end(), Tree[index].begin());
}

vector<long> query(long index, long s,long e,long qs,long qe){

   // cout<<index<<" "<<s<<" "<<e<<" "<<endl;
    if(qe<s or qs >e){
        vector<long> v;
        return v;
    }
    if(qs<= s and qe >= e){
        return Tree[index];
    }

    long mid= (s+e)/2;
    vector<long> leftans= query(2*index,s,mid,qs,qe);
    vector<long> rightans= query(2*index+1,mid+1,e,qs,qe);

    vector<long> ans;
    ans.resize( leftans.size() + rightans.size());
    merge(leftans.begin(),leftans.end(),rightans.begin(),rightans.end(),ans.begin());
    return ans;
}


void update(long index,long s,long e,long i,long val){

    if(i<s or i> e){
        return;
    }
    if(s==e){
        vector<long> a;
        a.push_back(val);
        Tree[index]=a;
        return ;
    }

    long mid=(s+e)/2;
    long left= 2*index;
    update(left,s,mid,i,val);
    update(left+1,mid+1,e,i,val);

    Tree[index].resize( Tree[2*index].size() + Tree[2*index+1].size());
    merge(Tree[2*index].begin(), Tree[2*index].end()  , Tree[2*index+1].begin(), Tree[2*index+1].end(), Tree[index].begin());

}

int main(){

    long n,x,y,z,q; cin>>n>>q;

    for(long i=1;i<=n;i++){
        cin>>arr[i];
    }
    buildTree(1,1,n);

    while(q--){
        cin>>x>>y>>z;
        if(x==1){
            update(1,1,n,y,z);
        }
        else{
                bool flag=true;
            vector<long> ans=query(1,1,n,y,z);

            for(auto i=ans.size()-1;i >=2;i--){

            if(ans[i] < ans[i-1]+ ans[i-2]){
               // cout<<ans[i]<<" "<<ans[i-1]<<" "<<ans[i-2]<<endl;
                cout<<ans[i]+ans[i-1]+ans[i-2]<<endl;
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<0<<endl;
        }
    }
    }

    return 0;
}
