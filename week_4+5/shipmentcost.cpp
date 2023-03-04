#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m, n, s, t;
vector<int> adj[MAX_N];
int deg[MAX_N];
int count = 0;
bool storage[MAX_N];
vector<int> factory;

void read_input()
{
  cin >> n >> m >> s >> t;
  for (int i = 0; i < n; i++)
    deg[i] = 0;

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
    storage[inp] = true;
  }

  for (int i = 0; i < t; i++)
  {
    int inp;
    cin >> inp; inp--;
    factory.push_back(inp);
    count++;
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

int bfs(int s)
{
  list<int> Q;

  Q.push_back(s);
  seen[s] = true;
  layer[s] = 0;

  while (!Q.empty())
  {
    int u = Q.front();

    if (storage[u] == true)
    {
      return layer[u];
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

int main()
{
  read_input();
  for (int i = 0; i < count; i++)
  {
    init();
    cout << bfs(factory[i]) << "\n";
  }

  // init();
  // bfs(0);
  // for (int u = 0; u < n; u++)
  // {
  //   cout << "node : " << u + 1 << " layer : " << layer[u] << "\n";
  // }
}