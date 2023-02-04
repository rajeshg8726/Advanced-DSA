#include <bits/stdc++.h>
using namespace std;

void Creategraph(unordered_map<int, set<int>> &adjlist, vector<pair<int, int>> &edges)
{

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;
        int v = edges[i].second;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}

// we use set for ans in sorted manner
// T,C = O(V+E)
void bfs(unordered_map<int, set<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store frontNode to the ans
        ans.push_back(frontNode);

        // check for all the neighbours of frontNode

        for (auto it : adjlist[frontNode])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}



vector<int> ApplyBFSTraversal(int vertex, vector<pair<int, int>> edges)
{

    unordered_map<int, bool> visited;
    unordered_map<int, set<int>> adjlist;

    Creategraph(adjlist, edges);

    vector<int> ans;

    // check all the component of the graph

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjlist, visited, ans, i);
            // bfs(adjlist, visited, ans, 0)  for the graph wich is not disconnectec;
        }
    }

    return ans;
}

int main()
{

    vector<pair<int, int>> edges = {{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};

    int n = edges.size();

    vector<int> ans = ApplyBFSTraversal(n, edges);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}