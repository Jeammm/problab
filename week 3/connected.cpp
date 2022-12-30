#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

void dfs(vector<vector<int>> &graph, int i, vector<bool> &visited)
{
    visited[i] = true;

    for (auto ptr: graph[i])
    {
        if (!visited[ptr]) {
            dfs(graph, ptr, visited);
        }
    }
}

int main(void) 
{
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        vector<int> node = {};
        graph.push_back(node);
    }

    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n, false);

    int count = 0;
    for (int i=0; i<n; i++) 
    {
        if (!visited[i])
        {
            count++;
            dfs(graph, i, visited);
        }
    }
    cout << count << "\n";
}