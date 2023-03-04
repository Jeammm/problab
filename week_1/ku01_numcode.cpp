#include <iostream>

using namespace std;

int main () {
    int n, t, i, num;
    int arr[51];
    cin >> n >> t;
    for (i=0; i<n; i++) {
        cin >> num;
        arr[i] = num;
    }

    if (t == 2){
        int track = n;
        for (i=1; i<n; i++) {
            if (arr[i] - arr[i-1] > track) {
                arr[i] -= 2*arr[i-1];
                track++;
            } else {
                arr[i] -= arr[i-1];
                track--;
            }
        }
        
    }
    

    for (i=0; i<n; i++) {
        if (i==0) {
            if (arr[0] < n) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else {
            if (arr[i-1] > arr[i]) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        }
    }
}