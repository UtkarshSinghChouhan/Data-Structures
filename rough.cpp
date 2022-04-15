#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int numNode;
    vector<int> *adjList;
    void dfsRec(int node, vector<int> &vis, vector<int> &storeDfs);
public:
    Graph(int numNode);//
    void addEdge(int src, int des);//
    vector<int> bfsOfGraph();
    vector<int> dfsOfGraph();
    void print();//
};

Graph :: Graph(int numNode)
{
    this->numNode = numNode;
    adjList = new vector<int>[numNode + 1];
}

void Graph :: addEdge(int src, int des)
{
    adjList[src].push_back(des);
    adjList[des].push_back(src);
}

vector<int> Graph :: bfsOfGraph()
{
    vector<int> storeBfs;
    vector<int> vis(numNode + 1, 0);

    for(int i = 1; i <= numNode; i++)
    {
        if(vis[i] == 0 )
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
             while(q.empty() == false)
             {
                 
             }

        }
    }
}


//Funcion to print the adjacency-List of the graph
void Graph :: print()
{
    for(int i = 0; i < (numNode + 1); i++)
    {
        for(int j : adjList[i])
        {
            cout << j <<" ";
        }
    }
}

int main()
{
    
    return 0;
}