#include <iostream>
#include <array>

using namespace std;
array<int, 301> road;

int main(void) {
    int l, n;
    cin >> l >> n;
    for (int i=0; i<n; i++) {
        int start, stop;
        cin >> start >> stop;
        for (int j=start; j<stop; j++) {
            road[j]++;
        }
    }
    int max=0;
    for (auto ptr: road) {
        if (ptr > max) {
            max = ptr;
        }
    }
    cout << max << "\n";
}