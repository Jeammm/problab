#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> jobs;


int main()
{
    int n, i;
    cin >> n;
    for (i=0; i<n; i++)
    {
        int d, t;
        cin >> d >> t;
        pair<int, int> job = {d, t};
        jobs.push_back(job);
    }


    sort(jobs.begin(), jobs.end());


    int time = 0;
    int max_fee = 0;
    for (i=0; i<n; i++)
    {
        time += jobs[i].second;
        if (time - jobs[i].first > 10)
        {
            int fee = (time - jobs[i].first - 10)*1000;
            if (fee > max_fee)
            {
                max_fee = fee;
            }
        }        
        
    }
    cout << max_fee << "\n";
}