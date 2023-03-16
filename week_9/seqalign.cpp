#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
const int MAX_N = 301;

int table[MAX_N][MAX_N];
int back_track[MAX_N][MAX_N];
int ans;
string s, t;
int ls, lt;

void lcs()
{
  for (int i = 1; i <= lt; i++)
  {
    for (int j = 1; j <= ls; j++)
    {
      int tl = table[j - 1][i - 1];
      int match = -1;
      if (s[j - 1] == t[i - 1])
        match = 1 + tl;

      table[j][i] = max({table[j - 1][i], table[j][i - 1], match});
      if (table[j][i] == match)
      {
        back_track[j][i] = 3;
      }
      else if (table[j][i - 1] == table[j - 1][i])
      {
        if (table[j][i - 1] == tl)
        {
          back_track[j][i] = 4;
        }
        else
        {
          if (back_track[j][i - 1] == 3)
          {
            back_track[j][i] = 2;
          }
          else
          {
            back_track[j][i] = 1;
          }
        }
      }
      else if (table[j][i] == table[j][i - 1])
      {
        back_track[j][i] = 2;
      }
      else
      {
        back_track[j][i] = 1;
      }
    }
  }
}

void print_table(int y, int x)
{
  int temp = ans;
  int count = 0;

  while (temp != 0)
  {
    if (back_track[y][x] == 3)
    {
      y--;
      x--;
      temp--;
    }
    else if (back_track[y][x] == 2)
    {
      x--;
      count++;
    }
    else if (back_track[y][x] == 1)
    {
      y--;
      count++;
    }
    else 
    {
      y--;
      x--;
      count++;
    }
  }
  if (x > y)
  {
    count += x;
  }
  else
  {
    count += y;
  }
  cout << count;
}

void print_back()
{
  for (int i = 0; i <= ls; i++)
  {
    for (int j = 0; j <= lt; j++)
    {
      cout << table[i][j] << " ";
    }
    cout << "\n";
  }
}

void print_track()
{
  for (int i = 0; i <= ls; i++)
  {
    for (int j = 0; j <= lt; j++)
    {
      cout << back_track[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  cin >> s;
  cin >> t;
  ls = s.length();
  lt = t.length();

  lcs();

  ans = table[ls][lt];
  // cout << ans << "\n";
  // print_track();

  // cout << "\n";
  // print_back();

  print_table(ls, lt);
}