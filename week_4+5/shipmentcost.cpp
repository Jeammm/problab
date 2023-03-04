#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m, n, s, t;
vector<int> adj[MAX_N];
int min_cost[MAX_N];
int deg[MAX_N];

bool is_storage[MAX_N];
bool is_factory[MAX_N];
vector<int> storage;
vector<int> factory;

void read_input()
{
  cin >> n >> m >> s >> t;
  for (int i = 0; i < n; i++)
  {
    deg[i] = 0;
    min_cost[i] = -1;
  }

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }

  for (int i = 0; i < s; i++)
  {
    int inp;
    cin >> inp; inp--;
    is_storage[inp] = true;
    storage.push_back(inp);
  }

  for (int i = 0; i < t; i++)
  {
    int inp;
    cin >> inp; inp--;
    is_factory[inp] = true;
    factory.push_back(inp);
  }


}

bool seen[MAX_N];
int layer[MAX_N];

void init()
{
  for (int u = 0; u < n; u++)
  {
    seen[u] = false;
    layer[u] = -1;
    
  }
}

void bfs_f(int s, int it)
{
  list<int> Q;

  Q.push_back(s);
  seen[s] = true;
  layer[s] = 0;

  while (!Q.empty())
  {
    int u = Q.front();

    if (is_storage[u] == true)
    {
      min_cost[it] = layer[u];
      return;
    }

    Q.pop_front();
    for (int d = 0; d < deg[u]; d++)
    {
      int v = adj[u][d];
      if (!seen[v])
      {
        Q.push_back(v);
        seen[v] = true;
        layer[v] = layer[u] + 1;
      }
    }
  }
}


void bfs_s(int s)
{
  list<int> Q;

  Q.push_back(s);
  seen[s] = true;
  layer[s] = 0;

  while (!Q.empty())
  {
    int u = Q.front();

    Q.pop_front();
    for (int d = 0; d < deg[u]; d++)
    {
      int v = adj[u][d];
      if (!seen[v])
      {
        Q.push_back(v);
        seen[v] = true;
        layer[v] = layer[u] + 1;
      }
    }
  }
}

void print_min_cost()
{
  for (int i = 0; i < t; i++)
  {
    cout << min_cost[i] << "\n";
  }
  // cout << "\n";
}

int main()
{
  read_input();

  if (t < s)
  {
    for (int i = 0; i < t; i++)
    {
      init();
      bfs_f(factory[i], i);
    }
  }
  else
  {
    for (int i = 0; i < s; i++)
    {
      init();
      bfs_s(storage[i]);
      for (int j = 0; j < t; j++)
      {
        if (min_cost[j] == -1 || layer[factory[j]] < min_cost[j])
        {
          min_cost[j] = layer[factory[j]];
        }
      }
    }
    
  }
  print_min_cost();

  // init();
  // bfs(0);
  // for (int u = 0; u < n; u++)
  // {
  //   cout << "node : " << u + 1 << " layer : " << layer[u] << "\n";
  // }
}