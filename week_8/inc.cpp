#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1010];
int level[1010];
int n, last;
int max_level = 1;
vector<int> ans;


void get_input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    level[i] = 1;
  }
}

int main()
{
  get_input();
  for (int i = 1; i < n; i++)
  {

    int top_level = 0;
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j])
      {
        if (level[j] > top_level)
        {
          top_level = level[j];

        }
      }
    }

    level[i] += top_level;

    if (level[i] > max_level)
    {
      max_level = level[i];
      last = i;
    }
  }

  int current = max_level;

  cout << max_level << "\n";
  ans.push_back(arr[last]);
  int arr_last = arr[last];
  current--;

  for (int i = last-1; i >= 0; i--)
  {
    if (level[i] == current)
    {
      if (arr[i] < arr_last)
      {
        ans.push_back(arr[i]);
        current--;
        arr_last = arr[i];
      }
    }
  }

  reverse(ans.begin(), ans.end());

  for (auto ptr: ans)
  {
    cout << ptr << " ";
  }
}