#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;

int check_space(vector<vector<int>> &map, int x, int y, int m, int n) {
    if (y < 0 || y >= n-1 || x < 0 || x >= m-1) {
        return 0;
    }
    if (map[y][x] == 0 ) {
        if (map[y+1][x] != 1 && map[y][x+1] != 1 && map[y+1][x+1] != 1) {
            return 1; 
        }
    }
    return 0;
}

int move(vector<vector<int>> &map, int x, int y, int &m, int &n, int &possible) {
    if (y == n-2 || possible == 1) {
        possible = 1;
        return 1;
    }
    map[y][x] = 2;

    if (!possible && check_space(map, x, y+1, m, n)) {
        move(map, x, y+1, m, n, possible);
    }
    if (!possible && check_space(map, x+1, y, m, n)) {
        move(map, x+1, y, m, n, possible);
    }
    if (!possible && check_space(map, x-1, y, m, n)) {
        move(map, x-1, y, m, n, possible);
    }
    if (!possible && check_space(map, x, y-1, m, n)) {
        move(map, x, y-1, m, n, possible);
    }

    return 0;
}

int main(void) {
    int m, n;
    cin >> n >> m;
    for (int i=0 ;i<n; i++) {
        vector<int> row;
        string read;
        cin >> read;
        for (int j=0; j<m; j++) {
            row.push_back(read[j] == '#');
        }
        map.push_back(row);
    }
    
    int possible = 0;
    for (int i=0; i<m-1; i++) {
        if (check_space(map, i, 0, m, n)) {
            move(map, i, 0, m, n, possible);
            if (possible) {
                cout << "yes" << "\n";
                return 1;
            }
        }
    }
    cout << "no" << "\n";
    return 0;
    
}