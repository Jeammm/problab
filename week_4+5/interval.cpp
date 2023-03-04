#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> schedul; 

int main()
{
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        int start, finish;
        cin >> start >> finish;
        pair<int, int> interval(finish, start);
        schedul.push_back(interval);
    }

    sort(schedul.begin(), schedul.end());

    int count = 0;
    int time = 0;

    for (auto ptr: schedul)
    {
        if (ptr.second >= time)
        {
            time = ptr.first;
            count++;
        }
    }
    cout << count << "\n";
}