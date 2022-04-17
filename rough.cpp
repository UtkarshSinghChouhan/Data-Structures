#include<bits/stdc++.h>
using namespace std;

void topoSortDfs(int node, vector<int> &vis, vector<int> adjList[], stack<int> &s)
{
    vis[node] = 1;

    for(int adjNode : adjList[node])
    {
        if(vis[adjNode] == 0){
            topoSortDfs(adjNode, vis, adjList, s);
        }
    }

    s.push(node);
}

vector<int> topoSort(vector<int> adjList[], int numNodes)
{
    stack<int> s;
    vector<int> vis(numNodes, 0);

    for(int i = 0; i < numNodes; i++)
    {
        if(vis[i] == 0)
        {
            topoSortDfs(i, vis, adjList, s);
        }
    }

    vector<int> topoSortValue;

    while(s.empty() == false)
    {
        int value = s.top();
        topoSortValue.push_back(value);
        s.pop();
    }

    return topoSortValue;
}

int main()
{
    int n, m;       //n - no. of vertices or nodes
    cin >> n >> m;  //m - no. of edges

    //declaring the adjacency list
    vector<int> adjList[n+1];

    //taking edges as input and storing it in the adjacency list
    for(int i = 0; i<m; i++)
    {
        int u, v;            //u and v represents the end vertices of any edge
        cin >> u >> v;

        adjList[u].push_back(v);
    }

    for(int &value : topoSort(adjList, n))
    {
        cout << value <<" ";
    }
    cout<<endl;


    return 0;
}