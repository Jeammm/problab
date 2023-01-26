#include <iostream>
#include <vector>
#define MAX_N 200001

using namespace std;

int rot[MAX_N] = {0};

int main()
{
    int n, i, o;
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> o;
        
        int diff = o-i-1;
        if (diff < 0)
        {
            diff += n;
        }

        rot[diff]++;

    }

    int max_right = 0;
    for (i=0; i<n; i++)
    {
        if (rot[i] > max_right)
        {
            max_right = rot[i];
        }
    }
    cout << max_right << "\n";
}