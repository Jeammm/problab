#include <iostream>
#include <vector>
#include <queue>
#define MAX_W 2001
using namespace std;

const int MAX_N = 200010;
const int MAX_M = 200010;


vector<pair<int, int>> adj[MAX_N];
bool seen[MAX_N];
int value[MAX_N];
int deg[MAX_N];
int n, m;

void get_input()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int s, t, w;
    cin >> s >> t >> w; s--; t--;
    adj[s].push_back(make_pair(t, w));
    adj[t].push_back(make_pair(s, w));
    deg[s]++;
    deg[t]++;
    value[i] = MAX_W;
  }
}

void shortest_path()
{
  value[0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, 0));

  while (!pq.empty())
  {
    int current = pq.top().second;
    pq.pop();

    if (seen[current])
    {
      continue;
    }

    seen[current] = true;

    for (int i = 0; i < deg[current]; i++)
    {
      int target_node = adj[current][i].first;
 
      int cost = value[current] + adj[current][i].second;

      if (cost < value[target_node])
      {
        value[target_node] = cost;
        pq.push(make_pair(cost, target_node));
      }
    }
  }

  cout << value[n - 1];
}

int main()
{
  get_input();
  shortest_path();
  return 0;
}