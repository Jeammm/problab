#include <iostream>
#include <list>
#include <array>

using namespace std;

array<list<int>, 100001> station;

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        char cmd;
        int number, rail;
        cin >> cmd >> number >> rail;
        if (cmd == 'N') {
            station[rail].push_back(number);
        } else {
            station[rail].splice(station[rail].end(), station[number]);
            station[number].clear();
        }
    }
    for (int i=0; i<100001;i++) {
        for (auto ptr: station[i]) {
            cout << ptr << "\n";
        }
    }
}