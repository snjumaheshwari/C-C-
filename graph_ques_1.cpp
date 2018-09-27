#include<bits/stdc++.h>
using namespace std;
class Graph{
  int N;
  list<int> *adjlist;

  public:
  Graph(int n)
  {
    N=n;
    adjlist= new list<int>[N+1];
  }

  void addEdge(int u, int v)
  {
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }
  void printGraph()
  {
    for (int i=1;i<=N;i++)
    {
        cout<<i<<" ";
        for (int j : adjlist[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
  }

  void bfs(int src)
  {
      int *distance= new int[N+1];
      bool *visited=new bool[N+1]{0};

        for(int i=0;i<=N;i++)
            distance[i]=-1;

        queue<int>q;
        q.push(src);

        distance[src]=0;
        visited[src]=true;

        while(! q.empty())
        {
            int node=q.front();
            q.pop();

            for( int i: adjlist[node])
            {
                if(! visited[i])
                {
                    visited[i]=true;
                    distance[i]=distance[node]+6;
                    q.push(i);
                }
            }

        }
        for(int i=1;i<=N;i++)
        {
            if(i!=src)
                cout<<distance[i]<<" ";
        }
  }

};
int main() {

    int test;
    cin>>test;

    while(test--)
    {
        int n;
        long long m;
        int u,v,src;
        cin>>n>>m;

        Graph g(n);
        for (long long i=0;i<m;i++)
        {
            cin>>u>>v;
            g.addEdge(u,v);
        }
            cin>> src;
            g.bfs(src);


    }




	return 0;
}
