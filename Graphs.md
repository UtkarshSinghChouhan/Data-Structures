<a href = "#01">Program 01 - Graph Representation as an Adjacency Matrix</a> <br>
<a href = "#02">Program 02 - Graph Representation as an Adjacency List</a> <br>

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