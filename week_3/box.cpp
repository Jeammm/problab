#include <iostream>
#include <vector>
#define MAX_N 35

using namespace std;


int map[MAX_N][MAX_N] = {0};
bool seen[MAX_N][MAX_N] = {false};
bool possible = false;
int n, m;


int check_space(int x, int y) {
    if (y < 0 || y >= n-1 || x < 0 || x >= m-1) {
        return 0;
    }
    if (map[y][x] != 0 || map[y+1][x] != 0 || map[y][x+1] != 0 || map[y+1][x+1] != 0) {
        return 0;
    }

    return 1;
}

void move(int x, int y) {
    
    if (possible){
        return;
    }

    if (seen[y][x]){
        return;
    }

    if (check_space(x, y) == 0){
        return;
    }

    if (y == n-2){
        possible = true;
        return;
    }

    seen[y][x] = true;

    move(x, y+1);
    move(x+1, y);
    move(x-1, y);
    move(x, y-1);

    return;
}

int main(void) {
    cin >> n >> m;
    for (int i=0 ;i<n; i++) {
        string read;
        cin >> read;
        for (int j=0; j<m; j++) {
            map[i][j] = (read[j] == '#');
        }
    }
    
    for (int i=0; i<m-1; i++) {
        if (check_space(i, 0)) {
            move(i, 0);
            if (possible) {
                cout << "yes" << "\n";
                return 1;
            }
        }
    }
    cout << "no" << "\n";
    return 0;
    
}