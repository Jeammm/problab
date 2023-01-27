#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 3010;

int m,n;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool possible = true;

void read_input()
{
  cin >> n >> m;
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
  possible = true;
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
      } else if (layer[v] == layer[u]){
        cout << u+1 << " " << v+1 << "\n";
        return; 
      }
    }
  }
}



int main()
{
  read_input();
  init();
  bfs(0);
}