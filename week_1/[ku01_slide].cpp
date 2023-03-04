#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int n, order, count=0;
    cin >> n;
    int *arr = (int *)malloc(sizeof(arr)*35);
    for (int i=0; i<n; i++) {
        cin >> order;
        arr[i] = order;
        for (int l=0; l<i; l++) {
            if (order > arr[l]) {
                count++;
            }
        }
    }
    cout << count << "\n";
}