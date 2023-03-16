#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_N = 201;

int table[MAX_N][MAX_N];

string s, t;
int ls, lt;


void lcs()
{
  for (int i = 1; i <= lt; i++)
  {
    for (int j = 1; j <= ls; j++)
    {
      int match = table[j - 1][i - 1];
      if (s[j - 1] == t[i - 1])
        match++;

      table[j][i] = max({table[j-1][i], table[j][i-1], match});
    }
  }
}

void print_table()
{
  for(int i = 0; i <= ls; i++)
  {
    for (int j = 0; j <= lt; j++)
    {
      cout << table[i][j] << " ";
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

  // print_table();
  cout << table[ls][lt];
}