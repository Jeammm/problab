#include <iostream>
#include <vector>
#include <array>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX_N 1001

using namespace std;

int n, m, ex_count = 0;
vector<pair<int, int>> adj[MAX_N];
vector<array<int, 3>> express_way;

int shortestPath(int src)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int dist[MAX_N];
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
  }

  bool seen[MAX_N];

  pq.push(make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty())
  {
    int u = pq.top().second;
    seen[u] = true;
    pq.pop();
    for (auto x : adj[u])
    {
      int v = x.first;
      int weight = x.second;

      if (dist[v] > dist[u] + weight)
      {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  if (seen[n-1])
  {
    return dist[n-1];
  }
  else
  {
    return -1;
  }
}

void get_input()
{
  cin >> n >> m;
  int u, v, w, s;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w >> s; u--; v--;
    if (s == 0)
    {
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
    else
    {
      express_way.push_back({u, v, w});
      ex_count++;
    }
  }
}

int main()
{
  get_input();
  int min_path = -1;

  int short_path = shortestPath(0);
  if (min_path == -1 || short_path < min_path)
  {
    min_path = short_path;
  }

  for (int i = 0; i < ex_count; i++)
  {
    array<int, 3> ex = express_way.back();
    express_way.pop_back();
    int u = ex[0];
    int v = ex[1];
    int w = ex[2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));

    int short_path = shortestPath(0);
    if (min_path == -1 || short_path < min_path)
    {
      min_path = short_path;
    }
    

    adj[u].pop_back();
    adj[v].pop_back();
  }

  cout << min_path;

  return 0;
}