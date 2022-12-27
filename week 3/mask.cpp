#include <iostream>
#include <vector>

using namespace std;
vector<int> player;
vector<int> power;

int main(void) {
    int n, count=1;
    cin >> n;
    
    for (int i=0; i<4; i++) {
        int max_power = 0;
        int best_player = 0;
        for (int j=0; j<n; j++) {
            int p;
            cin >> p;
            if (p > max_power) {
                max_power = p;
                best_player = count;
            }
            count++;
        }

        player.push_back(best_player);
        power.push_back(max_power);

    }
    // for (auto ptr: player) {
    //     cout << ptr << " ";
    // }
    // cout << "\n";

    // for (auto ptr: power) {
    //     cout << ptr << " ";
    // }
    // cout << "\n";


    int first, second, third, fourth;
    int max = 0;

    int max1;
    if (power[0] > power[1]) {
        max1 = 0;
    } else {
        max1 = 1;
    }

    int max2;
    if (power[2] > power[3]) {
        max2 = 2;
    } else {
        max2 = 3;
    }

    if (power[max1] > power[max2]) {
        cout << player[max1] << " " << player[max2] << " ";
    } else {
        cout << player[max2] << " " << player[max1] << " ";
    }

    if (max1 == 0) {
        cout << player[1] << " ";
    } else {
        cout << player[0] << " ";
    }

    if (max2 == 2) {
        cout << player[3] << "\n";
    } else {
        cout << player[2] << "\n";
    }

}