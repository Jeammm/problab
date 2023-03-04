#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

const int MAX_N = 100010;

int n, m, k, h;
vector<int> adj[MAX_N];
vector<int> placed;
int deg[MAX_N];
int c_type[MAX_N];

void read_input()
{

  int num;
  for (int j = 0; j < k; j++)
  {
    cin >> num; num--;
    placed.push_back(num);
  }

  for (auto ptr: placed)
  {
    cin >> num;
    c_type[ptr] = num;
  }

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
  cin >> n >> m >> k >> h;
  read_input();
  
  set<int> chill;

  for (auto ptr: placed)
  {
    init();
    bfs(ptr);
    int safe_time = h + h*c_type[ptr]; //check first if it is hospital
    
    for(int k=0; k<n; k++) {
      if (layer[k] <= safe_time) {
        // cout << "k : " << k << "\n";
        chill.insert(k);
      }
    }

  }

  cout << chill.size();
}