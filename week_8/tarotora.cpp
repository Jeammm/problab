#include <iostream>

using namespace std;

int n, k;
int path[100010][2];
int visited[250][100010];

void get_input()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> path[i][0] >> path[i][1];
  }
}

int min(int x, int y)
{
  if (x < y)
  {
    return x;
  }
  return y;
}

int get_diff(int x, int y)
{
  int diff = x - y;
  if (diff < 0)
  {
    diff *= -1;
  }
  return diff;
}

void init()
{
  for (int i = 0; i < 250; i++)
  {
    for (int j = 0; j < 100010; j++)
    {
      visited[i][j] = -1;
    }
  }
}

int get_energy(int taro, int tora, int index)
{

  if (index == n)
  {
    return 0;
  }

  if (visited[taro-tora + 120][index] != -1)
  {
    return visited[taro-tora + 120][index];
  }

  if (get_diff(taro, tora) >= k && taro > tora) // taro > tora at max diff
  {
    return path[index][1] + get_energy(taro, tora + 1, index + 1);
  }
  else if (get_diff(taro, tora) >= k && tora > taro) // tora > taro at max diff
  {
    return path[index][0] + get_energy(taro + 1, tora, index + 1);
  }
  else
  {
    int taro_fight = path[index][0] + get_energy(taro + 1, tora, index + 1);
    int tora_fight = path[index][1] + get_energy(taro, tora + 1, index + 1);

    if (taro_fight > tora_fight)
    {
      visited[taro - tora + 120][index] = tora_fight;
      return tora_fight;
    }
    else
    {
      visited[taro - tora + 120][index] = taro_fight;
      return taro_fight;
    }
  }
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    get_input();
    init();
    cout << get_energy(0, 0, 0) << "\n";
  }
}