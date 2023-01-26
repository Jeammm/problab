#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int n, m, k, h;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
  for(int i = 0; i < n; i++)
    deg[i] = 0;
  
  for(int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v; u--; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool seen[MAX_N];
int layer[MAX_N];

void init()
{
  for(int u = 0; u < n; u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}

void bfs(int s)
{
  list<int> Q;

  Q.push_back(s);
  seen[s] = true;
  layer[s] = 0;
  
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for(int d=0; d<deg[u]; d++) {
      int v = adj[u][d];
      if(!seen[v]) {
        Q.push_back(v);
        seen[v] = true;
        layer[v] = layer[u] + 1;
      }
    }
  }
}

int main()
{
  cin >> n >> m >> h;
  read_input();
  

  int max_chill = 0;
  
  for(int u=0; u<n; u++) {
    init();
    bfs(u);
    int in_layer = 0;
    for(int k=0; k<n; k++) {
      if (layer[k] <= h) {
        in_layer++;
      }
    }
    if (in_layer > max_chill) {
        max_chill = in_layer;
    }
  }
  cout << max_chill;
}