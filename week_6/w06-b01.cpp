#include <iostream>
#define MAX_N 100010

using namespace std;

int parent[MAX_N];
int psize[MAX_N];
int edge[MAX_N][2];
int n, q;

void init()
{
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
    psize[i] = 1;
  }
}

int find_parent(int node)
{
  if (parent[node] == node)
  {
    return node;
  }
  else
  {
    return parent[node] = find_parent(parent[node]);
  }
}

void union_t(int u, int v)
{
  v = find_parent(v);
  u = find_parent(u);
  if (psize[u] > psize[v])
  {
    int tmp = u;
    u = v;
    v = tmp;
  }
  parent[u] = v;
  psize[v] += psize[u];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  init();

  int i;
  char c;
  int u, v;
  
  for (i = 0; i < q; i++)
  {
    cin >> c >> u >> v;
    
    if (c == 'q')
    {
      if (find_parent(u) == find_parent(v))
      {
        cout << "yes" << '\n';
      }
      else
      {
        cout << "no" << '\n';
      }
    }
    else
    {
      if (find_parent(u) != find_parent(v))
      {
        union_t(u, v);
      }
    }
  }


  return 0;
}