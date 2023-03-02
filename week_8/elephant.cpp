#include <iostream>
#include <algorithm>

using namespace std;

int path[100010];
int score[100010];
int top_score;
int n;

void jump()
{
  for (int i = 2; i < n; i++)
  {
    int max_score = 0;
    for (int j = i - 3; (j >= i-6 && j >= 2); j--)
    {
      if (score[j] > max_score)
      {
        max_score = score[j];
      }
    }
    score[i] = max_score + path[i];
    if (score[i] > top_score)
    {
      top_score = score[i];
    }
  }
}

int main()
{
  int i;
  cin >> n;
  for (i = 0; i < n; i++)
  {
    cin >> path[i];
  }

  jump();
  cout << top_score;
}