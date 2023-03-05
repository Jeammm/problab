#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m, n, s, t;
vector<int> adj[MAX_N];
vector<pair<int, int>> red_path;
vector<pair<int, int>> black_path;
int deg[MAX_N];
int red_count = 0;
int black_count = 0;

void add_edge(int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
  deg[u]++;
  deg[v]++;
}

void remove_edge(int u, int v)
{
  adj[u].pop_back();
  adj[v].pop_back();
  deg[u]--;
  deg[v]--;
}

void read_input()
{
  cin >> n >> m >> s >> t; s--; t--;
  for (int i = 0; i < n; i++)
  {
    deg[i] = 0;
  }

  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;

    if (c == 0)
    {
      add_edge(u, v);
    }
    else if (c == 1)
    {
      red_path.push_back(make_pair(u, v));
      red_count++;
    }
    else
    {
      black_path.push_back(make_pair(u, v));
      black_count++;
    }
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

int bfs()
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
  return layer[t];
}

void print_layer()
{
  for (int i = 0; i < n; i++)
  {
    cout << layer[i] << " ";
  }
  cout << "\n";
}


int main()
{
  read_input();

  int min_path = -1;
  int path;

  init();  // no bridge
  path = bfs();
  // print_layer();
  if (path != -1)
  {
    min_path = path;
  }

  init(); // add red
  for (int i = 0; i < red_count; i++)
  {
    add_edge(red_path[i].first, red_path[i].second);
  }
  path = bfs();
  // print_layer();
  if (path != -1)
  {
    if (min_path == -1 || path < min_path)
    {
      min_path = path;
    }
  }
  for (int i = 0; i < red_count; i++) // remove red
  {
    remove_edge(red_path[i].first, red_path[i].second);
  }
  
  init();
  for (int i = 0; i < black_count; i++) // add black
  {
    add_edge(black_path[i].first, black_path[i].second);
  }
  path = bfs();
  // print_layer();
  if (path != -1)
  {
    if (min_path == -1 || path < min_path)
    {
      min_path = path;
    }
  }

  cout << min_path;
}