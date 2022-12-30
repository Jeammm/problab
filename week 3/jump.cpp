#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <cmath>

using namespace std;

vector<array<int, 2>> points;
vector<vector<int>> adj;

float get_distance(int x, int y, int to_x, int to_y) {
    int f = pow(to_x - x, 2);
    int b = pow(to_y - y, 2);
    
    
    return pow(f+b, 0.5);
}

int bfsLayers(vector<vector<int>> &adj, int start_node) {
  queue<int> q;
  vector<bool> visited(adj.size(), false);

  q.push(start_node);
  visited[start_node] = true;

  int layers = 0;

  while (!q.empty()) {
    layers++;
    int level_size = q.size();
    for (int i=0; i<level_size; i++) {
      int node = q.front();
      q.pop();

      for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
          q.push(neighbor);
          visited[neighbor] = true;
        }
      }
    }
  }

//   for (auto ptr: visited) {
//     cout << ptr << " ";
//   }
//   cout << "\n";
  if (!visited[adj.size()-1]){
    return 1;
  }
  return layers;
}

int main(void) {
    array<int, 2> start = {0, 0};
    points.push_back(start);

    int n, r;
    cin >> n >> r;
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        array<int, 2> point = {x, y};
        points.push_back(point);
    }

    array<int, 2> end = {100, 100};
    points.push_back(end);

    
    for (int i=0; i<n+2; i++) {
        vector<int> next;
        for (int j=0; j<n+2; j++) {
            if (i != j) {
                float distance = get_distance(points[i][0], points[i][1], points[j][0], points[j][1]);
                if (distance <= r) {
                    next.push_back(j);
                }
            }
        }
        adj.push_back(next);
    }

    int n_layer = bfsLayers(adj, 0);

    if (n_layer <= 1) {
        cout << -1 << "\n";
    } else {
        cout << n_layer-1 << "\n";
    }
}