#include <iostream>
#include <list>

using namespace std;
list<char> path;

int rotate(char from, char to) {
    if (from == 'N') {
        switch (to) {
            case 'N': return 0;
            case 'E': return 1;
            case 'S': return 2;
            case 'W': return 3;
        }
    } else if (from == 'E') {
        switch (to) {
            case 'N': return 3;
            case 'E': return 0;
            case 'S': return 1;
            case 'W': return 2;
        }
    }  else if (from == 'S') {
        switch (to) {
            case 'N': return 2;
            case 'E': return 3;
            case 'S': return 0;
            case 'W': return 1;
        }
    } else {
        switch (to) {
            case 'N': return 1;
            case 'E': return 2;
            case 'S': return 3;
            case 'W': return 0;
        }
    }
}

int main(void) {
    char direction = 'N';
    string program;
    cin >> program;

    for (int i=0; i<program.size(); i++) {
        if (program[i] == 'Z') {
            path.push_back('Z');
            direction = 'N';
        } else {
            int rotate_n = rotate(direction, program[i]);
            direction = program[i];
            for (int j=0; j<rotate_n; j++) {
                path.push_back('R');
            }
            path.push_back('F');
        }
    }
    for (auto ptr: path) {
        cout << ptr;
    }
    cout << "\n";
}