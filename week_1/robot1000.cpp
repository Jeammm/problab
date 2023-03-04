#include <iostream>
#include <string.h>

using namespace std;

int main () {
    char cmd[101];
    cin >> cmd;
    int x=0, y=0;
    for (int i=0; i<strlen(cmd); i++) {
        switch (cmd[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
            case 'Z': x=0; y=0; break;
        }
    }
    cout << x << " " << y << "\n";
}