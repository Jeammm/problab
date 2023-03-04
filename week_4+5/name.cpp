#include <iostream>

using namespace std;

string t, name;

int main()
{
    int i, l, track=0;
    int count = 0;
    cin >> name;
    cin >> t;
    for (i = 0; i < t.size(); i++)
    {
        if (t[i] == name[track])
        {
            track++;
            if (track == name.size())
            {
                count++;
                track = 0;
            }
        }
    }
    cout << count << "\n";
}