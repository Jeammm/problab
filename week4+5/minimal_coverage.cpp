#include <iostream>
#include <vector>
#define MAX_N 100010

using namespace std;
pair<int, int> lines[MAX_N];
int ranks[MAX_N] = {0};
vector<int> coverage[MAX_N];

void get_input()
{
  int m;
  cin >> m;
  int s, t, i=0;
  cin >> s >> t;
  while (s != 0 && t != 0)
  {
    lines[i] = make_pair(s, t);
    coverage[i].push_back(i);
    int start, finish;

    if (s < 0)
    {
      start = 0;
    }
    if (t > m)
    {
      finish = m;
    }

    ranks[i] += finish - start;
    
    i++;
    cin >> s >> t;
  }
}

void get_lines()
{

}

int main()
{
  int n;
  cin >> n;
  cout << "\n";

  for (int i = 0; i < n; i++)
  {
    get_input();
    get_lines();
  }
}