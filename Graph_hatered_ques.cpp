#include<list>
#include<iostream>
#include<queue>
#include<map>

using namespace std;


class Graph{
    int N;  // denotes no of vertices.. i,e. vertices are numbered 0 to N-1.

    list <int>*adjList;

    public:
    Graph(int n)
    {
        N=n;
        adjList= new list<int>[N];
    }

    void addEdge(int u, int v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }

    void printGraph()
    {
        for(int i=0;i<N;i++)
        {
            cout<<i<<" -> ";

            for (int node : adjList[i])
                cout<<node<<" , ";
            cout<<"\n";
        }
    }

    void dfsHelper(int node, map<int,bool> &visited,int &length)
    {
            visited[node]=true;
          //  cout<< node <<" ";
            length++;
            for( int neib : adjList[node])
            {
                if(! visited[neib])
                    dfsHelper(neib,visited,length);
            }
    }

    void dfs(int src)
    {
        map<int,bool> visited;
        cout<<"\nDFS :";
        int components=1;
        int length=0;
        int ans=1;

        dfsHelper(src,visited,length);
        cout<<"\n";
        ans*=length;
        for( int i=0;i<N;i++)
        {
            if( ! visited[i])
            {
                    int length=0;
                    dfsHelper(i,visited,length);
                    components++;
                    //cout<<length<<" ";
                    ans*=length;
            }
        }
        cout<<" components : "<<components;
    }

    void bfs(int src)
    {
        queue<int> q;

        bool *visited= new bool[N]{0};
        int *distance=new int[N]{0};
        int *parent=new int[N]{-1};

        q.push(src);
        visited[src]=true;


        while( ! q.empty())
        {
            int node= q.front();
            cout<<node <<" ";
            q.pop();

            for(int neib : adjList[node])
            {
                if(! visited[neib])
                {
                    visited[neib]=true;
                    distance[neib]=distance[node]+1;
                    parent[neib]=node;
                    q.push(neib);

                }
            }
        }

        cout<<"\n";
        // print the distances of each node from source ..
        for (int i=0;i <N;i++)
            cout<<i<<"node have distance "<<distance[i]<<endl;

        // shortest path...from src to destination...( calculate for all)


        for(int  dest=0; dest <N;dest++)
        {
            int temp =dest;
            while(temp!=-1)
            {
            cout<<temp<< " <--";
            temp=parent[temp];
            }
            cout<<endl;
        }
    }
};


int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(3,4);

    g.printGraph();



   // int a[]={1,2,3,4,5,6};

    //for(int i: a)
      //  cout<<i<<" ";

    g.bfs(0);
    g.dfs(0);

    return 0;
}
