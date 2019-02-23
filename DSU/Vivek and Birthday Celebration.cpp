#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define pf push_front
#define READ freopen("in.txt","r",stdin);
#define WRITE freopen("out.txt","w",stdout);
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MOD = int(1e9)+7;
const int MAX = int(1e5)+5;
const ll inf= int(1e18)+1;

using namespace std;

list<int> *adj;
list<int> *Tadj;

int n;

stack<int> s;


void dfsHelper(int node,bool* visited){
   // cout<<"dfs Helper\n";
        visited[node]=true;

        for(auto neib: adj[node]){
            if(!visited[neib]){
                 visited[neib]=true;
                dfsHelper(neib,visited);
            }
        }
        s.push(node);
}
void dfs(){
   // cout<<"DFs call\n";
    bool *visited= new bool[n]{false};
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfsHelper(i,visited);
        }
    }
}

void Transpose(){
        //cout<<"Transpose\n";
        Tadj= new list<int>[n];

        for(int i=0;i<n;i++){
            for(auto u: adj[i]){
                Tadj[u].push_back(i);
            }
        }


}

void dfs1(int node, bool *visited, int &count){
    count++;
    visited[node]=true;

    for(auto neib: Tadj[node]){
        if(!visited[neib])
            dfs1(neib,visited,count);
    }
}


void PrintSCC(){
    dfs();
    Transpose();
    int ans=n;

    bool *visited= new bool[n]{false};
    while(!s.empty()){
        int node= s.top();
        s.pop();
        if(!visited[node]){
            int count=0;
            dfs1(node,visited, count);
            ans= min(ans,count);
        }
    }
    cout<<ans;
}

int main(){
	//FAST; 
    
//    READ;WRITE;

   cin>>n;
    adj= new list<int>[n];

    int m; cin>>m;
    while(m--){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }
    PrintSCC();


return 0;
}
