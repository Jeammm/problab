#include <iostream>
using namespace std;

int main() {
    int n, k, t;
    int track = 1;
    int count = 0;
    cin >> n >> k >> t;
    while (1) {
        track += k;
        count++;
        if (track > n) {
            track -= n;
        }
        if (track == 1) {
            break;
        } else if (track == t){
            count++;
            break;
        }
    }
    cout << count << "\n";
}