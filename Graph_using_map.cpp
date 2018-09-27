#include<list>
#include<map>
#include<iostream>
#include<cstring>

using namespace std;

template< typename T>
class Graph{
    map<T,list<T>> adjList;

public:
    Graph()
    {
    }

    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);

    }
    void printGraph()
    {
        for( auto row : adjList)
        {
            T key =row.first;
            cout<<key<< " -> ";

            for (T node : row.second)
            {
                cout<<node<<" ";
            }
            cout<<"\n";
        }
    }
      void dfsHelper(T node, map<T,bool> &visited)
    {
            visited[node]=true;
            cout<< node <<" ";
            for( T neib : adjList[node])
            {
                if(! visited[neib])
                    dfsHelper(neib,visited);
            }
    }

    void dfs(T src)
    {
        map<T,bool> visited;
        cout<<"\nDFS :";

        dfsHelper(src,visited);


    }

};

int main()
{
    Graph<string> g;

    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","jaipur");
    g.addEdge("Delhi","Jalandhar");
    g.addEdge("Jodhpur","jaipur");
    g.addEdge("Delhi","banglore");
    g.addEdge("Jodhpur","Delhi");

    g.printGraph();
    g.dfs("Delhi");


}
