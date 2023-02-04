#include <bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &component, int node)
{

    // storing the ans
    component.push_back(node);
    // mark visited
    visited[node] = 1;

    // har connected node ke liye recursive call
    for (auto it : adjlist[node])
    {
        if (!visited[it])
        {
            DFS(adjlist, visited, component, it);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //    prepare List for the graph

    unordered_map<int, list<int>> adjlist;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            // it gives answer of one component of disconnected graph
            DFS(adjlist, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> edge = {{5, 4}, {0, 2}, {0, 1}, {1, 2}, {3, 4}};

    int n = edge.size();

    vector<vector<int>> ans;
    ans = depthFirstSearch(n, n, edge);

    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}