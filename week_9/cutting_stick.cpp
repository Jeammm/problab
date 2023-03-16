#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 51;
const int MAX_L = 1010;
int l;
int n;
int cuts[MAX_N];
int seen[MAX_L][MAX_L][MAX_N][MAX_N];
bool visited[MAX_L][MAX_L][MAX_N][MAX_N];

void init()
{
  for (int i = 0; i < MAX_L; i++)
  {
    for (int j = 0; j < MAX_L; j++)
    {
      for (int k = 0; k < MAX_N; k++)
      {
        for (int x = 0; x < MAX_N; x++)
        {
          visited[i][j][k][x] = false;
        }
      }
    }

  }
}

int get_cuts(int wood_s, int wood_f, int left, int right)
{

  int cutting_remain = right - left;
  if (cutting_remain <= 0)
  {
    return 0;
  }

  if (visited[wood_s][wood_f][left][right])
  {
    return seen[wood_s][wood_f][left][right];
  }

  int wood_l = wood_f - wood_s;

  int min_cost = wood_l;
  for (int i = left; i < right; i++)
  {
    int cut = cuts[i];
    int cost = wood_l + get_cuts(wood_s, cut, left, i) + get_cuts(cut, wood_f, i + 1, right);
    if (cost < min_cost)
    {
      min_cost = cost;
    }
  }

  seen[wood_s][wood_f][left][right] = min_cost;
  visited[wood_s][wood_f][left][right] = true;

  return min_cost;
}

int main()
{
  cin >> l;

  while (l != 0)
  {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> cuts[i];
    }

    init();
    cout << "The minimum cutting is " << get_cuts(0, l, 0, n) << ".\n";
    cin >> l;
  } 
}