#include <iostream>
#include <algorithm>

using namespace std;

string word;
int visited[95][95][1010];

void init()
{
  for (int i = 0; i < 95; i++)
  {
    for (int j = 0; j < 95; j++)
    {
      for (int k = 0; k < word.size()+1; k++)
      {
        visited[i][j][k] = -1;
      }
    }
  }
}

int lower_value(int x, int y)
{
  if (x > y)
  {
    return y;
  }
  return x;
}

int rotate(char from, char to)
{

  if (to > 'Z' || to < 'A')
  {
    return 0;
  }

  int clw = from - to;
  int cclw = to - from + 26;
  if (clw < 0)
  {
    clw += 26;
    cclw -= 26;
  }

  return lower_value(clw, cclw);
}

int turn(char left, char right, int index)
{

  if (index >= word.size())
  {
    return 0;
  }

  if (visited[left][right][index] != -1)
  {
    // cout << "visited : " << visited[left][right][word.size()] << "\n";
    return visited[left][right][index];
  }

  int left_left = rotate(left, word[index]) + rotate(word[index], word[index + 1]) + turn(word[index + 1], right, index + 2);
  int left_right = rotate(left, word[index]) + rotate(right, word[index + 1]) + turn(word[index], word[index + 1], index + 2);
  int right_left = rotate(right, word[index]) + rotate(left, word[index + 1]) + turn(word[index + 1], word[index], index + 2);
  int right_right = rotate(right, word[index]) + rotate(word[index], word[index + 1]) + turn(left, word[index + 1], index + 2);

  // cout << left_left << left_right << right_right << right_left << "\n";

  int solution = min({left_left, left_right, right_right, right_left});

  if (left_left == solution)
  {
    visited[left][right][index] = rotate(left, word[index]);
    visited[word[index]][right][index + 1] = rotate(word[index], word[index+1]);
  }
  else if (left_right == solution)
  {
    visited[left][right][index] = rotate(left, word[index]);
    visited[word[index]][right][index + 1] = rotate(right, word[index + 1]);
  }
  else if (right_right == solution)
  {
    visited[left][right][index] = rotate(right, word[index]);
    visited[left][word[index]][index + 1] = rotate(word[index], word[index + 1]);
  }
  else
  {
    visited[left][right][index] = rotate(right, word[index]);
    visited[left][word[index]][index + 1] = rotate(left, word[index + 1]);
  }

  return solution;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> word;
    init();
    cout << turn('A','A', 0);
  }
}