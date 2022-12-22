#include <iostream>
#include <vector>

using namespace std;

vector<int> price;
vector<int> performance;
vector<int> spot;

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p, v;
        cin >> p >> v;
        price.push_back(p);
        if (i != 0 && v > performance.back()) {
            spot.push_back(i);
        }
        performance.push_back(v);
    }
    
    int count = 0;
    while (spot.size() != 0) {
        int better_spot = spot.back();
        spot.pop_back();
        int better_price = price[better_spot];
        int better_performance = performance[better_spot];
        int cursor = better_spot-1;

        // cout << better_spot << better_performance << cursor << "\n";
        while (performance[cursor] < better_performance) {
            count++;
            if (cursor == 0) {
                break;
            }
            if (spot.size() != 0 && cursor == spot.back()) {
                spot.pop_back();
            }
            cursor--;
        }


    }
    cout << count << "\n";

}