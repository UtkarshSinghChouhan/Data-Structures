<a href = "#01">Program 01 - Graph Representation as an Adjacency Matrix</a> <br>
<a href = "#02">Program 02 - Graph Representation as an Adjacency List</a> <br>
<a href = "#03">Program 03 - Graph Implementations</a> <br>

<h2 id = "01">Program 01 - Graph Representation as an Adjacency Matrix</h2>

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;        //n - no. of vertices
    cin >> n >> m;  //m - no. of edges 
    

    //declaring the adjacency matrix
    int adj[n+1][n+1];

    //taking edges as input
    for(int i = 0; i<m; i++)
    {
        int u,v;     //u and v represents the end vertices of any edge
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}


// 1----2
// |\   | \
// | \  |  4
// |  \ | /
// 5----3
```
<h2 id = "02">Program 02 - Graph Representation as an Adjacency List</h2>

```cpp
//Case_01 - Undirected Graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;           //n - no. of vertices
    cin >> n >> m;      //m - no. of edges

    //declaring the adjacency list
    vector<int> adj[n+1];           //'array of vector' - each element of this array is a vector.

    //taking edges as input and storing it in the adjacency list
    for(int i = 0; i<m; i++)
    {
        int u, v;           //u and v represents the end vertices of any edge
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}




//Case_02 Directed graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;       //n - no. of vertices
    cin >> n >> m;  //m - no. of edges

    //declaring the adjacency list
    vector<int> adj[n+1];

    //taking edges as input and storing it in the adjacency list
    for(int i = 0; i<m; i++)
    {
        int u, v;            //u and v represents the end vertices of any edge
        cin >> u >> v;

        adj[u].push_back(v);
    }
    return 0;
}





//Case_03 Weighted Undirected graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;           //n - no. of vertices
    cin >> n >> m;      //m - no. of edges

    vector<pair<int,int>> adj[n+1];

    //taking edges and its weight as input and storing it in the adjacency list
    for(int i = 0; i<m; i++)
    {
        int u, v, wt;       //u and v represents the end vertices of any edge and wt represent the weight of that edge.
        cin >> u >> v >>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    return 0;
}
```


<h2 id = "03">Program 03 - Graph Implementations</h2>

```cpp
#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int numNode;
    vector<int> *adjList;
    void dfsUtilis(int node, vector<int> &vis, vector<int> &storeDfs);

public:
    Graph(int numNode);

    void addEdge(int src, int des);

    vector<int> bfsOfGraph();

    vector<int> dfsOfGraph();

    void print();
};


Graph :: Graph(int numNode)
{
    this->numNode = numNode;
    adjList = new vector<int>[numNode + 1];         //as soon as we will be given the number of nodes(i.e. numNode) in the graph the adjacency-list of size (numNode+1) will be created
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
                int node  = q.front();
                q.pop();
                storeBfs.push_back(node);

                for(int adjNode : adjList[node])
                {
                    if(vis[adjNode] == 0)
                    {
                        q.push(adjNode);
                        vis[adjNode] = 1;
                    }
                }
            }

        }
    }

    return storeBfs;
}

void Graph :: dfsUtilis(int node, vector<int> &vis, vector<int> &storeDfs)
{    
    //Base Condition
    if(vis[value] == 0)
    {
        return;
    }

    // Induction step
    storeDfs.push_back(node);
    vis[node] = 1;

    //Hypothesis(call for smaller input)
    for(int value : adjList[node])
    {       
            dfsUtilis(value,  vis, storeDfs);
    }
}


vector<int> Graph :: dfsOfGraph()
{
    vector<int> storeDfs;
    vector<int> vis(numNode + 1, 0);

    for(int i = 1; i <= numNode; i++)
    {
        if(vis[i] == 0)
        {
            dfsUtilis(i, vis, storeDfs);
        }
    }

    return storeDfs;
}



int main()
{
    Graph g(7);

    //Component C1 of the graph
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,7);
    g.addEdge(7,5);
    g.addEdge(5,3);

    //Component C2 of the graph
    g.addEdge(4,6);


    g.print();


    //Printing the Bfs of the graph.
    for(int value : g.bfsOfGraph())
    {
        cout << value << " ";
    }
    cout<<endl;


    //Printing the Dfs of the graph.
    for(int value : g.dfsOfGraph())
    {
        cout << value << " ";
    }
    cout<<endl;


    return 0;
}
```