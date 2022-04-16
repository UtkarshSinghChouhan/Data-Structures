#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int numNode;            //represents the no. of nodes in the graph
    vector<int> *adjList;

public:
    Graph(int numNode);

    void addEdge(int src, int des);

    void print();

    bool checkCycle();
    bool checkCycleUtils(int node,int pre, vector<int> &vis, vector<int> adjList[]);
};


Graph :: Graph(int numNode)
{
    this->numNode = numNode;
    adjList = new vector<int>[numNode + 1];         //as soon as we will be given the number of nodes(i.e. numNode) in the graph the adjacency-list of size (numNode+1) will be created
}

bool Graph :: checkCycleUtils(int node,int pre, vector<int> &vis, vector<int> adjList[])
{
   vis[node] = 1;

   for(int adjNode : adjList[node])
   {
       if(vis[adjNode] == 0)
       {
           if(checkCycleUtils(adjNode,node,vis,adjList) == true)
           {
               return true;
           }
       }

       else if(adjNode != pre)
       {
           return true;
       }
   }
   return false;
}


bool Graph :: checkCycle()
{
    vector<int> vis(numNode + 1, 0);

    for(int i = 1; i <= numNode; i++)
    {
        if(vis[i] == 0)
        {
            if(checkCycleUtils(i,-1, vis, adjList) == true)
            {
                return true;
            }
        }
    }
    return false;
}



void Graph :: addEdge(int src, int des)
{
    adjList[src].push_back(des);
    adjList[des].push_back(src);
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
        cout<<endl;
    }
}







int main()
{
    Graph g(3);

    //Component C1 of the graph
    g.addEdge(1,2);
    g.addEdge(2,3);

    // //Component C2 of the graph
    // g.addEdge(3,5);
    // g.addEdge(5,10);
    // g.addEdge(5,6);
    // g.addEdge(6,7);
    // g.addEdge(10,9);
    // g.addEdge(7,8);
    // g.addEdge(9,8);
    // g.addEdge(8,11);


    g.print();

    if(g.checkCycle())
    {
        cout<<"Cycle exists"<<endl;
    }

    else{
        cout<<"Cycle do not exists"<<endl;
    }


    return 0;
}