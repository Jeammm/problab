#include <iostream>
#include <vector>
#define MAX_N 21

using namespace std;

vector<int> board[MAX_N];
vector<bool> seen[MAX_N];
bool possible = false;
int n, k;

void jump(int x, int y)
{
    if (x == n-1 && y == n-1)
    {
        possible = true;
        return;
    }

    if (seen[x][y] || possible)
    {
        return;
    }

    seen[x][y] = true;

    if (x+1 < n && (board[x+1][y] - board[x][y] <= k))
    {
        jump(x+1, y);
    }
    if (x-1 >= 0 && (board[x-1][y] - board[x][y] <= k))
    {
        jump(x-1, y);
    }
    if (y+1 < n && (board[x][y+1] - board[x][y] <= k))
    {
        jump(x, y+1);
    }
    if (y-1 >= 0 && (board[x][y-1] - board[x][y] <= k))
    {
        jump(x, y-1);
    }
}

int main()
{
    int i, j, e;
    cin >> n >> k;


    for (i=0; i<n; i++)
    {
        vector<int> row;
        vector<bool> srow;
        for (j=0; j<n; j++)
        {
            cin >> e;
            row.push_back(e);
            srow.push_back(false);
        }
        board[i] = row;
        seen[i] = srow;
    }

    jump(0, 0);
    if (possible)
    {
        cout << "yes\n";
    } else 
    {
        cout << "no\n";
    }
}