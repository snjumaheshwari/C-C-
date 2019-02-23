#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph{

    unordered_map<T,list<T> > adj;


public:
    Graph(){

    }
    void addEdge(T u, T v, bool bidir=true){
        adj[u].push_back(v);
        if(bidir)
            adj[v].push_back(u);
    }

    void print(){
        for(auto p: adj){
            cout<<p.first<<" : ";
            for(auto i: adj[p.first]){
                cout<<i<<" , ";
            }
            cout<<endl;
        }
    }


    // Graph Traversal -- BFS

    void bfs(T root){

        queue<T> q;
        map<T,bool> visited;
        map<T,T> parent;
        map<T,int> dist;


        q.push(root);
        visited[root]=true;

        while(!q.empty()){
            T u=q.front();
            q.pop();
            cout<<u<<" ";

            for(auto v : adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);

                    parent[v]=u;
                    dist[v]=dist[u]+1;
                }
            }

        }

    }

    // Graph Traversal -- DFS

    void dfs(T src, map<T,bool> &visited){
        visited[src]=true;
        cout<<src<<" ";

        for(auto j: adj[src]){
            if(!visited[j]){
                dfs(j);
            }
        }
    }

    void dfsHelper(T src){
        map<T,bool> visited;
        dfs(src,visited);
    }

    // connected components using dfs

    void complete_dfs(T src){
        map<T,bool> visited;

        int comp=1;
        dfs(src,visited);

        for(auto u: adj){
            if(!visited[u.first]){
                dfs(u.first,visited);
                comp++;
            }
        }
        cout<<"Total No of components is"<<comp<<endl;
    }

    // Topological Sort Using DFS-- Works only on DAG

    // Directed acyclic graph




    void dfs_ts(T src,map<T,bool> &visited, list<T> &ordering){
        visited[src]=true;
        for(auto i:adj[src]){

            if(!visited[i]){
                dfs_ts(i,visited,ordering);
            }
        }
        ordering.push_front(src);
    }

    void dfs_ts_helper(){
        map<T,bool> visited;
        list<T> ordering;

        for(auto i: adj){
            T u= i.first;
            if(!visited[u]){
                dfs_ts(u,visited,ordering);
            }
        }

        for(auto i: ordering){
            cout<<i<<"-";
        }
    }

};



int main(){

    Graph<string> g;

    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic", "Java",false);
    g.addEdge("Programming Logic", "JS",false);
    g.addEdge("Python", "Web Dev",false);
    g.addEdge("HTML", "CSS",false);
    g.addEdge("CSS", "JS",false);
    g.addEdge("JS", "Web Dev",false);
    g.addEdge("Java", "Web Dev",false);
    g.addEdge("Python", "Web Dev",false);

    g.dfs_ts_helper();






    return 0;
}
