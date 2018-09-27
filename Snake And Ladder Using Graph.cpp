#include<list>
#include<iostream>
#include<queue>

using namespace std;

class Graph{
    int N;
     // denotes no of vertices.. i,e. vertices are numbered 0 to N-1.
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

    void bfs(int src,int dest)
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

        // shortest path...from src to destination..
            cout<<"Shortest Distance : "<<distance[dest]<<"\n";
            int temp =dest;
            while(temp!=-1)
            {
            cout<<temp<< " <--";
            temp=parent[temp];
            }
            cout<<endl;

    }
};


int main()
{
    Graph g(50);
    int Board[50]={0};

    Board[2]=13;
    Board[5]=2;
    Board[9]=18;
    Board[18]=11;
    Board[17]=-13;
    Board[20]=-14;
    Board[24]=-8;
    Board[25]=-10;
    Board[32]=-2;
    Board[34]=-22;

    for(int u=0;u<36;u++)
    {
        for(int d=1;d<=6;d++)
        {
            int v= u + d+ Board[u+d];
            g.addEdge(u,v,false);
        }
    }
   g.bfs(0,36);

    return 0;
}
// 995
