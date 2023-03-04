#include <iostream>
#include <array>

using namespace std;

array<int, 3> contracts[1000010];
int package[1001];

int main()
{
    int n, k, i, j;
    cin >> k >> n;
    int c, p, w;
    int min_price = -1;
    int price;
    int max_weight = 0;

    for (i = 0; i < k; i++)
    {
        array<int, 3> contract;
        cin >> c >> p >> w;
        contract = {c, p, w};
        contracts[i] = contract;
    }

    for (i = 0; i < n; i++)
    {
        cin >> c;
        package[i] = c;
        if (c > max_weight)
        {
            max_weight = c;
        }
    }

    for (i = 0; i < k; i++)
    {
        if (contracts[i][2] < max_weight)
        {
            continue;
        }

        int carrying = 0;
        int need = 1;
        for (j = 0; j < n; j++)
        {
            if (carrying + package[j] <= contracts[i][2])
            {
                carrying += package[j];
            } else {
                need++;
                carrying = package[j];
            }
        }
        price = contracts[i][0] + (need * contracts[i][1]);
        if (min_price > price || min_price == -1)
        {
            min_price = price;
        }
    }
    cout << min_price << "\n";
}