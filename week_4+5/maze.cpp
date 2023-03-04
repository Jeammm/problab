#include <iostream>
#include <vector>
#define MAX_N 50

using namespace std;

int n, q, x, y, a, b;
int w, d;
string board[MAX_N];
bool seen[MAX_N][MAX_N];
bool possible = false;

void travel(int x, int y, int key)
{
    if (x > w || y > d || x < 1 || y < 1)
    {
        return;
    }

    if (board[y-1][x-1] == '#' || seen[y-1][x-1])
    {
        return;
    }

    if ((x == a && y == b) || possible) {
        possible = true;
        return;
    }

    if (board[y-1][x-1] == 'O') {
        if (key == 0)
        {
            return;
        } 
        key = 0;
    }
    // cout << "x:" << x << " y:" << y << "\n";

    seen[y-1][x-1] = true;

    travel(x+1, y, key);
    travel(x-1, y, key);
    travel(x, y+1, key);
    travel(x, y-1, key);
}

int main()
{
    int i, j;
    cin >> n >> q;

    for (i=0; i<n; i++)
    {
        string row;
        cin >> row;
        board[i] = row;
    }
    w = board[0].size();
    d = n;

    for (i=0; i<q; i++)
    {
        cin >> y >> x >> b >> a;
        possible = false;
        
        for (j=0; j<n; j++)
        {
            for (int l=0; l<w; l++)
            {
                seen[j][l] = false;
            }
        }

        travel(x, y, 1);
        if (possible)
        {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}