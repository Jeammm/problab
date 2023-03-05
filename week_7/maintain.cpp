#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200010;

int parent[MAX_N];
int weight[MAX_N];
int edge[MAX_N][2];
int psize[MAX_N];
pair<int, int> sorted_edge[MAX_N];
int n, m;


int find(int u)
{
  if (parent[u] == u)
  {
    return u;
  }
  return parent[u] = find(parent[u]);
}

void union_t(int u, int v)
{
  v = find(v);
  u = find(u);
  if (psize[u] > psize[v])
  {
    int tmp = u;
    u = v;
    v = tmp;
  }
  parent[u] = v;
  psize[v] += psize[u];
}

int result = 0;

void get_result()
{
  sort(sorted_edge, sorted_edge + m);
  for (int i = 0; i < m; i++)
  {
    int e = sorted_edge[i].second;
    int u = edge[e][0];
    int v = edge[e][1];

    if (find(u) != find(v))
    {
      union_t(u, v);
      result += sorted_edge[i].first;
    }
  }
  cout << result << "\n";
}

void read_input()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
    psize[i] = 1;
  }
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    edge[i][0] = a;
    edge[i][1] = b;
    sorted_edge[i].first = w;
    sorted_edge[i].second = i;
    get_result();
  }
}

int main()
{
  read_input();
}