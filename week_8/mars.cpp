#include <iostream>

using namespace std;
int visited[95][95][1010];
string word;
int word_size;

int min(int x, int y)
{
  if (x > y)
  {
    return y;
  }
  return x;
}

void init()
{
  for (int i = 0; i < 95; i++)
  {
    for (int j = 0; j < 95; j++)
    {
      for (int k = 0; k < word_size+1; k++)
      {
        visited[i][j][k] = -1;
      }
    }
  }
}

int rotate(char from, int to)
{
  int clw = from - word[to];
  int cclw = word[to] - from + 26;
  if (clw < 0)
  {
    clw += 26;
    cclw -= 26;
  }

  return min(clw, cclw);
}

int find_min(char left, char right, int index)
{
  if (index == word_size)
  {
    return 0;
  }

  if (visited[left][right][index] != -1)
  {
    // cout << "visited : " << visited[left][right][word.size()] << "\n";
    return visited[left][right][index];
  }

  int rotate_left = rotate(left, index) + find_min(word[index], right, index + 1);
  int rotate_right = rotate(right, index) + find_min(left, word[index], index + 1);

  if (rotate_left < rotate_right)
  {
    visited[word[index]][right][index] = rotate_left;
    return rotate_left;
  }
  else
  {
    visited[left][word[index]][index] = rotate_right;
    return rotate_right;
  }
}

int main()
{
  int n, i;
  cin >> n;
  for (i = 0; i<n; i++)
  {
    cin >> word;
    word_size = word.size();
    init();
    cout << find_min('A', 'A', 0) << "\n";
  } 
}