
#include<bits/stdc++.h>
using namespace std;


class Graph{
    int N;
    vector<int> *adj;

public:
    Graph(int n){
        N=n;
        adj= new vector<int>[N];
    }

    void addEdge(int u,int v,bool bidir=true){
        adj[u].push_back(v);
        if(bidir)
            adj[v].push_back(u);
    }

    void print(){

        for(int i=0;i<N;i++){
            cout<<i<<" : ";
            for(auto j: adj[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    // Graph Traversal -- BFS

    void bfs(int root){

        bool *visited = new bool[N]{false};
        int *dist= new int[N];
        int *parent= new int[N];
        queue<int> q;

        q.push(root);
        visited[root]=true;
        parent[root]=-1;
        dist[root]=0;

        while(!q.empty()){

            int u= q.front();
            cout<<u<<" ";
            q.pop();

            for(auto v: adj[u]){

                if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                        parent[v]=u;
                        dist[v]=dist[u]+1;
                }
            }
        }
    }

    // Graph- Traversal DFS

    void dfs(int src, bool *visited){

        cout<<src<<" ";
        for(auto i:adj[src]){
            if(!visited[i]){
                visited[i]=true;
                dfs(i,visited);
            }
        }
    }
    void dfsHelper(int src){
        bool *visited= new bool[N]{0};
        visited[src]=true;
        dfs(src,visited);
    }

    // connected components using dfs

    void complete_dfs(int src){

        bool *visited= new bool[N]{0};
        int components=1;

        visited[src]=true;
        dfs(src,visited);
        cout<<endl;

        for(int i=0;i<N;i++){
            if(!visited[i]){
                visited[i]=true;
                dfs(i,visited);
                components++;
            }
        }
        cout<<"The number of components graph have "<<components<<endl;
    }


    //
};

int main(){


    Graph  g(7);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(5,6);

    g.print();
    g.bfs(0);
    cout<<endl;

    g.dfsHelper(0);
    cout<<endl;

    g.complete_dfs(0);

    return 0;
}
