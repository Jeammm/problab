#include <iostream>

using namespace std;

int main () {
    int n, i, target, current_hand, round;
    int maxRound=0;
    int track[110000] = {0};
    int give[110000];
    cin >> n;
    for (i=1; i<=n; i++) {
        cin >> target;
        give[i] = target;
    }

    for (i=1; i<=n; i++) {
        if (track[i] == 1) {
            continue;
        }
        track[i] = 1;
        current_hand=give[i];
        round = 1;
        while (current_hand != i) {
            current_hand = give[current_hand];
            track[current_hand] = 1;
            round++;
        }
        if (round > maxRound) {
            maxRound = round;
        }
    }

    cout << maxRound << "\n";
}