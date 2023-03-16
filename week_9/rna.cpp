#include <iostream>
#include <algorithm>
#define MAX_N 210

using namespace std;
int table[MAX_N][MAX_N];

string rna;
int n;
int max_length = 0;


void get_pair()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      int match = 0;
      if 
      (
        (i - j > 4) && (
          (rna[i - 1] == 'G' && rna[j - 1] == 'C') 
          || (rna[i - 1] == 'C' && rna[j - 1] == 'G')
          || (rna[i - 1] == 'A' && rna[j - 1] == 'U')
          || (rna[i - 1] == 'U' && rna[j - 1] == 'A')
        )
      )
      {
        match++;
      }

      int before = table[j - 1][1];
      table[i][j] = max({ table[i - 1][j], table[i - 1][j + 1] + match });
      
      if (table[i][j] > max_length)
      {
        max_length = table[i][j];
      }
    }
  }
}

void print_table()
{
  for (int i = 1; i <= n; i++)
  { 
    for (int j = 1; j <= n; j++)
    {
      cout << table[i][j] << ", ";
    }
    cout << "\n";
  }
}

int main()
{
  cin >> rna;
  n = rna.size();
  get_pair();
  cout << max_length << "\n";
  print_table();
}