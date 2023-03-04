#include <iostream>
// #include <vector>
#define MAX_WORKS 1010

using namespace std;

int weight[MAX_WORKS];
pair<int, int> interval[MAX_WORKS];
// vector<vector<int>> work_set;
int value[MAX_WORKS];
int parent[MAX_WORKS];
int max_value_work = 0;
int max_value = 0;

int n;

void get_input()
{
  cin >> n;
  int s, t, w;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> t >> w;
    weight[i] = w;
    value[i] = w;
    interval[i] = make_pair(s, t);
    parent[i] = i;
  }
}

void get_value()
{
  int i;
  for (i = 1; i < n; i++)
  {
    int max_value_before = 0;
    int top_value_work_before = i;
    for (int j = 0; j < i; j++) //find max value that compatible
    {
      if (interval[j].second <= interval[i].first && value[j] > max_value_before)
      {
        max_value_before = value[j];
        top_value_work_before = j;
      }
    }
    value[i] += max_value_before; //set level for work i
    parent[i] = top_value_work_before;  //set parent for work i
    
    if (value[i] > max_value)
    {
      max_value = value[i];
      max_value_work = i;
    }
  }
}

void print_work_set()
{

  int current = max_value_work;

  cout << value[max_value_work] << "\n";

  int count = 1;

  while (parent[current] != current)
  {
    current = parent[current];
    count++;
  }


  cout << count << "\n";

  current = max_value_work;
  while (parent[current] != current)
  {
    cout << current+1 << " ";
    current = parent[current];
  }
  cout << current+1;

}

int main()
{
  get_input();
  get_value();
  print_work_set();
}