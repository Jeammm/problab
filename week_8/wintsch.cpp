#include <iostream>
#include <vector>
#define MAX_WORKS 1010

using namespace std;

int weight[MAX_WORKS];
pair<int, int> interval[MAX_WORKS];
vector<int> work_set;

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

int get_works(int work_number)
{

  if (work_number == 0)
  {
    return weight[0];
  }
  if (work_number < 0)
  {
    return 0;
  }

  // cout << work_number << " ";

  int possible = work_number - 1;


  int value_if_not_choose = 0;
  int max_value_if_not_choose = 0;

  while (interval[possible].second > interval[work_number].first && possible >= 0)
  {
    value_if_not_choose = get_works(possible);
    if (value_if_not_choose > max_value_if_not_choose)
    {
      max_value_if_not_choose = value_if_not_choose;
    }
    
    possible--;
  }

  int value_if_choose = weight[work_number] + get_works(possible);

  if (max_value_if_not_choose > value_if_choose)
  {
    return max_value_if_not_choose;
  }
  else
  {
    work_set.push_back(work_number + 1);
    return value_if_choose;
  }
  
}

int main()
{
  get_input();
  cout << get_works(n - 1) << "\n";
  cout << work_set.size() << "\n";
  for (auto ptr:work_set)
  {
    cout << ptr << " ";
  }
}