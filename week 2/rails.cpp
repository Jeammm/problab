#include <iostream>
#include <list>

using namespace std;

int main(void) {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        while (1) {
            list<int> line;
            int number;
            int next = n;

            for (int i=0; i<n; i++ ) {
                cin >> number;
                if (number == 0) {
                    break;
                } else {
                    line.push_back(number);
                }
            }

            if (number == 0) {
                cout << "\n";
                break;
            }

            list<int> station;

            for (int i=0; i<n; i++) {
                station.push_back(line.back());
                line.pop_back();
                while (next != 0 && station.back() == next) {
                    station.pop_back();
                    next--;
                }
            }

            if (next == 0) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }

        }
    }

}
