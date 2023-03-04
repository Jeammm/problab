#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main () {
    int i, j;
    double n, k, time, fastestTime=1100000000;
    double clock, round;
    cin >> n >> k;
    double *lapTime = (double *)malloc(sizeof(lapTime) * n);
    double *knockedRec = (double *)malloc(sizeof(knockedRec) * n);
    for (i=0; i<n; i++) {
        cin >> time;
        lapTime[i] = time;
        if (time < fastestTime) {
            fastestTime = time;
        }
    }

    for (i=0; i<n; i++) {
      knockedRec[i] = 0;
      for (j=1; j<=k; j++) {
          clock = fastestTime*j;
          round = clock/lapTime[i];
          if (round < j-1 || (round == j-1 && fmod(clock,lapTime[i]) == 0)) {
              knockedRec[i] = 1;
              break;
          }
      }
    }

    int left = n;

    for (i=0; i<n; i++) {
        left -= knockedRec[i];
    }

    cout << left << "\n";


}