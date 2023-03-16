#include <iostream>
#include <algorithm>
#define MAX_N 100010

using namespace std;

int n;
int tuek[MAX_N][2];
int visited[MAX_N][3];

void get_input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    tuek[i][0] = u;
    tuek[i][1] = v;

    for (int j = 0; j < 3; j++)
    {
      visited[i][j] = -1;
    }
  }
}

int get_max_profit(int index, int brand)
{
  if (index < 0)
  {
    return 0;
  }

  if (visited[index][brand] != -1)
  {
    return visited[index][brand];
  }

  int profit_left = tuek[index][0] + get_max_profit(index - 1, 1);
  int profit_nope = get_max_profit(index - 1, 0);
  int profit_right = tuek[index][1] + get_max_profit(index - 1, 2);

  if (brand == 1)
  {
    profit_left = -1;
  }
  else if (brand == 2)
  {
    profit_right = -1;
  }

  int result = max({profit_left, profit_right, profit_nope});

  visited[index][brand] = result;

  return result;
}

int main()
{
  get_input();
  cout << get_max_profit(n - 1, 0);
}