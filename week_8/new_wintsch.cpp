#include <iostream>
#include <vector>
#define MAX_WORKS 1010

using namespace std;

int weight[MAX_WORKS];
pair<int, int> interval[MAX_WORKS];
vector<vector<int>> work_set;

int n;

void get_input()
{
  cin >> n;
  int s, t, w;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> t >> w;
    weight[i] = w;
    interval[i] = make_pair(s, t);
  }
}

int get_works(int n)
{
  
}

int main()
{
  get_input();
  cout << get_works(n - 1) << "\n";
}